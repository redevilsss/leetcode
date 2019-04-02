#include<iostream>
#include<vector>
using namespace std;
// 22 括号生成

/*给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
例如，给出 n = 3，生成结果为：
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

//思想：dfs+剪枝
vector<string> generateParenthesis(int n) {
	vector<string> res;
	func(res, "", 0, 0, n);
	return res;
}
//l表示当前左括号数，r表示当前右括号数，n表示括号对数
void func(vector<string>& res, string str, int l, int r, int n)
{
	//左括号大于n、右括号大于n、右括号大于左括号（无效）都退出，不符合条件，
	if (l>n || r>n || r>l)
		return;
	if (l == n&&r == n)//左右括号都为n个时，压入此时str，回溯
	{
		res.push_back(str);
		return;
	}
	//分别递归载入新的函数过程，加左括号则l加1，加右括号则r加1
	func(res, str + '(', l + 1, r, n);
	func(res, str + ')', l, r + 1, n);
	return;