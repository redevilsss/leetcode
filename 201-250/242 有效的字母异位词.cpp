#include<iostream>
#include<vector>
#include<string>
using namespace std;

//242 有效的字母异位词
/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。
示例 1:
输入: s = "anagram", t = "nagaram"
输出: true
*/

//很简单的题，用一个26位数组统计字符串s中字符出现的次数，对于保存在下标0-25中，下标0存储a出现的次数，以此类推
//再遍历字符串t，对于的字符在统计数组中相应位置的值中减1
//最后判断当前的统计数组是否全0
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