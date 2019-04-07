#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>
#include<unordered_map>
using namespace std;

//315 计算右侧小于当前元素的个数

/*
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
示例:
输入: [5,2,6,1]
输出: [2,1,1,0]
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.
*/

//这道题归到复杂肯定不能用暴力搜索
/*
方法有很多很多，这里选取归并思想、树状数组和二叉搜索树三种方法来解
复杂度都是o(nlogn)
*/
//方法一：归并方法：
/*
构造元素值和下标的键值对数组nums，元素值用于比较，下标方便计算元素个数
数组ans用来记录逆序对数，作为最终的输出
归并思想，先把数组二分分割直到每个子数组只有一个元素，然后子数组两两归并排序，边排序边更新逆序个数
要注意的是，最终输出的是一个数组，而不是像剑指offer51题一样只需要总数即可，所以这里一定要构造元素和下标的数对
因为在归并过程中元素的位置会发生变化，只有维护好这个数对，才能保证最终把数加到合适的位置
否则元素的位置在变，但下标没变，那么在加的时候就会加到错误的位置

不要问我怎么知道的...试出来的

记录的方法为：两个指针i和j分别指向前一半和后一半的尾(前一半和后一半各自有序)开始遍历
当发现nums[i].first>nums[j].first的时候，说明此时从后一半开始到下标j处的元素都与nums[i].first构成逆序，将这个数加给ans[nums[i].second]
再将值放入辅助数组copy中，如果nums[i].first<nums[j].first，则说明没有逆序，直接放到copy中即可

辅助数组copy用来保存对nums部分排序的结果
*/
void mergeSort(vector<pair<int, int>>& nums, vector<pair<int, int>>& copy, int start, int end, vector<int> &ans)
{
	if (start == end)
	{
		copy[start] == nums[start];
		return;
	}
	int len = (end - start) / 2;
	mergeSort(copy, nums, start, start + len, ans);
	mergeSort(copy, nums, start + len + 1, end, ans);

	//计数加归并排序
	int i = start + len;
	int j = end;
	int indexCopy = end;
	int count = 0;
	while (i >= start&&j >= start + len + 1)
	{
		//此时存在逆序对，将较大的数放入排序数组并加将逆序数加到合适的位置
		if (nums[i].first > nums[j].first)
		{
			ans[nums[i].second] += j - start - len;
			copy[indexCopy--] = nums[i];
			i--;
		}
		else
		{
			copy[indexCopy--] = nums[j--];
		}

	}
	for (; i >= start; --i)
		copy[indexCopy--] = nums[i];
	for (; j >= start + len + 1; --j)
		copy[indexCopy--] = nums[j];
}
vector<int> countSmaller(vector<int>& nums) {
	if (nums.size() == 0) return {};
	int len = nums.size();
	vector<pair<int, int>> vec;
	for (int i = 0; i < len; i++) 
		vec.push_back(make_pair(nums[i], i));
	vector<int> ans(len, 0);
	vector<pair<int, int>> copy(vec);
	mergeSort(vec, copy, 0, len-1, ans);
	return ans;
}

//方法二：用树状数组来做
/*
这是看youtube上一个大佬的做法...总之理解起来还是有点难度，为什么这么做，想完全搞懂好像不是很容易
首先举个例子 5，2，6，1
这四个数，我先把数组倒过来变成1 6 2 5，为什么要倒过来？
因为这道题后面更新元素值用到的是树状数组，树状数组求的是前缀和，
也就是说我构建树状数组后数组第i位的值表示的是从k(我也不知道k是多少，反正就是0~i之间)到i-1的数中小于当前数的个数
所以我把数组倒过来就是为了后序处理方便，大不了最终结果再倒回来呗

然后我需要把数组的数进行排序 也就是说构造了一个数组sorted，1 4 2 3
每一位就是原数组对应的元素在数组中的排序(重复元素排序相同)，这个对应关系由一个哈希表来维持
哈希表的键值对存储着元素与其排名的关系
即ranks数组保存着<1,1>、<6,4>、<2,2>、<5,3>这四个键值对
构造树状数组tree，初始值为全0

找逆序数的过程其实就是元素插入树状数组的过程
从最后一个数(也就是逆序后的第一个数)开始遍历
nums[i]是逆序第size-i项ranks[nums[i]]表示该数在所有数中的排名
query(ranks[nums[i]]-1)则是查找当前数组中位于该数右侧的数字中比当前树小的元素个数
接着将树状数组从ranks[nums[i]]到根节点的路径元素都加1

其实这里本来的操作是这样的：
以上题为例
构造一个 0 0 0 0 0数组
依次将nums[i]元素插入新数组的ranks[nums[i]]位置
第一步 把1插入下标1，第一个位置+1  0 1 0 0 0 在第一位之前共有0个元素
第二步 把6插入下标4，第四个位置+1  0 1 0 0 1 在第四位之前共有1个元素
第三步 把2插入下标2，第二个位置+1  0 1 1 0 0 在第二位之前共有1个元素
第四步 把5插入下标3，第三个位置+1  0 1 1 1 1 在第三位之前共有2个元素
得到的2 1 1 0就是最后的结果

这里的树状数组其的作用就是求前ranks[nums[i]]-1项和
为了将这个过程的复杂度降为o(logn)
至于为什么要逆序遍历，也真是为了树状数组输出能方便，因为利用树状数组可以很方便的更新和求前缀和
*/
class FenwickTree {
public:
	FenwickTree(int n) :sums(n + 1, 0) {};
	//更新数组元素，从当前元素到根节点全部更新
	void update(int i, int val)
	{
		while (i < sums.size())
		{
			sums[i] += val;
			i += lowbit(i);
		}
	}
	//返回前i项的和
	int query(int i) const
	{
		int sum = 0;
		while (i > 0)
		{
			sum += sums[i];
			i -= lowbit(i);
		}
		return sum;
	}
private:
	static inline int lowbit(int x) { return x&(-x); }
	vector<int> sums;

};

vector<int> countSmaller1(vector<int>& nums)
{
	//保存所有的元素值并排序
	set<int> sorted(nums.begin(), nums.end());
	//创建一个哈希表来存储元素的值-元素在数组中的排位的键值对
	unordered_map<int, int> ranks;
	int rank = 0;
	for (const int num : sorted)
		ranks[num] == ++rank;

	vector<int> ans;
	FenwickTree tree(ranks.size());
	//逆序遍历数组
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		//查找数组右侧有多少数字比当前的数字小
		//前面分析过，这一步相当于给前ranks[nums[i]]-1项求和
		ans.push_back(tree.query(ranks[nums[i]] - 1));
		//更新树状数组中当前元素排位到根节点的路径元素的值
		//前面分析过其实类似于给第ranks[nums[i]]位加1，因为树状数组保存的是部分和，则包含这个位的所有位置处都要+1
		tree.update(ranks[nums[i]], 1);
	}
	//翻转得到最终结果
	reverse(ans.begin(), ans.end());
	return ans;
}

/*
int main()
{
	vector<int> nums = { 2,0,1 };
	vector<int> res = countSmaller(nums);
	return 0;
}
*/