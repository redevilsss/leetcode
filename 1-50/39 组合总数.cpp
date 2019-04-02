#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//39 �������

/*
����һ�����ظ�Ԫ�ص����� candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�
candidates �е����ֿ����������ظ���ѡȡ��
˵����
�������֣����� target��������������
�⼯���ܰ����ظ�����ϡ�

ʾ�� 1:
����: candidates = [2,3,6,7], target = 7,
����⼯Ϊ:
[[7],[2,2,3]]
ʾ�� 2:
����: candidates = [2,3,5], target = 8,
����⼯Ϊ:
[[2,2,2,2],[2,3,3],[3,5]]
*/

//������û��ݷ��ݹ�ʵ�֣�������Ŀ���Ǵ�ͬС�죬˼�붼һ��ֻ��һЩԼ��ϸ�ڲ�ͬ
//������Ҫע��index�����������ƽ����Ҫ�����ظ�
//�������������û��ݷ�����
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	if (candidates.size() == 0)
		return { {} };
	vector<vector<int>> res;
	vector<int> temp;
	sort(candidates.begin(), candidates.end());
	dfs(candidates, target, res, temp, 0);
	return res;
}
//index��������¼�˻ص�λ�ã��������ظ�
void dfs(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& temp, int index)
{
	//targetС��0�������ϣ��˳�
	if (target<0)
		return;
	//����0�������ʱ��temp���鲢����
	if (target == 0)
	{
		res.push_back(temp);
		return;
	}
	//forѭ�����жϴ�С����������еݹ�
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