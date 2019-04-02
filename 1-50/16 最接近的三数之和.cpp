#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//16 最接近的三数之和
/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。
例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

//核心思想和同15题，不做赘述，只是多了一个保存最大值的过程
int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int res = INT_MAX, len = nums.size();
	int left = 0, right = len - 1;
	int now, min_abs = INT_MAX;
	for (auto i = 0; i < len; ++i)
	{
		for (left = i + 1, right = len - 1; left < right;)
		{
			now = nums[i] + nums[left] + nums[right];
			if (target == now)
				return now;
			if (abs(target - now) < min_abs)
			{
				res = now;
				min_abs = abs(target - now);
			}
			if (now > target)
				right--;
			else
				left++;
		}
	}
	return res;
}
