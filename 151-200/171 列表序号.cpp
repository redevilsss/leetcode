#include<iostream>
#include<string>
using namespace std;

//171 �б����
/*
����һ��Excel����е������ƣ���������Ӧ������š�
���磬
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
*/

//��168������һ�ԣ�һ��������ת�ַ���һ�����ַ���ת����
//��ΪA��Ӧ����1������-Aת�����ֺ�Ҫ+1����������
long titleToNumber(string s)
{
	long num = s[0] - 'A' + 1;
	for (int i = 1; i<s.length(); i++)
	{
		num = num * 26 + s[i] - 'A' + 1;
	}
	return num;
}
