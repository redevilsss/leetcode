#include<iostream>
#include<vector>
#include<string>
using namespace std;

//242 ��Ч����ĸ��λ��
/*
���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ��һ����ĸ��λ�ʡ�
ʾ�� 1:
����: s = "anagram", t = "nagaram"
���: true
*/

//�ܼ򵥵��⣬��һ��26λ����ͳ���ַ���s���ַ����ֵĴ��������ڱ������±�0-25�У��±�0�洢a���ֵĴ������Դ�����
//�ٱ����ַ���t�����ڵ��ַ���ͳ����������Ӧλ�õ�ֵ�м�1
//����жϵ�ǰ��ͳ�������Ƿ�ȫ0
bool isAnagram(string s, string t) {
	if (s.length() != t.length())
		return false;
	if (s.length() == 0)
		return true;
	vector<int> numsOfLetters(26, 0);
	for (int i = 0; i<s.length(); i++)
		numsOfLetters[s[i] - 'a']++;
	for (int i = 0; i<t.length(); i++)
		numsOfLetters[t[i] - 'a']--;
	for (int i = 0; i<26; i++)
	{
		if (numsOfLetters[i] != 0)
			return false;
	}
	return true;
}