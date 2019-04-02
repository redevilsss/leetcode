#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
#include<string>
using namespace std;

//290 单词模式

/*
给定一种 pattern(模式) 和一个字符串 str ，判断 str 是否遵循相同的模式。
这里的遵循指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应模式。
示例1:
输入: pattern = "abba", str = "dog cat cat dog"
输出: true
*/

//方法一：自己的渣渣方法
//首先把str字符串分割成单词,存放在数组s中
//然后以pattern[i]为键以s[i]为值进行一次插入，如果当前存在key值但是map[key]不等于当前的s[i],返回false，如果key值不存在则插入(pattern[i],s[i])
//再以以s[i]为键以pattern[i]为值进行一次插入,同上
//为什么要插入判断两次，因为要保证对应关系，需要a能映射到b，b也能映射到a
bool wordPattern(string pattern, string str) {
	if (pattern.length() == 0 && str.length() == 0)
		return true;
	if (pattern.length() == 0 || str.length() == 0)
		return false;
	vector<string> s;
	int i = 0, j = 0;
	for (; j<str.length(); j++)
	{
		if (str[j] == ' ')
		{
			string temp = str.substr(i, j - i);
			s.push_back(temp);
			i = j + 1;
		}
	}
	string temp = str.substr(i, j - i);
	s.push_back(temp);

	//判断长度是否相等
	if (s.size() != pattern.length())
		return false;
	unordered_map<char, string> check1;
	for (int i = 0; i<s.size(); i++)
	{
		if (check1.find(pattern[i]) != check1.end())
		{
			if (check1[pattern[i]] == s[i])
				continue;
			else
				return false;
		}
		else
			check1.insert(pair<char, string>(pattern[i], s[i]));
	}

	unordered_map<string, char> check2;
	for (int i = 0; i<s.size(); i++)
	{
		if (check2.find(s[i]) != check2.end())
		{
			if (check2[s[i]] == pattern[i])
				continue;
			else
				return false;
		}
		else
			check2.insert(pair<string, char>(s[i], pattern[i]));
	}
	return true;
}

//方法二：大佬的方法
//思路基本上都差不多
//这里用istringstream来实现分割...之前没接触过
//后序的处理用到了如下思想：
//将字母和单词分别映射成int，当某一对(char,string)出现时，分别修改当前map1中char的值和map2中string的值
//因为是顺序遍历，所以当char和string一一对应时，无论如何map1中char的值等于map2中string的值
//只要不一样，就说明这两者其中一个陷入了其他的对应关系，在两者不同时出现的某一次遍历中值被修改
bool wordPattern1(string pattern, string str) {
	unordered_map<char, int> p2i;
	unordered_map<string, int> w2i;
	istringstream in(str);
	int i = 0, n = pattern.size();
	for (string word; in >> word; i++)
	{
		if (i == n || p2i[pattern[i]] != w2i[word])
			return false;
		p2i[pattern[i]] = w2i[word] = i + 1;
	}
	return i == n;
}
/*
int main()
{
	string pattern = "abba";
	string str = "dog cat cat dog";
	bool res = wordPattern(pattern, str);
	return 0;
}
*/