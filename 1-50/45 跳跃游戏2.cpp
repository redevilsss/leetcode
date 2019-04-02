#include<iostream>
#include<vector>
using namespace std;

// 45 跳跃游戏2

/*
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:
输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
*/


//此题的核心在于“充足的前瞻”，每次不仅要考虑下一步的结果，还要考虑到下下一步
//选取使得下下一步跳的最远的点
int jump(vector<int>& nums) {
	int steps = 0;
	int nextIndex = 0;
	int curIndex = 0;
	//思想：记录从该位置起两步步能到达的最远距离，然后用curIndex更新位置到使得两步走最长的位置，
	//并加步长，再从现在的curIndex记录走两步最远能到哪里，循环
	//直到发现从某curIndex起可以一步走到终点，再加步数且循环退出，
	while (curIndex<nums.size() - 1)
	{
		int far = 0;//记录当前两步走的最远位置
		for (int i = curIndex + 1; i <= curIndex + nums[curIndex] && i<nums.size(); i++)
		{
			if (i == nums.size() - 1)
			{
				nextIndex = i;
				break;
			}
			int temp = i + nums[i];//若下一步走到i处，下下一步能跳到的最远位置
			if (temp>far)
			{
				nextIndex = i;
				far = temp;
			}
		}
		//更新当前下标
		curIndex = nextIndex;
		steps++;//步数增加
	}
	return steps;
}