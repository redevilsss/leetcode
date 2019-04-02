#include<iostream>
#include<vector>
using namespace std;

//54 ��������

/*
����һ������ m x n ��Ԫ�صľ���m ��, n �У����밴��˳ʱ������˳�򣬷��ؾ����е�����Ԫ�ء�
ʾ�� :
����:
[[1, 2, 3],[4, 5, 6],[7, 8, 9]]
��� : [1, 2, 3, 6, 9, 8, 7, 4, 5]
*/


//�������ǽ�ָoffer��29��
//˼·������Ҫȷ����ô��ӡ����������һ��һ���ӡ����ӡ���ٲ㣿��������Ϊ�к��еĽ�Сֵ����2
//��ο�����ô�򣿷��Ĳ��� ���ϵ����� ���ϵ����� ���µ����� ���µ�����
//ÿһ���ֶ��ֱ��ӡ�����أ�
//��3*4���������Ϊ�� ���ϵ������Ǵ�[0][0]~[0][3] 4�� ���ϵ����´�[1][3]~[2][3] 2��
//���µ������Ǵ�[2][2]~[2][0] 3�� ���µ����ϴ�[1][0] 1��
//���Ҹ��������ڲ���״�Ĳ�ͬ����һ�������������Ĳ��֣�������ڲ�ֻ��һ�У�һ�ξ��ܴ���
//���廭��ͼ�������
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	if (matrix.size() == 0)
		return res;
	int start = 0;//��������
	int rows = matrix.size();
	int cols = matrix[0].size();
	while (cols>start * 2 && rows>start * 2)
	{
		int endX = cols - 1 - start;//����ÿһ������ĺ��������ֵ
		int endY = rows - 1 - start;//����ÿ����������������ֵ
		//��ʼ��ӡ,���ϵ����� 
		for (int i = start; i <= endX; i++)
			res.push_back(matrix[start][i]); 
		if (start<endY)
		{
			//���ϵ�����
			for (int i = start + 1; i <= endY; i++)
				res.push_back(matrix[i][endX]);
		}
		if (start<endX&&start<endY)
		{
			// ���µ�����
			for (int i = endX - 1; i >= start; --i)
				res.push_back(matrix[endY][i]);
		}
		if (start<endX&&start<endY - 1)
		{
			// ���µ�����
			for (int i = endY - 1; i >= start + 1; i--)
				res.push_back(matrix[i][start]);
		}
		++start;
	}
	return res;
}
