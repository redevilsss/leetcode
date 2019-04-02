#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//74 搜索二维矩阵
/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例 1:
输入:
matrix = [[1,   3,  5,  7],[10, 11, 16, 20],[23, 30, 34, 50]]
target = 3
输出: true
*/

//这道题和剑指offer第4题类似，很简单的思想，不做详细描述
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	int cols = matrix[0].size();
	int rows = matrix.size();
	int row = 0;
	int col = cols - 1;
	while (row<rows&&col >= 0)
	{
		if (matrix[row][col] == target)
			return true;
		else if (matrix[row][col]>target)
			col--;
		else
			row++;
	}
	return false;
}