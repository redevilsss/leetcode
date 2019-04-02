#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//213 打家劫舍2
/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
示例 1:
输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
*/

//因为最后一家和最后一家也是相邻的，如果不偷第一家，那从第2家到第n家都可以偷
//如果不偷第n家，第1家到第n-1家都可以偷
//类比198题一次动态规划，这道题只需要两次动态规划，求最大值即可
int rob(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	else if (nums.size() == 1)
		return nums[0];
	vector<int> dp1(nums.size(), 0);
	vector<int> dp2(nums.size(), 0);
	dp1[0] = nums[0];
	dp2[1] = nums[1];
	dp1[1] = max(dp1[0], nums[1]);
	//dp1从下标0遍历到len-2，最终结果在dp1[len-2]中
	//dp2从下标1遍历到len-1，最终结果在dp2[len-1]中
	for (int i = 2; i<nums.size() - 1; i++)
		dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
	for (int i = 2; i<nums.size(); i++)
		dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
	return max(dp1[nums.size() - 2], dp2[nums.size() - 1]);

}