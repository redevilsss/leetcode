#include<iostream>
#include<vector>
using namespace std;

//59 螺旋矩阵2

/*
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
示例:
输入: 3
输出:
[[ 1, 2, 3 ],[ 8, 9, 4 ],[ 7, 6, 5 ]]
*/

//思路：和54题打印的顺序基本一样，也是一层一层，每一层从当前层的左上开始
//我只需要创建矩阵，设置初始值为1，按照打印顺序赋值，每赋一次，设置的值加1
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> res(n, vector<int>(n));
	int start = 0;
	int temp = 0;
	while (n>start * 2 && n>start * 2)
	{
		int endX = n - 1 - start;
		int endY = n - 1 - start;
		for (int i = start; i <= endX; i++)
			res[start][i] = ++temp;
		if (start<endY)
		{
			for (int i = start + 1; i <= endY; i++)
				res[i][endX] = ++temp;
		}
		if (start<endX&&start<endY)
		{
			for (int i = endX - 1; i >= start; --i)
				res[endY][i] = ++temp;
		}
		if (start<endX&&start<endY - 1)
		{
			for (int i = endY - 1; i >= start + 1; i--)
				res[i][start] = ++temp;
		}
		++start;
	}
	return res;
}