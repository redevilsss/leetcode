#include<iostream>
#include<vector>
using namespace std;

// 33 搜索旋转排序数组
/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。

示例 1:
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4

示例 2:
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/


//这个算法的重点在于如何在旋转数组上进行二分查找
//对于旋转数组，取中间下标一分为二，至少有一个子数组是有序的
//如果落在无序部分则继续分，否则可以二分查找获得结果
int serachCore(vector<int>& nums, int left, int right, int target)
{
	if (left>right)//未找到
		return -1;
	int mid = (left + right) / 2;
	if (target == nums[mid])
		return mid;
	//若中间值大于右值，说明前一半是有序的
	if (nums[mid]>nums[right])
	{
		//如果中间值大于target且左值小于target，说明就在left mid-1之中
		//这一区间是有序的
		if (nums[mid] > target&&target >= nums[left])
			return serachCore(nums, left, mid - 1, target);
		else
			//否则继续遍历
			return serachCore(nums, mid + 1, right, target);
	}
	else//中间值小于右值，说明后一半是有序的
	{
		//如果或中间值小于target而右值小于等于target，说明就在mid+1，right之间
		//这一区间是有序的
		if (nums[mid]<target&&target <= nums[right])
			return serachCore(nums, mid + 1, right, target);
		else//否则继续遍历
			return serachCore(nums, left, mid - 1, target);
	}
}

int search(vector<int>& nums, int target)
{
	return serachCore(nums, 0, nums.size() - 1, target);
}

int main()
{
	vector<int> vec = { 3,1 };
	int res = search(vec, 0);
	return 0;
}