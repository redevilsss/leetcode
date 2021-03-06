#include<iostream>
#include<string>
#include<vector>
using namespace std;

//10 正则表达式匹配
/*
给定一个字符串(s) 和一个字符模式(p)。实现支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的元素。
匹配应该覆盖整个字符串(s) ，而不是部分字符串。

说明 :

s 可能为空，且只包含从 a - z 的小写字母。
p 可能为空，且只包含从 a - z 的小写字母，以及字符.和 *。
示例 1 :
输入 :
s = "aa"
p = "a"
输出 : false
解释 : "a" 无法匹配 "aa" 整个字符串。

示例 2 :
输入 :
s = "aa"
p = "a*"
输出 : true
解释 : '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。

示例 3 :
输入 :
s = "ab"
p = ".*"
输出 : true
解释 : ".*" 表示可匹配零个或多个('*')任意字符('.')

示例 4 :
输入 :
s = "aab"
p = "c*a*b"
输出 : true
解释 : 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"

示例 5 :
输入 :
s = "mississippi"
p = "mis*is*p*."
输出 : false
*/

//这个题算是比较难的题目，第一次拿到的时候还是没什么思路，与剑指offer中的第20题类似
//但是那里使用递归来做，这里直接用动态规划会比较快
//具体的细节已经做了较为详细的注解，不再重复
bool isMatch(string s, string p) {
	int sl = s.size(), pl = p.size();
	vector<vector<bool> > dp(sl + 1, vector<bool>(pl + 1, false));//向量的行数和列数分别比原串 和匹配串长度大1
	dp[0][0] = true;
	for (int i = 0; i <= sl; i++) {
		for (int j = 1; j <= pl; j++) {
			if (j>1 && p[j - 1] == '*')
				//此时p[j-1]为*，有如下几种情况：
				//1.dp[i][j-2]保存着匹配至原串下标i-1和匹配串下标j-3时的结果，如果该结果为真，匹配到原串下标i-1和匹配串下标j-1时也为真
				//举例：           原串：      a    |       匹配串：            a     |   *
				//                         第i-1位 |                         第j-2位 | 第j-1位
				//说明：此时*只匹配了它前面的字符1次，即直接越过*所在位置
				//2.dp[i-1][j]保存着匹配至原串下标i-2和匹配串下标j-1时的结果，若该结果为真，同时
				//原串下标i-1的值等于匹配串j-2处的值，或者匹配串j-2处为'.'，匹配到原串下标i-1和匹配串下标j-1时也为真
				//举例1：      原串： |     a           匹配串：             a         *    |
				//                   |  第i-1位                          第j-2位  第j-1位   |
				//举例2：      原串： |     a           匹配串：             .         *     |
				//                   |  第i-1位                          第j-2位  第j-1位   |
				//说明：举例1和举例2中，又把*前面的元素匹配了一遍
				dp[i][j] = dp[i][j - 2] || (i>0 && (p[j - 2] == '.' || s[i - 1] == p[j - 2]) && dp[i - 1][j]);
			else dp[i][j] = i>0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
			//举例1：           原串：      X    |    a              匹配串：             X   |  a 
			//                          第i-2位 |  第i-1位                           第j-2位 | 第j-1位
			//举例2：           原串：      X    |    任意           匹配串：             X   |  . 
			//                          第i-2位 |  第i-1位                           第j-2位 | 第j-1位
		}
	}
	return dp[sl][pl];//dp[s1][p1]表示匹配至原串下标s1-1和匹配串下标p1-1时的结果，
}