#include<iostream>
#include<stack>
#include<string>
using namespace std;
// 20  有效的括号

/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出 : true

示例 2 :
输入 : "()[]{}"
输出 : true

示例 3 :
输入 : "(]"
输出 : false

示例 4 :
输入 : "([)]"
输出 : false

示例 5 :
输入 : "{[]}"
输出 : true
*/

//核心思想：用栈的压入弹出来模拟判断过程，遇到相同的就弹出，看最终栈是不是为空
bool isValid(string s) {
	if (s.size() == 0)
		return true;
	//若元素个数为奇数个，肯定无效
	if (s.size() % 2 != 0)
		return false;
	stack<char> temp;
	//遍历元素，进行判断
	for (int i = 0; i<s.size(); i++)
	{
		//分为栈空和非空两种情况，栈空是只能进左括号，否则报错
		int flag = temp.empty();
		if (flag)
		{
			if (s[i] == '}' || s[i] == ']' || s[i] == ')')
				return false;
			else
				temp.push(s[i]);
		}
		//栈非空时要判断下一个元素是否与栈顶元素配对，配对则弹出栈顶元素，否则压入下一个元素
		else
		{
			if (temp.top() == '['&&s[i] == ']')
				temp.pop();
			else if (temp.top() == '('&&s[i] == ')')
				temp.pop();
			else if (temp.top() == '{'&&s[i] == '}')
				temp.pop();
			else
				temp.push(s[i]);
		}
	}
	return temp.empty();
}

int main()
{
	string s = "()";
	bool res = isValid(s);
	return 0;
}
