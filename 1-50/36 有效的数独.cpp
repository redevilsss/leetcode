#include<iostream>
#include<vector>
using namespace std;

// 36 ��Ч������
/*
�ж�һ�� 9x9 �������Ƿ���Ч��ֻ��Ҫ�������¹�����֤�Ѿ�����������Ƿ���Ч���ɡ�
���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
���� 1-9 ��ÿһ���Դ�ʵ�߷ָ��� 3x3 ����ֻ�ܳ���һ�Ρ�
*/


//˼�룬��̬�滮��������9*10�������ʾĳһ��ĳ�����Ƿ��Ѿ����ֹ�
bool isValidSudoku(vector<vector<char>>& board) 
{
	vector<vector<bool>> row(9, vector<bool>(10, false));
	vector<vector<bool>> col(9, vector<bool>(10, false));
	vector<vector<bool>> block(9, vector<bool>(10, false));
	for (int i = 0; i<9; i++)
		for (int j = 0; j<9; j++)
		{
			if (board[i][j] != '.')//���Ϊ��Ϊ�㣬˵���Ѿ��������֣��ж��Ƿ����
			{
				int num = board[i][j] - '0';
				//���������������һ�������Ѿ����ֹ����ͷ���false
				if (row[i][num] || col[j][num] || block[i / 3 * 3 + j / 3][num])
					return false;
				else
				{
					//����������������ֵ
					row[i][num] = true;
					col[j][num] = true;
					//���к���⣬�������Ĳ������
					//��Ϊ��3*3��С����ͨ���˳�����ʵ�ֻ���
					//��[8,8]����8/3*3+8/3=8��Ҳ���ǵ�9������
					block[i / 3 * 3 + j / 3][num] = true;
				}
			}
		}
	return true;

}