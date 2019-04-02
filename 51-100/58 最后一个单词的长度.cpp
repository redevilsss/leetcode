#include<iostream>
#include<string>
using namespace std;

//58 最后一个单词的长度

/*
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
如果不存在最后一个单词，请返回 0 。
说明：一个单词是指由字母组成，但不包含任何空格的字符串。
示例:
输入: "Hello World"
输出: 5
*/
//倒序遍历，找第一个字符，再遍历，找第一个空格，第一个字符的下标减第一个空格的下标就是最后一个单词的长度

int lengthOfLastWord(string s) {
	int l = s.length();
	int i = l - 1;
	while (i >= 0 && s[i] == ' ')//i表示倒数第一个不是空格的下标
		i--;
	int j = i;
	while (j >= 0 && s[j] != ' ')
		j--;
	return i - j;
}