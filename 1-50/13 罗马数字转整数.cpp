#include<iostream>
#include<string>
#include<vector>
using namespace std;

//13 ��������ת����

/*
�������ְ������������ַ�: I�� V�� X�� L��C��D �� M��
�ַ�          ��ֵ
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
���磬 �������� 2 д�� II ����Ϊ�������е� 1��12 д�� XII ����Ϊ X + II �� 27 д��  XXVII, ��Ϊ XX + V + II ��
ͨ������£�����������С�������ڴ�����ֵ��ұߡ�
��Ҳ�������������� 4 ��д�� IIII������ IV������ 1 ������ 5 ����ߣ�����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��
ͬ���أ����� 9 ��ʾΪ IX���������Ĺ���ֻ�������������������
I ���Է��� V (5) �� X (10) ����ߣ�����ʾ 4 �� 9��
X ���Է��� L (50) �� C (100) ����ߣ�����ʾ 40 �� 90��
C ���Է��� D (500) �� M (1000) ����ߣ�����ʾ 400 �� 900��
����һ���������֣�����ת��������������ȷ���� 1 �� 3999 �ķ�Χ�ڡ�

ʾ�� 1:
����: "III"
���: 3

ʾ�� 2:
����: "IV"
���: 4

ʾ�� 3:
����: "IX"
���: 9

ʾ�� 4:
����: "LVIII"
���: 58
����: L = 50, V= 5, III = 3.

ʾ�� 5:
����: "MCMXCIV"
���: 1994
����: M = 1000, CM = 900, XC = 90, IV = 4.
*/

//����һ
int romanToInt(string s) {
	int res = 0;
	int i = 0;
	//�����ַ�����ֵ
	while (i<s.length())
	{
		//���г������������ʱ��ȡֵ
		if (s[i] == 'I'&&s[i + 1] == 'V')
		{
			res += 4;
			i += 2;
		}
		else if (s[i] == 'I'&&s[i + 1] == 'X')
		{
			res += 9;
			i += 2;
		}
		else if (s[i] == 'X'&&s[i + 1] == 'L')
		{
			res += 40;
			i += 2;
		}
		else if (s[i] == 'X'&&s[i + 1] == 'C')
		{
			res += 90;
			i += 2;
		}
		else if (s[i] == 'C'&&s[i + 1] == 'D')
		{
			res += 400;
			i += 2;
		}
		else if (s[i] == 'C'&&s[i + 1] == 'M')
		{
			res += 900;
			i += 2;
		}
		//���о�һ�����
		else switch (s[i])
		{
		case 'I':res += 1; i += 1; break;
		case 'V':res += 5; i += 1; break;
		case 'X':res += 10; i += 1; break;
		case 'L':res += 50; i += 1; break;
		case 'C':res += 100; i += 1; break;
		case 'D':res += 500; i += 1; break;
		case 'M':res += 1000; i += 1; break;
		}

	}
	return res;
}

//���������������뷽��һû�б����ϵĲ�𣬷���һ���߱��㣬�������ȴ���㣬���������
int romanToInt(string s)
{
	int n[s.size() + 1];
	n[s.size()] = 0;
	int res = 0;
	for (int i = 0; i<s.length(); i++)
	{
		switch (s[i])
		{
		case 'I':n[i] = 1;   break;
		case 'V':n[i] = 5;   break;
		case 'X':n[i] = 10;  break;
		case 'L':n[i] = 50;  break;
		case 'C':n[i] = 100; break;
		case 'D':n[i] = 500; break;
		case 'M':n[i] = 1000; break;
		}
	}
	//�Գ���4 �� 9�Ĵ������Ƚϼ��������񷽷�1һ�����ӣ��и����� 
	for (int i = 0; i<s.length(); i++)
	{
		if (n[i]<n[i + 1])
		{
			res = res + n[i + 1] - n[i];
			i++;
		}
		else
			res += n[i];
	}
	return res;
}