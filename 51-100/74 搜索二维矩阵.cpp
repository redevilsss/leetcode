#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//74 ������ά����
/*
��дһ����Ч���㷨���ж� m x n �����У��Ƿ����һ��Ŀ��ֵ���þ�������������ԣ�
ÿ���е����������Ұ��������С�
ÿ�еĵ�һ����������ǰһ�е����һ��������
ʾ�� 1:
����:
matrix = [[1,   3,  5,  7],[10, 11, 16, 20],[23, 30, 34, 50]]
target = 3
���: true
*/

//�����ͽ�ָoffer��4�����ƣ��ܼ򵥵�˼�룬������ϸ����
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	int cols = matrix[0].size();
	int rows = matrix.size();
	int row = 0;
	int col = cols - 1;
	while (row<rows&&col >= 0)
	{
		if (matrix[row][col] == target)
			return true;
		else if (matrix[row][col]>target)
			col--;
		else
			row++;
	}
	return false;
}