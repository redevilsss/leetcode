#include<iostream>
using namespace std;

//  9 ������
/*
�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������

ʾ�� 1:
����: 121
���: true
ʾ�� 2:
����: -121
���: false
����: �������Ҷ�, Ϊ -121 �� ���������, Ϊ 121- �����������һ����������
ʾ�� 3:
����: 10
���: false
����: ���������, Ϊ 01 �����������һ����������
*/

//����Ҫ֪���������϶����ǻ����������ų�
bool isPalindrome(int x) {
	if (x<0)
		return false;
	int res = 0;
	int temp = x;
	//�������7��һ������xΪ����ʱ�����䷴ת����ԭ���Ƿ�һ��
	while (temp)
	{
		res = res * 10 + temp % 10;
		temp /= 10;
	}
	if (res == x)
		return true;
	else
		return false;
}

int main()
{
	bool res = isPalindrome(121);
	return 0;
}