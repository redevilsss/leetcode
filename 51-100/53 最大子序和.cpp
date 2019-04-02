#include<iostream>
#include<vector>
using namespace std;

//53 最大子序和
/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/


//首先要确定的是空子序的和是0，也就是说我未开始遍历之前，子序和是0，
//那么现在开始遍历，定义一个当前和，再定义一个最大和
//当我的当前和大于0时，说明此时的子序和是比初始时候高的，继续加上下一个元素
//否则，说明我的子序和连初始值都不如，我把子序和置0，从下一个元素开始重新计数
//每次的当前和都需要和最大和进行比较，更新最大和
int maxSubArray(vector<int>& nums) {
	if (nums.size() == 1)
		return nums[0];
	int maxSum = 0x80000000;
	int curSum = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		if (curSum <= 0)
			curSum = nums[i];
		else
			curSum += nums[i];
		if (curSum>maxSum)
			maxSum = curSum;
	}
	return maxSum;
}