#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//209 长度最小的子数组
/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
示例:
输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
*/

/*
这道题用双指针遍历，初始时两指针都指向起始位置，左指针和右指针
设置初始最小长度为INT_MAX，当前和sum为0
开始遍历，叠加当前right指针的值，当此时sum大于等于s时，记录当前的长度(right-left+1)
并更新最小长度，left指针前移，更改sum值，循环直到sum小于s
再回到主循环中，更新right指针
*/
int minSubArrayLen(int s, vector<int>& nums) {
	int len = nums.size();
	int left = 0;
	int right = 0;
	int sum = 0;
	int minLen = INT_MAX;
	while (right < len)
	{
		sum += nums[right];
		while (sum >= s)
		{
			int curLen = right - left + 1;
			minLen = min(minLen, curLen);
			sum -= nums[left];
			left++;
		}
		right++;
	}
	if (minLen = INT_MAX)
		return 0;
	return minLen;
}