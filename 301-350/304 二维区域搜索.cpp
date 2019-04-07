#include<iostream>
#include<vector>
using namespace std;
//304 ��ά��������

/*
����һ����ά���󣬼������Ӿ��η�Χ��Ԫ�ص��ܺͣ����Ӿ�������Ͻ�Ϊ (row1, col1) �����½�Ϊ (row2, col2)��
��ͼ�Ӿ������Ͻ� (row1, col1) = (2, 1) �����½�(row2, col2) = (4, 3)�����Ӿ�����Ԫ�ص��ܺ�Ϊ 8��
ʾ��:
���� matrix = [
[3, 0, 1, 4, 2],
[5, 6, 3, 2, 1],
[1, 2, 0, 1, 5],
[4, 1, 0, 1, 7],
[1, 0, 3, 0, 5]
]
sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
˵��:
����Լ�����󲻿ɱ䡣
���ε��� sumRegion ������
����Լ��� row1 �� row2 �� col1 �� col2��
*/

//���������ƣ��ص����ڱ��沿�ֺͣ������ö�ά����dp������
//���һά���鸴��һ�㣬�������ܼ�
class NumMatrix {
private:
	vector<vector<int>> dp;
public:
	NumMatrix(vector<vector<int>> matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return;
		int rows = matrix.size();
		int cols = matrix[0].size();
		dp.resize(rows);
		for (int i = 0; i<rows; i++)
			dp[i].resize(cols);
		dp[0][0] = matrix[0][0];
		//��ʼ����һ��
		for (int i = 1; i<rows; i++)
			dp[i][0] = dp[i - 1][0] + matrix[i][0];
		//��ʼ����һ��
		for (int i = 1; i<cols; i++)
			dp[0][i] = dp[0][i - 1] + matrix[0][i];
		//��������λ��
		for (int i = 1; i<rows; i++)
		{
			for (int j = 1; j<cols; j++)
			{
				//ΪʲôҪ��ô�㻭ͼһĿ��Ȼ
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		//������������ؽ��
		if (row1 == 0 && col1 == 0)
			return dp[row2][col2];
		else if (row1 == 0)
			return dp[row2][col2] - dp[row2][col1 - 1];
		else if (col1 == 0)
			return dp[row2][col2] - dp[row1 - 1][col2];
		else
			return dp[row2][col2] - dp[row2][col1 - 1] - dp[row1 - 1][col2] + dp[row1 - 1][col1 - 1];

	}
};

int main()
{
	vector<vector<int>> vec = { {3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5} };
	NumMatrix n(vec);
	int res1 = n.sumRegion(2, 1, 4, 3);
	int res2 = n.sumRegion(1, 1, 2, 2);
	int res3 = n.sumRegion(1, 2, 2, 4);
	return 0;
}