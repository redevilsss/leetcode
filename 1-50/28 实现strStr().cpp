#include<iostream>
#include<vector>
#include<string>
using namespace std;

//28 ʵ��strStr()

/*
����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��
ʾ�� 1:
����: haystack = "hello", needle = "ll"
���: 2

ʾ�� 2:
����: haystack = "aaaaa", needle = "bba"
���: -1
*/
//������ô�ͳ��ƥ�䷽����û���κ��Ѷȵģ�����ַ���ƥ�����⣬Ҫѧ��KMP�㷨
//����ҪдKMP�㷨ʵ��ƥ��

int strStr(string haystack, string needle) {
	//ƥ�䴮Ϊ�շ���0
	if (needle.size() == 0)
		return 0;
	//ƥ�䴮����ԭ������-1
	if (needle.size()>haystack.size())
		return -1;
	//ԭ��ѭ��
	for (int i = 0; i<haystack.length(), haystack.size() - i >= needle.size(); i++)
	{
		//���ԭ��ĳ�ַ�����ƥ�䴮��һ���ַ�������ƥ�䣬����ֱ����һ��
		if (haystack[i] == needle[0])
		{
			int j = 1;
			//����ƥ�䣬���ƥ�䲻�ɹ�break������jֵ�ж��Ƿ�ɹ�
			for (; j<needle.size(); j++)
			{
				if (haystack[i + j] != needle[j])
					break;
			}
			if (j == needle.size()) return i;
		}
	}
	return -1;

}