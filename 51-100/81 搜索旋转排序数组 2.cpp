#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//82 搜索旋转排序数组2
/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
（ 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
示例:
输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
*/

//方法一：借鉴剑指offer中的第11题，对出现左中右三个下标值相同的情况进行特殊处理，其余和33题保持一致
int serachCore(vector<int>& nums, int left, int right, int target)
{
	if (left>right)
		return false;
	int mid = (left + right) / 2;
	if (target == nums[mid])
		return true;

	if (nums[mid] == nums[left] && nums[mid] == nums[right])
	{
		for (int i = left; i < right; i++);
		{
			if (nums[i] == target)
				return true;
		}
		return false;
	}
	if (nums[mid]>nums[right])
	{
		if (nums[mid] > target&&target >= nums[left])
			return serachCore(nums, left, mid - 1, target);
		else
			return serachCore(nums, mid + 1, right, target);
	}
	else
	{
		if (nums[mid]<target&&target <= nums[right])
			return serachCore(nums, mid + 1, right, target);
		else
			return serachCore(nums, left, mid - 1, target);
	}
}

bool search(vector<int>& nums, int target)
{
	return serachCore(nums, 0, nums.size() - 1, target);
}


//方法2：不用遍历直接循环，但思路一样
bool search(vector<int>& nums, int target) {
	int l = 0, r = nums.size() - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] == target || nums[l] == target || nums[r] == target) //说明此时数组中存在目标值
			return true;
		if (nums[mid] == nums[r]) //当中间值等于右值时，无法判断当前哪个字串有序，将右下标左移直到中间值大于右值
			while (nums[mid] == nums[r]) 
				--r;
		else if (nums[mid] > nums[r]) //mid处于第一个递增序列上，l到mid递增
		{
			if (nums[r] > target || nums[mid] < target) //nums[r] > target说明target在mid和r之间，nums[mid] < target说明target在mid和最大数之间，将左边界调整至mid+1
				l = mid + 1;
			else 
				r = mid - 1;//否则去另一边找
		}
		else //mid处于第二个递增数列上 nums[mid] < nums[r],mid到r递增
		{
			if (nums[mid] > target || nums[r] < target) //nums[mid] > target说明若存在target则在最小数和mid之间，nums[r] < target说明若存在target则在l和mid-1之间
				r = mid - 1;
			else 
				l = mid + 1;//否则去另一边找
		}
	}
	return false;
}
int main()
{
	vector<int> vec = { 2,5,6,0,0,1,2 };
	bool res = search(vec, 3);
}
