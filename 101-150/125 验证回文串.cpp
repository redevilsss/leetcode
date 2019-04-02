#include<iostream>
#include<vector>
#include<string>
using namespace std;

//125 ��֤���Ĵ�

/*
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
ʾ�� 1:
����: "A man, a plan, a canal: Panama"
���: true
*/


//˫ָ�룬һ����ͷ��ʼ��һ����β��ʼ���Ƚ��ַ����Ĵ�д��ĸ�����
//�����Ƚϵ�ǰbegin����λ�ú�end����λ���Ƿ���ȣ���������ĸ������Ҫ����
//����Ⱦ�ֱ�ӷ���false
bool isPalindrome(string s) {
	int begin = 0;
	int end = s.length() - 1;
	for (int i = 0; i<s.length(); i++)
	{
		if (s[i] <= 'Z'&&s[i] >= 'A')
			s[i] = tolower(s[i]);
	}
	while (begin<end)
	{
		while (begin<end && (s[begin]<48 || (s[begin]>57 && s[begin]<65) || (s[begin]<97 && s[begin]>90) || (s[begin]>122)))
			begin++;
		while (begin<end && (s[end]<48 || (s[end]>57 && s[end]<65) || (s[end]<97 && s[end]>90) || (s[end]>122)))
			end--;
		if (s[begin] != s[end])
			return false;
		begin++;
		end--;
	}
	return true;
}

int main()
{
	string s = "A man, a plan, a canal : Panama";
	bool res = isPalindrome(s);
	return 0;
}