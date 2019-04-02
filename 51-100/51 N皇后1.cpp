#include<iostream>
#include<vector>
#include<string>
using namespace std;

//51 N皇后1

/*
皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给定一个整数 n，返回 n 皇后不同的解决方案的数量。
示例:
输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[[".Q..", "...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
*/

//思路：用递归来做
//需要额外的空间来记录该位置是否可以放置皇后，构造三个数组分别表示列，对角线和反对角线的放置情况
//行是由遍历控制的，每一行只会找一个位置放皇后
//index用来记录当前放置到的行数

vector<vector<string>> res;
vector<int> visitedCol;
vector<int> visitedDia1;
vector<int> visitedDia2;
vector<vector<string>> solveNQueens(int n)
{
	visitedCol.resize(n);
	visitedDia1.resize(2 * n - 1);//15个对角线 左上到右下
	visitedDia2.resize(2 * n - 1);//15个反对角线 左下到右上
	vector<int> temp;
	dfs(temp, 0, n);
	return res;
}
void dfs(vector<int>& temp, int index, int n)//index表示目前匹配到了第几行，不能忽略
{
	if (index == n)
	{
		vector<string> board(n, string(n, '.'));
		for (int i = 0; i<n; i++)
			board[i][temp[i]] = 'Q';
		res.push_back(board);
		return;
	}
	for (int i = 0; i<n; i++)//i表示列，也就是说这个循环针对的是第index行第i列，对这个位置能不能放进行判断，能放就放，不能放就看下一个位置
		if (!visitedCol[i] && !visitedDia1[index + i] && !visitedDia2[index - i + n - 1])
		{
			temp.push_back(i);
			visitedCol[i]++;
			visitedDia1[index + i]++;//行数加列数
			visitedDia2[index - i + n - 1]++;//行数加（总列数-1-列数）
			dfs(temp, index + 1, n);
			visitedCol[i]--;
			visitedDia1[index + i]--;
			visitedDia2[index - i + n - 1]--;
			temp.pop_back();
		}
	return;
}