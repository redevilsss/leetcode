#include<iostream>
#include<vector>
using namespace std;

//34 在排序数组中查找元素的第一个和最后一个位置
//考察二分查找

/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。
示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]

示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

//此题主要还是考察二分查找，用两个子函数实现对左右两个边界的寻找
//先找到值为target的点再判断其是否是最左/右的一个
int getLeftBoundIndex(vector<int>& nums, int left, int right, int target)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
		{
			//mid为0或者mid左边值不为target，说明mid处就是左边界
			if (mid == 0||nums[mid - 1] != target)
				return mid;
			right = mid - 1;
		}

		else if (nums[mid]>target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

int getRightBoundIndex(vector<int>& nums, int left, int right, int target)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
		{
			//mid为最右或者mid右边值不为target，说明mid处就是右边界
			if (mid == nums.size() - 1||nums[mid + 1] != target)
				return mid;
			left = mid + 1;
		}

		else if (nums[mid]>target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}


vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> res(2);
	//先处理特殊情况
	if (nums.size() == 0 || (nums.size() == 1 && nums[0] != target))
		return { -1,-1 };
	if (nums.size() == 1 && nums[0] == target)
		return { 0,0 };
	res[0] = getLeftBoundIndex(nums, 0, nums.size() - 1, target);
	res[1] = getRightBoundIndex(nums, 0, nums.size() - 1, target);
	return res;
}



int main()
{
	vector<int> vec = { 2,2};
	vector<int> res = searchRange(vec, 2);
	return 0;
}