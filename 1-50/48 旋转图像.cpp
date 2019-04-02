#include<iostream>
#include<vector>
using namespace std;

// 48 ��תͼ��
/*
����һ�� n �� n �Ķ�ά�����ʾһ��ͼ��
��ͼ��˳ʱ����ת 90 �ȡ�
˵����
�������ԭ����תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫʹ����һ����������תͼ��
ʾ�� 1:
���� matrix =
[[1,2,3],[4,5,6],[7,8,9]],
ԭ����ת�������ʹ���Ϊ:
[[7,4,1],[8,5,2],[9,6,3]]
*/


//������Ŀ����Ҫ�ľ���Ҫ�۲죬��תһ��һ��չ��
//ÿһ���ѭ������������ÿһ��ѭ����Ҫ˳ʱ��ı��ĸ�λ�õ�ֵ
//�ص��������������Ĺ��̣�ȡ�ò�����ѭ������
void rotate(vector<vector<int>>& matrix) {
	int rotateRange = matrix.size() - 1;
	//��ת����Ϊ���������/2����Ϊż��û�����ģ���Ϊ�����м�һ�㲻�ñ�
	for (int i = 0; i<matrix.size() / 2; i++)
	{
		//������ת��ʼ��
		int startIndex1 = i;
		int startIndex2 = i;
		//ÿһ���ѭ������Ϊ����-1-2*i����һ��ѭ������-1�Σ��Դ�����
		for (int j = 0; j<matrix.size() - 2 * i - 1; j++)
		{
			//���н������ĸ�������һ���Ĺ�����ͨ��rotateRange��ʵ��ת��
			//rotateRange��һ����ֵ����������-1
			int temp = matrix[startIndex1][startIndex2];
			matrix[startIndex1][startIndex2] = matrix[rotateRange - startIndex2][startIndex1];
			matrix[rotateRange - startIndex2][startIndex1] = matrix[rotateRange - startIndex1][rotateRange - startIndex2];
			matrix[rotateRange - startIndex1][rotateRange - startIndex2] = matrix[startIndex2][rotateRange - startIndex1];
			matrix[startIndex2][rotateRange - startIndex1] = temp;
			startIndex2++;
		}
	}
}

int main()
{
	vector<vector<int>> vec = { {5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16} };
	rotate(vec);
	return 0;
}