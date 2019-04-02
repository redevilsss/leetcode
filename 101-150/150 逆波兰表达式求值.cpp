#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//150 波兰表达式求值

/*
根据逆波兰表示法，求表达式的值。
有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：
输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
*/

//这道题如果知道啥是逆波兰表达式就很简单...
//求逆波兰表达式的过程就是数字入栈，遇到符号弹出两个数字运算，结果再入栈，直到数组遍历完，栈顶元素就是结果（此时栈里面也就这一个元素）
//遇到数字就入栈，遇到符号就弹出两次计算，算完再把结果放回去
int evalRPN(vector<string>& tokens) {
	stack<int> s;
	for (int i = 0; i<tokens.size(); i++)
	{
		if (tokens[i] == "+")
		{
			int s1 = s.top();
			s.pop();
			int s2 = s.top();
			s.pop();
			s.push(s2 + s1);
		}
		else if (tokens[i] == "-")
		{
			int s1 = s.top();
			s.pop();
			int s2 = s.top();
			s.pop();
			s.push(s2 - s1);
		}
		else if (tokens[i] == "*")
		{
			int s1 = s.top();
			s.pop();
			int s2 = s.top();
			s.pop();
			s.push(s2*s1);
		}
		else if (tokens[i] == "/")
		{
			int s1 = s.top();
			s.pop();
			int s2 = s.top();
			s.pop();
			s.push(s2 / s1);
		}
		else
			s.push(stoi(tokens[i]));
	}
	return s.top();
} 