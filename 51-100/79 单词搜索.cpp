#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//79 单词搜索

/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
示例:
board =[['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.
*/

//方法一：//类似于剑指offer第12题，但是这个代码比较繁杂，在选择下一步时没有取舍，运算效率差
bool hasPath(vector<vector<char>>& board, int rows, int cols, int row, int col, const string str, int& pathLength, vector<vector<bool>>& visited);

bool exist(vector<vector<char>>& board, string word) {
	if (board.size() == 0 || board[0].size() == 0)
		return false;
	int rows = board.size();
	int cols = board[0].size();
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	int pathLength = 0;//记录当前匹配长度
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			if (hasPath(board, rows, cols, i, j, word, pathLength, visited))
				return true;
		}
	}
	return false;
}

bool hasPath(vector<vector<char>>& board, int rows, int cols, int row, int col, const string str, int& pathLength, vector<vector<bool>>& visited)
{
	if (str[pathLength] == '\0')
		return true;
	bool flag = false;
	if (row>=0 && row<rows&&col>=0 && col<cols && 
		!visited[row][col] && str[pathLength] == board[row][col])
	{
		++pathLength;
		visited[row][col] = true;
		flag = hasPath(board, rows, cols, row - 1, col, str, pathLength, visited) ||
			hasPath(board, rows, cols, row + 1, col, str, pathLength, visited) || 
			hasPath(board, rows, cols, row, col - 1, str, pathLength, visited) || 
			hasPath(board, rows, cols, row, col + 1, str, pathLength, visited);
		if (!flag)
		{
			--pathLength;
			visited[row][col] = false;
		}
	}
	return flag;
}







//方法二 构造一个go矩阵用于改变当前坐标，四行分别对应下右上左
//遍历四次看每次操作后能否继续匹配字符串的下一个字符，如果可以，递归，否则看下一个
int go[4][2] = { 1, 0, 0, 1, -1, 0, 0 ,-1 };//go数组表示向下、向右、向上、向左时的坐标变化情况
int m, n;
vector<vector<char>> Board;//定义成全局变量
string Word;//同上
vector<vector<int>> visited;
//遍历，idx用于存储当前匹配的单词长度，如果此时该点的上下左右其中一个的值等于字符串下一个字符，就继续遍历
bool dfs(int r, int c, int idx) {
	if (idx == Word.length())//此时说明匹配完成，返回true
		return true;
	int tr, tc;//当前坐标
			   //这个符号用来标记匹配开始的地方，ch用来保存当前匹配下标的上一个字符，类似于上面的visited数组但是要简单很多，
			   //边匹配边调换位置，当某一位匹配上时，通过swap交换此时的元素和其前一个元素，避免其走回头路
	for (int i = 0; i < 4; i++) {
		tr = r + go[i][0];
		tc = c + go[i][1];
		//可以继续匹配
		if (tr >= 0 && tc >= 0 && tr<m && tc<n && Board[tr][tc] == Word[idx] && visited[tr][tc] == 0) {
			visited[tr][tc]++;
			if (dfs(tr, tc, idx + 1))
				return true;
			visited[tr][tc]--;//否则退回到上一步
		}
	}
	return false;
}
bool exist(vector<vector<char>>& board, string word) {
	Board = board;
	Word = word;
	m = Board.size(), n = Board[0].size();
	//初始化visited数组
	visited.resize(m);
	for (int i = 0; i < m; i++)
		visited[i].resize(n);
	visited[0].resize(n);
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			visited[i][j] = 0;
	//遍历找某坐标处等于字符串第一个数，若找到，则在visited标记并进入递归
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (Board[i][j] == Word[0] && visited[i][j] == 0) {
				visited[i][j]++;
				if (dfs(i, j, 1))
					return true;
				visited[i][j]--;
			}
	return false;
}
int main()
{
	vector<vector<char>> vec = { {'A','B','C','E'}, { 'S','F','C','S' }, { 'A','D','E','E' } };
	string str = "ABCCED";
	bool res = exist(vec, str);
	return 0;
}