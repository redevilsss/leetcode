#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//130 ��Χ�Ƶ�����

/*
����һ����ά�ľ��󣬰��� 'X' �� 'O'����ĸ O����
�ҵ����б� 'X' Χ�Ƶ����򣬲�����Щ���������е� 'O' �� 'X' ��䡣
ʾ��:
X X X X
X O O X
X X O X
X O X X
������ĺ����󣬾����Ϊ��
X X X X
X X X X
X X X X
X O X X
*/


//���ⲻ���ó������룬ȥ�ұ�Χ��O��Ҫ����û��Χ������O����ǻ����޸ģ�����ѡ��O���-
//Ȼ���ʣ�������O�����X��û��Χ�Ļ�ԭ����
//����ҵ�����û��Χ�ģ���Ҫ������ȱ����������ܵ�O����
//go������ĸ�Ԫ�طֱ��ʾ�������¡����ҡ�����
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
	//�ȶԾ���������߷ֱ����������������δ��Χ��O�޸�Ϊ-
	for (int j = 0; j < board[0].size(); j++)//�Ե�һ�к����һ�н�������
	{
		if (board[0][j] == 'O')
			dfs(board,0, j);
		if (board[board.size() - 1][j] == 'O')
			dfs(board, board.size() - 1, j);
	}
	for (int i = 0; i < board.size(); i++)//�Ե�һ�к����һ�н�������
	{
		if (board[i][0] == 'O')
			dfs(board, i, 0);
		if (board[i][board[0].size()-1] == 'O')
			dfs(board, i,board.size() - 1);
	}
	//��ʱֻ�б�Χ��O����O��δ��Χ��O�������-���ֱ����޸�
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


