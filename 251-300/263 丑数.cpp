#include<iostream>
#include<vector>
using namespace std;

//263 ����
/*
��дһ�������жϸ��������Ƿ�Ϊ������
��������ֻ���������� 2, 3, 5 ����������
ʾ�� 1:
����: 6
���: true
����: 6 = 2 �� 3
*/

bool isUgly(int num) {
	if (num<1)
		return false;
	while (num % 2 == 0)
		num /= 2;
	while (num % 3 == 0)
		num /= 3;
	while (num % 5 == 0)
		num /= 5;
	return num == 1;
}