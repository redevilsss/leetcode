#include<iostream>
#include<vector>
using namespace std;

//240 ������ά����2


/*
��дһ����Ч���㷨������ m x n ���� matrix �е�һ��Ŀ��ֵ target���þ�������������ԣ�
ÿ�е�Ԫ�ش������������С�
ÿ�е�Ԫ�ش��ϵ����������С�
ʾ��:
���о��� matrix ���£�
[
[1,   4,  7, 11, 15],
[2,   5,  8, 12, 19],
[3,   6,  9, 16, 22],
[10, 13, 14, 17, 24],
[18, 21, 23, 26, 30]
]
���� target = 5������ true��
���� target = 20������ false��
*/

/*
�ܼ򵥵�һ���⣬ˮƽ���ҵ�����ֱ������ϵ��£�ȡ��ǰԪ�غ�target�Ƚ�
�ȽϵĴ�С��ͬ��һ����ȥ��ͬ����ˮƽ���������ֱ�����·�ʱ��δ�ҵ���˵��������
ĳһʱ�̵�ֵ����target��˵�����ڷ���true
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	bool res = false;
	int cols = matrix[0].size();
	int rows = matrix.size();
	int row = 0;
	int col = cols - 1;
	while (col >= 0 && row<rows)
	{
		if (matrix[row][col] == target)
		{
			res = true;
			break;
		}
		else if (matrix[row][col]>target)
			col--;
		else
			row++;
	}
	return res;
}