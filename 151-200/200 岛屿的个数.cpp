#include<iostream>
#include<vector>
using namespace std;

//200 岛屿的个数

/*
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
示例 1:
输入:
11110
11010
11000
00000
输出: 1
*/

/*遇到这种涉及到元素之间位置关系（比如定义的岛啊，还有之前有道题里面的被包围的元素啊），首先要考虑的就是递归
其实就是一个标记的过程，如何实现功能因题而异，但是思想无非就是找，然后标记，然后回主函数做下一步的处理
这道题也是一样，对每个元素进行遍历，如果当前元素为1，将从这个元素开始的相连的所有元素都置为0，
然后回到主函数将岛屿数+1，这其实就是一个数的过程，数完了当然要置0不然会再数一边的，题很简单，主要是思路
之前看到有人把定义的函数称为infect函数，很贴切，就像感染一样，只要有1相连的地方全部变成0，
此时矩阵中岛的个数少了一个，而当前记录的岛数+1
*/
int numIslands(vector<vector<char>>& grid) {
	if (grid.size() == 0 || grid[0].size() == 0)
		return 0;
	int res = 0;
	int rows = grid.size();
	int cols = grid[0].size();
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			if (grid[i][j] == '1')
			{
				infect(grid, i, j);
				res++;
			}
		}
	}
	return res;
}

void infect(vector<vector<char>>& grid, int row, int col)
{
	if (row<0 || row >= grid.size() || col<0 || col >= grid[0].size() || grid[row][col] != '1')
		return;
	grid[row][col] = '0';
	infect(grid, row - 1, col);
	infect(grid, row + 1, col);
	infect(grid, row, col - 1);
	infect(grid, row, col + 1);
}

int main()
{
	vector<vector<char>> vec = { {'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'} };
	int res = numIslands(vec);
	return 0;
}