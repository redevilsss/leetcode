#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// 40 ������� 2

/*
����һ������ candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�
candidates �е�ÿ��������ÿ�������ֻ��ʹ��һ�Ρ�
˵����
�������֣�����Ŀ������������������
�⼯���ܰ����ظ�����ϡ�
ʾ�� 1:
����: candidates = [10,1,2,7,6,1,5], target = 8,
����⼯Ϊ:
[[1, 7],[1, 2, 5],[2, 6],[1, 1, 6]]

ʾ�� 2:
����: candidates = [2,5,2,1,2], target = 5,
����⼯Ϊ:
[[1,2,2],[5]]
*/

//��39�⼸��һģһ����ֻ��Ҫ����һ����Ǿ�����������ĳ���Ƿ��Ѿ��ù�
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	if (candidates.size() == 0)
		return { {} };
	set<vector<int>> res;//set��������ͬ���Ľ����γ���
	vector<int> temp;
	int visited[candidates.size()] = {};
	sort(candidates.begin(), candidates.end());
	dfs(candidates, target, res, visited, temp, 0);
	vector<vector<int>> ans(res.begin(), res.end());
	return ans;
}
//index��֤������ظ���visited��֤ÿ��������ÿ�������ֻ��һ��
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