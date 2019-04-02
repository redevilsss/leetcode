#include<iostream>
#include<vector>
using namespace std;

//54 螺旋矩阵

/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
示例 :
输入:
[[1, 2, 3],[4, 5, 6],[7, 8, 9]]
输出 : [1, 2, 3, 6, 9, 8, 7, 4, 5]
*/


//这道题就是剑指offer的29题
//思路：首先要确定怎么打印，我这里是一层一层打印，打印多少层？遍历层数为行和列的较小值除以2
//其次考虑怎么打？分四部分 左上到右上 右上到右下 右下到左下 左下到左上
//每一部分都分别打印几次呢？
//以3*4矩阵最外层为例 左上到右下是从[0][0]~[0][3] 4次 右上到右下从[1][3]~[2][3] 2次
//右下到左下是从[2][2]~[2][0] 3次 左下到左上从[1][0] 1次
//而且根据最终内层形状的不同，不一定真正能走完四部分，如果最内层只有一行，一次就能打完
//具体画个图会很清晰
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	if (matrix.size() == 0)
		return res;
	int start = 0;//便利层数
	int rows = matrix.size();
	int cols = matrix[0].size();
	while (cols>start * 2 && rows>start * 2)
	{
		int endX = cols - 1 - start;//定义每一层遍历的横坐标最大值
		int endY = rows - 1 - start;//定义每层遍历的纵坐标最大值
		//开始打印,左上到右上 
		for (int i = start; i <= endX; i++)
			res.push_back(matrix[start][i]); 
		if (start<endY)
		{
			//右上到右下
			for (int i = start + 1; i <= endY; i++)
				res.push_back(matrix[i][endX]);
		}
		if (start<endX&&start<endY)
		{
			// 右下到左下
			for (int i = endX - 1; i >= start; --i)
				res.push_back(matrix[endY][i]);
		}
		if (start<endX&&start<endY - 1)
		{
			// 左下到左上
			for (int i = endY - 1; i >= start + 1; i--)
				res.push_back(matrix[i][start]);
		}
		++start;
	}
	return res;
}
