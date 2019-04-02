#include<iostream>
#include<vector>
#include<string>
using namespace std;

//28 实现strStr()

/*
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1
*/
//这个题用传统的匹配方法是没有任何难度的，针对字符串匹配问题，要学好KMP算法
//后面要写KMP算法实现匹配

int strStr(string haystack, string needle) {
	//匹配串为空返回0
	if (needle.size() == 0)
		return 0;
	//匹配串大于原串返回-1
	if (needle.size()>haystack.size())
		return -1;
	//原串循环
	for (int i = 0; i<haystack.length(), haystack.size() - i >= needle.size(); i++)
	{
		//如果原串某字符等于匹配串第一个字符，进入匹配，否则直接下一个
		if (haystack[i] == needle[0])
		{
			int j = 1;
			//进行匹配，如果匹配不成功break，根据j值判断是否成功
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