#include<iostream>
#include<vector>
using namespace std;

//200 ����ĸ���

/*
����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά���񣬼��㵺���������һ������ˮ��Χ����������ͨ��ˮƽ�����ֱ���������ڵ�½�����Ӷ��ɵġ�����Լ���������ĸ��߾���ˮ��Χ��
ʾ�� 1:
����:
11110
11010
11000
00000
���: 1
*/

/*���������漰��Ԫ��֮��λ�ù�ϵ�����綨��ĵ���������֮ǰ�е�������ı���Χ��Ԫ�ذ���������Ҫ���ǵľ��ǵݹ�
��ʵ����һ����ǵĹ��̣����ʵ�ֹ���������죬����˼���޷Ǿ����ң�Ȼ���ǣ�Ȼ�������������һ���Ĵ���
�����Ҳ��һ������ÿ��Ԫ�ؽ��б����������ǰԪ��Ϊ1���������Ԫ�ؿ�ʼ������������Ԫ�ض���Ϊ0��
Ȼ��ص���������������+1������ʵ����һ�����Ĺ��̣������˵�ȻҪ��0��Ȼ������һ�ߵģ���ܼ򵥣���Ҫ��˼·
֮ǰ�������˰Ѷ���ĺ�����Ϊinfect�����������У������Ⱦһ����ֻҪ��1�����ĵط�ȫ�����0��
��ʱ�����е��ĸ�������һ��������ǰ��¼�ĵ���+1
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