#include<iostream>
#include<vector>
using namespace std;

// 35 搜索插入位置
//考察二分查找
/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。
示例 1:
输入: [1, 3, 5, 6], 5
输出 : 2

示例 2 :
输入 : [1, 3, 5, 6], 2
输出 : 1

示例 3 :
输入 : [1, 3, 5, 6], 7
输出 : 4

示例 4 :
输入 : [1, 3, 5, 6], 0
输出 : 0
*/

//这个题还是考察二分查找，不做过多赘述
int searchInsert(vector<int>& nums, int target) {
	if (nums.size() == 0 || (nums.size() == 1 && nums[0] != target))
		return -1;
	if (nums.size() == 1 && nums[0] < target)
		return 1;
	else if(nums.size() == 1 && nums[0] >= target)
		return 0;
	//取两个指针分别指向头和尾
	int begin = 0;
	int end = nums.size() - 1;
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		//如果中间值为mid，说明能找到，直接返回mid
		if (target == nums[mid])
			return mid;
		//如果目标值大于中间值，分情况讨论
		else if (target>nums[mid])
		{
			if (mid == nums.size() - 1)
				return nums.size();
			//当目标大于中间值小于中间值的下一个值时，数组中不存在目标值
			//把目标值放进来的下标是mid+1
			else if ( nums[mid + 1] > target)
				return mid+1;
			else//否则继续遍历
				begin = mid + 1;
				
		}
		else
		{
			if (mid == 0)
				return mid;
			//当目标小于中间值大于中间值的上一个值时，数组中不存在目标值
			//把目标值放进来的下标是mid
			if (nums[mid - 1]<target)
				return mid;
			else
				end = mid - 1;
		}
	}
	return begin;
}

int main()
{
	vector<int> vec = { 1,3 };
	int res = searchInsert(vec,2);
	return 0;
}