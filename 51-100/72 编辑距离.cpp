#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//72 编辑距离
/*
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符、删除一个字符、替换一个字符
示例 1:
输入: word1 = "horse", word2 = "ros"
输出: 3
解释:
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
*/

//这道题还是有难度，一开始没有想到用动态规划去解而是想如何匹配
//但是从匹配的角度入手太那难去向，如果使用动态规划构造一个二维数组
//一步步来进行分析递推保证每一次转化的操作数最小，最终获得结果
int minDistance(string word1, string word2) {
	int m = word1.length();
	int n = word2.length();
	/**
	dp[i][j] 表示 使word1 的第 [1~i] 位和 word2 的 [1~j] 位相同
	所需的最少操作数. 则递推式为:
	if(word1[i] == word2[j])
	dp[i][j] = dp[i-1][j-1]
	else
	dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
	**/
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	// 边界情况, 将一个字符串转换成空字符串的操作
	for (int i = 1; i <= m; i++) dp[i][0] = i;
	for (int i = 1; i <= n; i++) dp[0][i] = i;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (word1[i - 1] == word2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;

		}
	}
		
	return dp[m][n];

}