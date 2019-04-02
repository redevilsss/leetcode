#include<iostream>
#include<vector>
#include<string>
using namespace std;

//125 验证回文串

/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true
*/


//双指针，一个从头开始，一个从尾开始，先将字符串的大写字母处理掉
//遍历比较当前begin所在位置和end所在位置是否相等，遇到非字母或数字要跳过
//不相等就直接返回false
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