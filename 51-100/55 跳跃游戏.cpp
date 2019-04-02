#include<iostream>
#include<vector>
using namespace std;


/*
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。
示例 1:
输入: [2, 3, 1, 1, 4]
输出 : true
解释 : 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
*/

//思路：从倒数第二位开始遍历，如果该下标加上下标处的值大于等于 n=size-1
//说明从倒数第二步可以走到最后一个位置，那么我现在的问题就变成了判断能否走到倒数第二步更新n为size-2
//以此类推，每次如果满足下标值加下标处的值大于等于当前判断的位置
//就把位置进行更新，如果遍历完后n=0，说明可以到达


bool canJump(vector<int>& nums) {
	int n = nums.size() - 1;//n表示从某一点起可以到达终点
	for (int i = nums.size() - 2; i >= 0; i--)
	{
		if (nums[i] + i >= n)//从第i点起可以到达终点，更新n的值
			n = i;
	}
	if (n == 0)
		return true;
	else
		return false;
}
