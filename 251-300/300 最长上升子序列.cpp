#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//300 最长上升子序列

/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。
示例:
输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
*/


//用常规的动态规划来做，复杂度为o(n*n)
/*
定义长度为数组长度的数组dp,其中dp[n]表示从0-n的最长上升子序列长度
要获得这个值，就要把nums[0]~nums[i-1]所有的数和nums[i]比较，
如果nums[j]小于nums[i]且j<i，就更新当前dp[i]为max(dp[i],dp[j]+1)
最后遍历dp找最大值即可
*/
int lengthOfLIS(vector<int>& nums) {
	int len = nums.size();
	if (len == 0)
		return 0;
	vector<int>dp(len, 1);
	for (int i = 0; i<len; i++)
	{
		for (int j = 0; j<i; j++)
		{
			if (nums[j]<nums[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int res = dp[0];
	for (int i = 1; i<len; i++)
		res = max(res, dp[i]);
	return res;
}

//另一种思路的动态规划，保证了dp数组元素的单调性，内层循环可以改为二分查找
/*
定义长度为数组长度的数组dp,其中dp[i]表示所有长度为i+1的递增子序列中，最小的序列尾数
则dp数组一定是递增数组，可以用maxLen来表示当前最长递增子序列的长度
对数组进行迭代，依次判断将每个数插入dp数组中的相应的位置：
1. num > dp[maxLen], 表示num比所有已知递增序列的尾数都大, 将num添加入dp数组尾部, 并将最长递增序列长度maxL加1
2. dp[i-1] < num <= dp[i], 只更新相应的dp[i]
遍历完数组后得到的maxLen就是结果
*/
int lengthOfLIS(vector<int>& nums) {
	int len = nums.size();
	if (len == 0)
		return 0;
	int maxLen = 0;
	vector<int>dp(len, 1);
	for (int i = 0; i<len; i++)
	{
		//二分查找，查找当前nums[i]应该在的位置
		int low = 0;
		int high = maxLen;
		while (low<high)
		{
			int mid = (high - low) / 2 + low;
			if (dp[mid]<nums[i])
				low = mid + 1;
			else
				high = mid;
		}
		dp[low] = nums[i];
		//如果low==maxLen，说明一开始nums[i]就是大于dp[maxLen]的
		if (low == maxLen)
			maxLen++;
	}
	return maxLen;
}