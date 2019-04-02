#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//198 打家劫舍

/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
示例 1:
输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
偷窃到的最高金额 = 1 + 3 = 4 。
*/


//用动态规划来实现，构造数组存储中间值，遍历原数组，
//当前位置的值就是max(dp[i-1]，dp[i-2}+nums[i]),取两种情况的较大值

int rob(vector<int>& nums) {
	int length = nums.size();
	if (length == 0)
		return 0;
	if (length <= 1)
		return length == 0 ? 0 : nums[0];
	//dp[i]表示抢劫到第i家时获得的最大收益
	vector<int> dp(length, 0);
	//初始化dp[0]和dp[1]
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	//当前位置的最大收益前两位的值以及当前位置的值有关
	for (int i = 2; i<length; i++)
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	//最终dp数组的最后一位表示的就是所求的最大值
	return dp[length - 1];
}