#include<iostream>
#include<vector>
using namespace std;
//304 二维区域搜索

/*
给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。
上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。
示例:
给定 matrix = [
[3, 0, 1, 4, 2],
[5, 6, 3, 2, 1],
[1, 2, 0, 1, 5],
[4, 1, 0, 1, 7],
[1, 0, 3, 0, 5]
]
sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
说明:
你可以假设矩阵不可变。
会多次调用 sumRegion 方法。
你可以假设 row1 ≤ row2 且 col1 ≤ col2。
*/

//和上题类似，重点在于保存部分和，这里用二维数组dp来保存
//相比一维数组复杂一点，但方法很简单
class NumMatrix {
private:
	vector<vector<int>> dp;
public:
	NumMatrix(vector<vector<int>> matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return;
		int rows = matrix.size();
		int cols = matrix[0].size();
		dp.resize(rows);
		for (int i = 0; i<rows; i++)
			dp[i].resize(cols);
		dp[0][0] = matrix[0][0];
		//初始化第一列
		for (int i = 1; i<rows; i++)
			dp[i][0] = dp[i - 1][0] + matrix[i][0];
		//初始化第一行
		for (int i = 1; i<cols; i++)
			dp[0][i] = dp[0][i - 1] + matrix[0][i];
		//更新其余位置
		for (int i = 1; i<rows; i++)
		{
			for (int j = 1; j<cols; j++)
			{
				//为什么要这么算画图一目了然
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		//分四种情况返回结果
		if (row1 == 0 && col1 == 0)
			return dp[row2][col2];
		else if (row1 == 0)
			return dp[row2][col2] - dp[row2][col1 - 1];
		else if (col1 == 0)
			return dp[row2][col2] - dp[row1 - 1][col2];
		else
			return dp[row2][col2] - dp[row2][col1 - 1] - dp[row1 - 1][col2] + dp[row1 - 1][col1 - 1];

	}
};

int main()
{
	vector<vector<int>> vec = { {3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5} };
	NumMatrix n(vec);
	int res1 = n.sumRegion(2, 1, 4, 3);
	int res2 = n.sumRegion(1, 1, 2, 2);
	int res3 = n.sumRegion(1, 2, 2, 4);
	return 0;
}