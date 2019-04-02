#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//164 最大间距
/*
给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
如果数组元素个数小于 2，则返回 0。
示例 1:
输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。*/






/*考虑用分桶法，一个数组最小值为low，最大值为high，如果数组在low和high之间均匀分布，得到的最大差值是最小的，
比如数组[1,3,5,7,9]，差值为2，而数组[1,3,4,5,9]，最大差值是4，虽然两个数组最小值和最大值以及元素数目均相同。
考虑分桶，桶的容量为(high-low)/n，其中n为元素的数组，则最大差值一定大于等于桶的容量。
桶的个数为(high-low)/桶的容量+1,也就是n+1，然后找出每个桶的最大值和最小值，那么最大差值一定是桶之间的最大间隔
为什么说最大值一定在相邻非空桶之间？
等于的情况就是前面所说的所有元素均匀分布，否则最大差值就一定存在于两个相邻的非空的桶之间，
因为任意一个桶的内部差值最多为桶的容量，只要数据不是完全均匀分布，最大差值就一定大于桶的容量，那就一定在相邻的非空桶之间
。*/
int maximumGap(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	//分保存数组元素的最大值和最小值
	int low = INT_MAX;
	int high = INT_MIN;
	int len = nums.size();
	for (int i = 0; i<len; i++)
	{
		low = min(low, nums[i]);
		high = max(high, nums[i]);
	}
	//每个桶中的元素个数，桶容量
	if (low == high)
		return 0;
	//最大值 最小值和判断是否有值的数组，长度均为len+1，(high-low)/((high - low)/len)+1
	vector<bool> hasNum(len + 1, 0);
	vector<int> mins(len + 1, 0);
	vector<int> maxs(len + 1, 0);
	int index = 0;

	for (int i = 0; i<len; i++)
	{
		//判断当前数字在哪个桶中，(nums[i] - low)/ ((high - low)/len),其中(high - low)/len就表示桶容量，用当前值与最小值差值除以桶容量，就是当前值被放在桶中的位置;
		index = (int)((long)nums[i] - low)*(long)len / (high - low);
		//更新桶内保存的最大值和最小值
		if (mins[index])
		{
			mins[index] = min(mins[index], nums[i]);
			maxs[index] = max(maxs[index], nums[i]);
		}
		else
		{
			mins[index] = nums[i];
			maxs[index] = nums[i];
			hasNum[index] = true;
		}

	}
	int res = 0;
	int lastMax = maxs[0];
	int i = 1;
	for (; i <= len; i++)
	{
		if (hasNum[i])
		{
			res = max(res, mins[i] - lastMax);
			lastMax = maxs[i];
		}
	}
	return res;
}