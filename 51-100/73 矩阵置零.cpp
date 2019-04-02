#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//73 ������0
/*
����һ�� m x n �ľ������һ��Ԫ��Ϊ 0�����������к��е�����Ԫ�ض���Ϊ 0����ʹ��ԭ���㷨��
ʾ�� 1:
����:
[[1,1,1],[1,0,1],[1,1,1]]
���:
[[1,0,1],[0,0,0],[1,0,1]]
*/



//������õ������ʱ��Ҳ��û�뵽���˱��˵Ĵ�
//��Ϊ��һ������λ0��Ҫɾ���������ڵ������к��У���β��ܽ��Ϳռ临�Ӷȣ�
//���ֱ�Ӵ�����Ҫm+n�ĸ��Ӷȣ�����������������������������
//�ٰ��������е�����m+n�ĸ����ռ䣬������¼���и����Ƿ���Ҫɾ���������
//��¼��ɺ󣬱������к����У��Ծ�����д���
//�����ٸ������������������Ϣ���������н��д���

void setZeroes(vector<vector<int>>& matrix) {
	//�������������Ƿ���Ҫ�������Ϣ��������������Ϊ���
	//�ж������Ƿ���Ҫ��0
	int colFlag = 0;
	for (int i = 0; i<matrix.size(); i++)
	{
		if (matrix[i][0] == 0)
		{
			colFlag = 1;
			break;
		}
	}
	//�ж������Ƿ���Ҫ��0
	int rowFlag = 0;
	for (int j = 0; j<matrix[0].size(); j++)
	{
		if (matrix[0][j] == 0)
		{
			rowFlag = 1;
			break;
		}
	}
	//�������飬��ĳ��Ϊ0�������Ӧ�����к����е�λ�ñ��Ϊ0
	for (int i = 1; i<matrix.size(); i++)
		for (int j = 1; j<matrix[0].size(); j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}

	//�������У�����0��0����������
	for (int i = 1; i<matrix.size(); i++)
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 0; j<matrix[0].size(); j++)
				matrix[i][j] = 0;
		}
	}
	//�������У�����0��0����������
	for (int j = 1; j<matrix[0].size(); j++)
	{
		if (matrix[0][j] == 0)
		{
			for (int i = 0; i<matrix.size(); i++)
				matrix[i][j] = 0;
		}
	}
	//��colFlagΪ1��˵��������0����������0
	if (colFlag)
	{
		for (int i = 0; i<matrix.size(); i++)
			matrix[i][0] = 0;
	}
	//��rowFlagΪ1��˵��������0����������0
	if (rowFlag)
	{
		for (int j = 0; j<matrix[0].size(); j++)
			matrix[0][j] = 0;
	}
}