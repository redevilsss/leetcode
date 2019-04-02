#include<iostream>
#include<vector>
using namespace std;


//154 寻找旋转排序数组中的最小值2

/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
请找出其中最小的元素。
注意数组中可能存在重复的元素。
*/
//参考上一题，不同的地方就是这里的数组可能会存在重复元素
//重复元素出现时，所有大小判断条件都要加上等号，因为很有可能会出现中点值等于两端点值的情况
//还有一个隐患，那就是会出现中点值、左右端点值全都一样的极端情况，这种情况下无法判断要怎么走，直接遍历子数组找最小值
int findMin(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	int start = 0;
	int end = nums.size() - 1;
	int mid = start;
	while (nums[start] >= nums[end])
	{
		//当end和start相邻的时候，end指向的就是最小值
		//此时start指向第一个升序的最后一个数字，end指向第二个升序的第一个数字，也就是所求数字
		if (end - start == 1)
		{
			mid = end;
			break;
		}
		//否则找中点
		mid = (start + end) / 2;

		//此时直接遍历
		if (nums[mid] == nums[start] && nums[mid] == nums[end])
		{
			int res = nums[start];
			for (int i = start + 1; i < end; i++)
			{
				if (res > nums[i])
					res = nums[i];
			}
			return res;
		}
		//如果中点值大于左端点，说明mid在第一个升序中，要求的最小值在mid右边
		if (nums[mid]>=nums[start])
			start = mid;
		//如果中点值小于左端点且小于右端点，说明mid在第二个升序中，要求的最小值在mid左边
		else if (nums[mid]<=nums[end])
			end = mid;
	}
	return nums[mid];
}