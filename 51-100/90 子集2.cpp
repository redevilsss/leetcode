#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//90 子集2

/*
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。
示例:
输入: [1,2,2]
输出:
[[2],[1],[1,2,2],[2,2],[1,2],[]]
*/


/*方法一：借鉴别人的方法，思路是在之前已经生成的子列的基础上依次加入新元素，生成新子列
* 这种思路下重复子列的出现是因为加入新元素过程中没有对连续的相同元素进行处理
* 举例 1 2 2
* 第一步遍历完时子集有 [] [1]
* 第二步遍历完时子集有 [] [1] [2] [1,2]，这里后面两个就是在前面两个的基础上加2
* 第三部遍历完时子集有 [] [1] [2] [1,2] [2] [1,2] [2,2] [1 2 2]
* 重复就出现在这里，第一个2遍历完时子集已经包括了 [2] [1 2]
* 第二个2遍历时就不应该再让2加入之前的子集[] [1]中，因为之前第二步已经做过类似的事情了
* 有多少元素遍历多少次，这个很好确定，但是所以如何定义每次遍历的次数呢
* 这里用left right作为每次遍历的下界，而length用来保存前一次遍历的次数
* 当出现重复元素时，就用当前子集数减去length作为本次遍历的起点，否则就从下标0开始
*/
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	vector<int> temp;
	res.push_back(temp);
	int right = 1, left = 0, length = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		if (i != 0 && nums[i] == nums[i - 1])
			left = res.size() - length;
		else
			left = 0;
		right = res.size();
		length = right - left;
		for (int j = left; j<right; j++)
		{
			temp = res[j];
			temp.push_back(nums[i]);
			res.push_back(temp);
		}
	}
	return res;
}

/* 方法二：用之前子集1用的位运算，对最后的结果进行去重
*/
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	int n = nums.size();
	for (int i = 0; i < (1 << n); i++)//1<<n就是2的n次方,最终的结果子集就是2的n次方个，所以每次循环得到一个子集，这里i的二进制每一位表示是否取数组中某一位的元素
	{
		vector<int> temp;
		//这一过程产生一个子集，举个例子，如果nums={1，2，3},则000对应空集，001 010 100分别对应[1] [2] [3]，011 101 110分别表示[2,3] [1,3] [1,2] 111表示[1,2,3]
		//对i的每一位进行判断就能得到子集
		for (int j = 0; j < n; j++)
			if (i >> j & 1)
				temp.push_back(nums[j]);
		res.push_back(temp);
	}
	//删除重复元素，unique将连续的相同元素除重，重复部分放到结尾去，返回原来的结尾
	//从原结尾到新结尾之间的元素是重复的
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	return res;
}

/* 方法三：使用原78题子集中的回溯算法，增加去重和排序
*/

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	vector<vector<int>> res;
	if (nums.size() == 0)
		return res;
	vector<int> temp;
	sort(nums.begin(), nums.end());
	func(res, temp, nums, 0);
	return res;
}
void func(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int index)
{
	res.push_back(temp);//每次遍历先将上一步得到的temp保存
	for (int i = index; i < nums.size(); i++)
	{
		if (i > index && nums[i] == nums[i - 1])
			continue;//遇到重复元素时直接跳过
		temp.push_back(nums[i]);
		func(res, temp, nums, i + 1);
		temp.pop_back();
	}
}



