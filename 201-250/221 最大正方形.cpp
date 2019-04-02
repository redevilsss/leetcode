#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//这类题一般考虑的就是回溯递归和动态规划
//回溯递归适合基于元素值的问题，动态规划适合基于位置的问题
/*
针对这道题，我需要找出最大正方形的边长
怎么找呢？找当前点对应的dp[i][j]周围的dp[i-1][j]、dp[i-1][j-1]、dp[i][j-1]中的最小值加1
也就是说，只要这三个值里有一个是0，那dp[i][j]就是1
总之这类问题最重要的就是动态规划的迭代公式
*/
int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return 0;
	int row = matrix.size();
	int col = matrix[0].size();
	//构造dp二维数组
	vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
	//定义最长边
	int maxLength = 0;
	//遍历数组更新dp数组和maxLength变量，要注意matrix数组和dp数组的下标不一致
	//dp[i][j]记录的是以matrix[i-1][j-1]为右下顶点的最大正方形边长，用来更新maxLength
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (matrix[i - 1][j - 1] == '1')//matrix的i j在dp中对应的下标是i+1，j+1，因为dp是从1开始的
			{
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
				maxLength = max(maxLength, dp[i][j]);
			}

		}
	}
	return maxLength*maxLength;
}