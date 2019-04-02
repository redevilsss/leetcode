#include<iostream>
#include<vector>
using namespace std;

//240 搜索二维矩阵2


/*
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：
每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:
现有矩阵 matrix 如下：
[
[1,   4,  7, 11, 15],
[2,   5,  8, 12, 19],
[3,   6,  9, 16, 22],
[10, 13, 14, 17, 24],
[18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。
给定 target = 20，返回 false。
*/

/*
很简单的一道题，水平从右到左，竖直方向从上到下，取当前元素和target比较
比较的大小不同下一步的去向不同，当水平到最左而竖直到最下方时仍未找到则说明不存在
某一时刻的值等于target则说明存在返回true
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	bool res = false;
	int cols = matrix[0].size();
	int rows = matrix.size();
	int row = 0;
	int col = cols - 1;
	while (col >= 0 && row<rows)
	{
		if (matrix[row][col] == target)
		{
			res = true;
			break;
		}
		else if (matrix[row][col]>target)
			col--;
		else
			row++;
	}
	return res;
}