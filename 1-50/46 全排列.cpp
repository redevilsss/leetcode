#include<iostream>
#include<vector>
using namespace std;

// 46 ȫ����

/*
����һ��û���ظ����ֵ����У����������п��ܵ�ȫ���С�

ʾ��:
����: [1,2,3]
���:
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

//��ǰ���39 40˼·����һ���������û��ݵݹ�ʵ��
vector<vector<int>> permute(vector<int>& nums) {
	if (nums.size() == 0)
		return { {} };
	vector<vector<int>> res;
	vector<int> temp;
	int visited[nums.size()] = {};
	permuteCore(nums, res, temp, visited, 0);
	return res;
}

//visited���鱣֤ÿ������ֻ����һ�Σ�n���Ƶݹ������nС�����鳤��ʱ�ݹ飬����ʱ������������
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