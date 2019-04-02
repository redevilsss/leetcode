#include<iostream>
#include<string>
#include<vector>
using namespace std;


//6 Z���α任
/*
��һ�������ַ������ݸ������������Դ������¡������ҽ��� Z �������С�

���������ַ���Ϊ "LEETCODEISHIRING" ����Ϊ 3 ʱ���������£�

L   C   I   R
E T O E S I I G
E   D   H   N
֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"LCIRETOESIIGEDHN"��

����ʵ��������ַ�������ָ�������任�ĺ�����

string convert(string s, int numRows);
ʾ�� 1:
����: s = "LEETCODEISHIRING", numRows = 3
��� : "LCIRETOESIIGEDHN"

ʾ�� 2 :
���� : s = "LEETCODEISHIRING", numRows = 4
��� : "LDREOEIIECIHNTSG"
���� :
	L     D     R
	E   O E   I I
	E C   I H   N
	T     S     G
*/


//˼�룺��������һ��ѭ���������Ŀ��ƣ�������ʾ��2Ϊ��
//LEETCOΪһ��ѭ����һ��ѭ�����ַ���Ϊ����*2-2
//0-3ʱΪ���򣬶�4 5Ϊ����LEETCO�ֱ�����±�Ϊ 0 1 2 3 2 1����
//Ҳ����˵�����������ʵ���������
//������ʾ
string convert(string s, int numRows) {
	vector<string> vec(numRows);
	string res;
	int check = numRows * 2 - 2;
	for (int i = 0; i<s.length(); i++)
	{
		//��i��ѭ���е�λ��Ϊ0-numRows(����numRows)����ֱ��д������%ѭ������
		if (i%check<numRows)
			vec[i%check]+=s[i];
		else//������Ҫ����ѭ����-��ǰ�±�%ѭ������
			vec[check - i%check]+=s[i];

	}
	//�����ַ���
	for (int i = 0; i < numRows; i++)
		res += vec[i];
	return res;
	
}

int main()
{
	string s = "LEETCODEISHIRING";
	string res = convert(s, 3);
	return 0;
}