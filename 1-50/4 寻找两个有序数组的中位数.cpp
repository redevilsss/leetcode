#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;

//4 寻找两个有序数组的中位数
/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。
示例 1:
nums1 = [1, 3]
nums2 = [2]
则中位数是 2.0

示例 2:
nums1 = [1, 2]
nums2 = [3, 4]
则中位数是 (2 + 3)/2 = 2.5

*/


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	//记录两数组的长度
	int len1 = nums1.size();
	int len2 = nums2.size();
	int len = len1 + len2;
	//对两个数组进行排序，两数组为有序数组，所有一次归并即可排序完成
	int *nums = new int[len];
	int i = 0, j = 0;
	for (int k = 0; k < len; ++k) {
		//当数组2走完或者当数组1未走完且数组1目前的值小于数组2目前的值时，归入数组1中元素
		if (j == len2 || (i < len1 && nums1[i] < nums2[j])) {
			nums[k] = nums1[i++];
		}
		else {
			nums[k] = nums2[j++];
		}
	}
	//根据长度为奇或偶来取中位数
	if (len % 2 != 0)
		return nums[len / 2];
	else
		return (nums[len / 2 - 1] + nums[len / 2]) / 2.0;

}