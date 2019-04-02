#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//130 被围绕的区域

/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
示例:
X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：
X X X X
X X X X
X X X X
X O X X
*/


//这题不能用常理来想，去找被围的O，要先找没被围的所有O，标记或者修改，这里选把O变成-
//然后把剩余的所有O都变成X，没被围的还原回来
//如何找到所有没被围的？需要深度优先遍历，从四周的O进入
//go数组的四个元素分别表示向左、向下、向右、向上
const vector<vector<int>> go = { {0,1}, {1,0} ,{ 0,-1 },{-1,0} };

void dfs(vector<vector<char>>& board, int x, int y)
{
	if (x >= board.size() || y >= board[0].size())
		return;
	if (board[x][y] == 'X' || board[x][y] == '-')
		return;
	if (board[x][y] == 'O')
		board[x][y] = '-';
	for(int i=0;i<4;i++)
		dfs(board,x+go[i][0],y+go[i][1]);
}
void solve(vector<vector<char>>& board) {
	
	if (board.size() == 0)
		return;
	//先对矩阵的四条边分别进行搜索，将所有未被围的O修改为-
	for (int j = 0; j < board[0].size(); j++)//对第一行和最后一行进行搜索
	{
		if (board[0][j] == 'O')
			dfs(board,0, j);
		if (board[board.size() - 1][j] == 'O')
			dfs(board, board.size() - 1, j);
	}
	for (int i = 0; i < board.size(); i++)//对第一列和最后一列进行搜索
	{
		if (board[i][0] == 'O')
			dfs(board, i, 0);
		if (board[i][board[0].size()-1] == 'O')
			dfs(board, i,board.size() - 1);
	}
	//此时只有被围的O还是O，未被围的O都变成了-，分别将其修改
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] == 'O')
				board[i][j] = 'X';
			else if (board[i][j] == '-')
				board[i][j] = 'O';
		}
}

int main()
{
	vector<vector<char>> vec = { {'X','O','X' },{ 'O','X','O'} ,{ 'X','O','X' } };
	solve(vec);
	return 0;
}


