#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//47 全排列
/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。
示例:
输入: [1,1,2]
输出:
[[1,1,2],[1,2,1],[2,1,1]]
*/


//与46基本一样，因为包含重复元素，而排序后重复元素必然相邻
//当nums[i] == nums[i - 1] && !visited[i - 1]时要跳过，以避免重复结果
vector<vector<int>> res;
vector<int> temp;
vector<int> visited;
vector<vector<int>> permuteUnique(vector<int>& nums) {
	if (nums.size() == 0)
		return { {} };
	visited.resize(nums.size());
	sort(nums.begin(), nums.end());
	permuteCore(nums);
	return res;
}
void permuteCore(vector<int>& nums)
{
	if (temp.size() == nums.size())
	{
		res.push_back(temp);
		return;
	}

	else
	{
		for (int i = 0; i<nums.size(); i++)
		{
			if (i>0 && nums[i] == nums[i - 1] && !visited[i - 1])
				continue;
			if (visited[i] == 0)
			{
				temp.push_back(nums[i]);
				visited[i]++;
				permuteCore(nums);
				visited[i]--;
				temp.pop_back();
			}
		}
		return;
	}
}