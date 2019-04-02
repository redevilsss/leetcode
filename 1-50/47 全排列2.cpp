#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//47 ȫ����
/*
����һ���ɰ����ظ����ֵ����У��������в��ظ���ȫ���С�
ʾ��:
����: [1,1,2]
���:
[[1,1,2],[1,2,1],[2,1,1]]
*/


//��46����һ������Ϊ�����ظ�Ԫ�أ���������ظ�Ԫ�ر�Ȼ����
//��nums[i] == nums[i - 1] && !visited[i - 1]ʱҪ�������Ա����ظ����
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