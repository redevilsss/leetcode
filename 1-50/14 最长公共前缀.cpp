#include<iostream>
#include<string>
#include<vector>
using namespace std;

//14 �����ǰ׺
/*
��дһ�������������ַ��������е������ǰ׺��
��������ڹ���ǰ׺�����ؿ��ַ��� ""��

ʾ�� 1:
����: ["flower", "flow", "flight"]
��� : "fl"

ʾ�� 2 :
���� : ["dog", "racecar", "car"]
��� : ""
���� : ���벻���ڹ���ǰ׺��
*/

//�ܼ򵥵��⣬���к��б����ַ������飬�Ƚϲ�ͬ�ַ�������ͬ�±���ֵ�Ƿ���ͬ
//������ͬ�򷵻�ǰ׺�������ӳ�ǰ׺һλ
string longestCommonPrefix(vector<string>& strs)
{
	string res;
	if (strs.size() == 0)
		return res;
	for (int j = 0; j<strs[0].size(); j++)
	{
		char src = strs[0][j];
		int i = 1;
		for (; i<strs.size(); i++)
		{
			if (strs[i].size() <= j || strs[i][j] != src)
				return res;
		}
		res += src;
	}
	return res;

}