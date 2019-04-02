#include<iostream>
#include<vector>
using namespace std;

// 46 全排列

/*
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:
输入: [1,2,3]
输出:
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

//与前面的39 40思路几乎一样，还是用回溯递归实现
vector<vector<int>> permute(vector<int>& nums) {
	if (nums.size() == 0)
		return { {} };
	vector<vector<int>> res;
	vector<int> temp;
	int visited[nums.size()] = {};
	permuteCore(nums, res, temp, visited, 0);
	return res;
}

//visited数组保证每个数字只出现一次，n控制递归次数，n小于数组长度时递归，等于时保存结果并返回
void permuteCore(vector<int>& nums, vector<vector<int>>& res, vector<int> temp, int visited[], int n)
{
	if (n == nums.size())
		res.push_back(temp);
	else
	{
		for (int i = 0; i<nums.size(); i++)
		{
			if (visited[i] == 0)
			{
				temp.push_back(nums[i]);
				visited[i]++;
				permuteCore(nums, res, temp, visited, n + 1);
				visited[i]--;
				temp.pop_back();
			}
		}
	}
}