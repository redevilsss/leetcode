#include<iostream>
#include<vector>
using namespace std;

//59 ��������2

/*
����һ�������� n������һ������ 1 �� n2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е������ξ���
ʾ��:
����: 3
���:
[[ 1, 2, 3 ],[ 8, 9, 4 ],[ 7, 6, 5 ]]
*/

//˼·����54���ӡ��˳�����һ����Ҳ��һ��һ�㣬ÿһ��ӵ�ǰ������Ͽ�ʼ
//��ֻ��Ҫ�����������ó�ʼֵΪ1�����մ�ӡ˳��ֵ��ÿ��һ�Σ����õ�ֵ��1
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> res(n, vector<int>(n));
	int start = 0;
	int temp = 0;
	while (n>start * 2 && n>start * 2)
	{
		int endX = n - 1 - start;
		int endY = n - 1 - start;
		for (int i = start; i <= endX; i++)
			res[start][i] = ++temp;
		if (start<endY)
		{
			for (int i = start + 1; i <= endY; i++)
				res[i][endX] = ++temp;
		}
		if (start<endX&&start<endY)
		{
			for (int i = endX - 1; i >= start; --i)
				res[endY][i] = ++temp;
		}
		if (start<endX&&start<endY - 1)
		{
			for (int i = endY - 1; i >= start + 1; i--)
				res[i][start] = ++temp;
		}
		++start;
	}
	return res;
}