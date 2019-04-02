#include<iostream>
#include<string>
#include<vector>
using namespace std;

//14 最长公共前缀
/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1:
输入: ["flower", "flow", "flight"]
输出 : "fl"

示例 2 :
输入 : ["dog", "racecar", "car"]
输出 : ""
解释 : 输入不存在公共前缀。
*/

//很简单的题，先列后行遍历字符串数组，比较不同字符串在相同下标下值是否相同
//若不相同则返回前缀，相等则加长前缀一位
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