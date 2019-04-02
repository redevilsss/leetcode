#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//151 翻转字符串里的单词

/*
给定一个字符串，逐个翻转字符串中的每个单词。
示例 1：
输入: "the sky is blue"
输出: "blue is sky the"
示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
*/


//剑指offer中有类似的题
//思路：
// 1.翻转整个链表
// 2.遍历链表，翻转每个单词（由两个指针控制单词的首尾）并加在设置的初始值为空的结果字符串中

//翻转字符串s的begin到end
void reverse(int begin, int end, string& s)
{
	while (begin < end)
	{
		int temp = s[begin];
		s[begin] = s[end];
		s[end] = temp;
		begin++;
		end--;
	}
}

string reverseWords(string s)
{
	if (s.length() == 0)
		return "";
	//翻转整个字符串
	reverse(0, s.length() - 1, s);
	string res;
	int left = 0;
	int right = 0;
	int end = s.length();
	while (left<end)
	{
		//跳过空格找到下一个非空字符
		while (left<end&&s[left] == ' ')
			left++;
		//如果到达末尾，直接退出
		if (left == end)
			break;
		//设置right，继续前进找下一个空格
		right = left;
		while (right<end&&s[right] != ' ')
			right++;
		//left到right-1之间的字符组成一个单词（不包含空格），right此时指向空格，right-1为单词最后一个字母，将单词翻转
		reverse(left, right - 1,s);
		string subS = s.substr(left, right - left);//取出单词
		res += subS + ' ';//逐步构造新字符串
		left = right;//设置新left值
	}
	return res.substr(0,res.size()-1);

}
int main()
{
	string s = "  hello world!    ";
	string res = reverseWords(s);
	return 0;
}