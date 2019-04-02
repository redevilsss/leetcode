#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// 40 组合总数 2

/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。
说明：
所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。
示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[[1, 7],[1, 2, 5],[2, 6],[1, 1, 6]]

示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[[1,2,2],[5]]
*/

//与39题几乎一模一样，只是要利用一个标记矩阵标记数组中某数是否已经用过
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	if (candidates.size() == 0)
		return { {} };
	set<vector<int>> res;//set用来避免同样的结果多次出现
	vector<int> temp;
	int visited[candidates.size()] = {};
	sort(candidates.begin(), candidates.end());
	dfs(candidates, target, res, visited, temp, 0);
	vector<vector<int>> ans(res.begin(), res.end());
	return ans;
}
//index保证结果不重复，visited保证每个数字在每个组合里只用一次
void dfs(vector<int>& candidates, int target, set<vector<int>>& res, int visited[], vector<int>& temp, int index)
{
	if (target<0)
		return;
	if (target == 0)
	{
		res.insert(temp);
		return;
	}
	for (int i = index; i<candidates.size(); i++)
	{
		if (visited[i] == 0 && candidates[i] <= target)
		{
			temp.push_back(candidates[i]);
			visited[i]++;
			dfs(candidates, target - candidates[i], res, visited, temp, i);
			visited[i]--;
			temp.pop_back();
		}
	}
}