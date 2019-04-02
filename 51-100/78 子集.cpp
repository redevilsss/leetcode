#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//78 �Ӽ�

/*
����һ�鲻���ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����
˵�����⼯���ܰ����ظ����Ӽ���
ʾ��:
����: nums = [1,2,3]
���:
[[3],[1],[2],[1,2,3],[1,3],[2,3],[1,2],[]]
*/


//�����뵽�û��ݵݹ飬�ص�������ο����Ӽ���Ԫ�ظ���
//����û��ݺ͵ݹ���������⣬��ô�ص������ο����Ӽ����ȣ������˳�����
//����˱��˵Ĵ��룬����indexһ�����ã���push��ǰindex��Ӧ��ֵǰ�������һ�εݹ飬ǰ��һ�εݹ���δ���뵱ǰindex��ֵ������һ�����Ǽ��뵱ǰindexֵ��
//���� 1 2 3 4��ǰһ�εݹ�ֱ�Ӵ�2��ʼ����һ�������ȱ���1���ٴ�2��ʼ���Դ�����
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> res;
	if (nums.size() == 0)
		return res;
	vector<int> temp;
	sort(nums.begin(), nums.end());
	func(res, temp, nums, 0);
	return res;
}
void func(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int index)
{
	if (index == nums.size())
	{
		res.push_back(temp);
		return;
	}
	func(res, temp, nums, index + 1);
	temp.push_back(nums[index]);
	func(res, temp, nums, index + 1);
	temp.pop_back();
}


//���ӱ������ͼ����㷨��ʹ��λ���㣬��0000...~11111...��ÿһλ��ʾ��һλ��Ӧ�������е���ȡ��ȡ����ȡ��������飬ѭ��2��n�η��Σ����Եõ�ȫ��2��n�η����Ӽ�
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> res;
	int n = nums.size();
	for (int i = 0; i<(1 << n); i++)//1<<n����2��n�η�,���յĽ���Ӽ�����2��n�η���������ÿ��ѭ���õ�һ���Ӽ�������i�Ķ�����ÿһλ��ʾ�Ƿ�ȡ������ĳһλ��Ԫ��
	{
		vector<int> temp;
		//��һ���̲���һ���Ӽ����ٸ����ӣ����nums={1��2��3},��000��Ӧ�ռ���001 010 100�ֱ��Ӧ[1] [2] [3]��011 101 110�ֱ��ʾ[2,3] [1,3] [1,2] 111��ʾ[1,2,3]
		//��i��ÿһλ�����жϾ��ܵõ��Ӽ�
		for (int j = 0; j<n; j++)
			if (i >> j & 1)
				temp.push_back(nums[j]);
		res.push_back(temp);
	}
	return res;
}