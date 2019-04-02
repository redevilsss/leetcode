#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//39 组合总数

/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。
说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。

示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[[7],[2,2,3]]
示例 2:
输入: candidates = [2,3,5], target = 8,
所求解集为:
[[2,2,2,2],[2,3,3],[3,5]]
*/

//该题采用回溯法递归实现，这类题目都是大同小异，思想都一样只有一些约束细节不同
//此题中要注意index参数，来限制结果不要出现重复
//排列组合问题大都用回溯法来做
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	if (candidates.size() == 0)
		return { {} };
	vector<vector<int>> res;
	vector<int> temp;
	sort(candidates.begin(), candidates.end());
	dfs(candidates, target, res, temp, 0);
	return res;
}
//index是用来记录退回的位置，避免结果重复
void dfs(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& temp, int index)
{
	//target小于0，不符合，退出
	if (target<0)
		return;
	//等于0，加入此时的temp数组并返回
	if (target == 0)
	{
		res.push_back(temp);
		return;
	}
	//for循环中判断大小，符合则进行递归
	for (int i = index; i<candidates.size(); i++)
	{
		if (candidates[i] <= target)
		{
			temp.push_back(candidates[i]);
			dfs(candidates, target - candidates[i], res, temp, i);
			temp.pop_back();
		}
	}
}