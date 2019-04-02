#include<iostream>
#include<vector>
using namespace std;

// 36 有效的数独
/*
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
*/


//思想，动态规划，用三个9*10的数组表示某一行某个数是否已经出现过
bool isValidSudoku(vector<vector<char>>& board) 
{
	vector<vector<bool>> row(9, vector<bool>(10, false));
	vector<vector<bool>> col(9, vector<bool>(10, false));
	vector<vector<bool>> block(9, vector<bool>(10, false));
	for (int i = 0; i<9; i++)
		for (int j = 0; j<9; j++)
		{
			if (board[i][j] != '.')//如果为不为点，说明已经加入数字，判断是否合理
			{
				int num = board[i][j] - '0';
				//如果三个数组中有一个该数已经出现过，就返回false
				if (row[i][num] || col[j][num] || block[i / 3 * 3 + j / 3][num])
					return false;
				else
				{
					//否则更新三个数组的值
					row[i][num] = true;
					col[j][num] = true;
					//行列好理解，这个方块的不好理解
					//因为是3*3的小方格，通过乘除可以实现划分
					//例[8,8]属于8/3*3+8/3=8，也就是第9个方块
					block[i / 3 * 3 + j / 3][num] = true;
				}
			}
		}
	return true;

}