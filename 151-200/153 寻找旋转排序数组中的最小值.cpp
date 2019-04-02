#include<iostream>
#include<vector>
using namespace std;


//153 寻找旋转排序数组中的最小值

/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
请找出其中最小的元素。
你可以假设数组中不存在重复元素。
*/

//这道题和第33题基本思想是一样的，是剑指offer的第11题，思想都是二分查找
/*
方法不少但是思想都是二分查找
旋转排序数组的特点：其实是两个升序链表，前一个升序的任意数字都大于后一个升序里的任意数组，要找的最小数值就是第二个升序的首个元素
剑指offer中的思路：
双指针start和end，分别指向第一个升序的头和第二个升序的尾，结束条件是start处的值小于end处的值
因为此时两指针已经在一个升序里了，要找的第二个升序的第一个数字
*/


int findMin(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	int start = 0;
	int end = nums.size() - 1;
	int mid = start;
 	while (nums[start] > nums[end])
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
		//如果中点值大于左端点，说明mid在第一个升序中，要求的最小值在mid右边
		if (nums[mid]>nums[start])
			start = mid ;
		//如果中点值小于左端点且小于右端点，说明mid在第二个升序中，要求的最小值在mid左边
		else if (nums[mid]<nums[end])
			end = mid;
	}
	return nums[mid];
}

int main()
{
	vector<int> vec = { 3,4,5,1,2, };
	int res = findMin(vec);
	return 0;
}