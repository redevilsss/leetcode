#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//������һ�㿼�ǵľ��ǻ��ݵݹ�Ͷ�̬�滮
//���ݵݹ��ʺϻ���Ԫ��ֵ�����⣬��̬�滮�ʺϻ���λ�õ�����
/*
�������⣬����Ҫ�ҳ���������εı߳�
��ô���أ��ҵ�ǰ���Ӧ��dp[i][j]��Χ��dp[i-1][j]��dp[i-1][j-1]��dp[i][j-1]�е���Сֵ��1
Ҳ����˵��ֻҪ������ֵ����һ����0����dp[i][j]����1
��֮������������Ҫ�ľ��Ƕ�̬�滮�ĵ�����ʽ
*/
int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return 0;
	int row = matrix.size();
	int col = matrix[0].size();
	//����dp��ά����
	vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
	//�������
	int maxLength = 0;
	//�����������dp�����maxLength������Ҫע��matrix�����dp������±겻һ��
	//dp[i][j]��¼������matrix[i-1][j-1]Ϊ���¶������������α߳�����������maxLength
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (matrix[i - 1][j - 1] == '1')//matrix��i j��dp�ж�Ӧ���±���i+1��j+1����Ϊdp�Ǵ�1��ʼ��
			{
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
				maxLength = max(maxLength, dp[i][j]);
			}

		}
	}
	return maxLength*maxLength;
}