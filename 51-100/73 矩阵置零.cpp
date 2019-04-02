#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//73 矩阵置0
/*
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
示例 1:
输入:
[[1,1,1],[1,0,1],[1,1,1]]
输出:
[[1,0,1],[0,0,0],[1,0,1]]
*/



//这道题拿到手里的时候也是没想到看了别人的答案
//因为是一个数字位0就要删除数字所在的整个行和列，如何才能降低空间复杂度？
//如果直接处理，需要m+n的复杂度，那我先用两个变量保存首行首列
//再把首行首列当成是m+n的辅助空间，用来记录该行该列是否需要删除并做标记
//记录完成后，遍历首行和首列，对矩阵进行处理
//最终再根据两个变量保存的信息对首行首列进行处理

void setZeroes(vector<vector<int>>& matrix) {
	//保存首行首列是否需要清零的信息后，用首行首列作为标记
	//判断首列是否需要置0
	int colFlag = 0;
	for (int i = 0; i<matrix.size(); i++)
	{
		if (matrix[i][0] == 0)
		{
			colFlag = 1;
			break;
		}
	}
	//判断首行是否需要置0
	int rowFlag = 0;
	for (int j = 0; j<matrix[0].size(); j++)
	{
		if (matrix[0][j] == 0)
		{
			rowFlag = 1;
			break;
		}
	}
	//遍历数组，若某处为0，将其对应在首行和首列的位置标记为0
	for (int i = 1; i<matrix.size(); i++)
		for (int j = 1; j<matrix[0].size(); j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}

	//遍历首列，遇到0则将0所在行置零
	for (int i = 1; i<matrix.size(); i++)
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 0; j<matrix[0].size(); j++)
				matrix[i][j] = 0;
		}
	}
	//遍历首行，遇到0则将0所在列置零
	for (int j = 1; j<matrix[0].size(); j++)
	{
		if (matrix[0][j] == 0)
		{
			for (int i = 0; i<matrix.size(); i++)
				matrix[i][j] = 0;
		}
	}
	//若colFlag为1，说明首列有0，将首列置0
	if (colFlag)
	{
		for (int i = 0; i<matrix.size(); i++)
			matrix[i][0] = 0;
	}
	//若rowFlag为1，说明首行有0，将首行置0
	if (rowFlag)
	{
		for (int j = 0; j<matrix[0].size(); j++)
			matrix[0][j] = 0;
	}
}