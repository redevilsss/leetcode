#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 77 ���
/*
������������ n �� k������ 1 ... n �����п��ܵ� k ��������ϡ�
ʾ��:
����: n = 4, k = 2
���:
[[2,4],[3,4],[2,3],[1,2],[1,3],[1,4],]
*/


//���������͵Ļ��ݵݹ����͵���Ŀ���ص�������ο�����ȡ���������������ֵ
//�ٸ����� n=4�� 1 2 3 4 k=2�����ȡ�������ֵ��Ҫ����һ���������ڴ洢��ǰ�ݹ�������±���
//��Ϊ��һ�α�������㣬��һ�Ͳ�������ظ���Ҳ�ܱ��������е���
vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> res;
	vector<int> temp;
	if (n == 0 || k == 0 || n<k)
		return res;
	func(res, temp, n, k, 1);
	return res;
}
void func(vector<vector<int>>& res, vector<int>& temp, int n, int k, int index)
{
	if (k == temp.size())
	{
		res.push_back(temp);
		return;
	}
	for (int i = index; i <= n; i++)
	{
		temp.push_back(i);
		//�����i����Ҫ��ʵ�ֶ����ٵ�ʱ��һ��Ҫ������������Ƶݹ�ʱ������ı��
		func(res, temp, n, k, i + 1);
		temp.pop_back();
	}
}