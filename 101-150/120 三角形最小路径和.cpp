#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//120 三角形最小路径和
/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
例如，给定三角形：
[
   [2],
  [3,4],
 [6,5,7],
[4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
*/

//动态规划，逐层遍历更新最小路径和数组

int minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.size() == 0)
		return 0;
	//dp数组表示自底向上到达某一层的最小路径，dp[j]表示到达某一层下标为j的元素时的最小路径
	//两层循环，外层控制层数，内层更新每一层的最小路径和
	vector<int> dp(triangle.size() + 1);
	for (int i = triangle.size() - 1; i >= 0; i--)
	{
		vector<int> temp = triangle[i];
		for (int j = 0; j<temp.size(); j++)
			//更新最小路径和的顺序时从左到右，所以当j更新以后dp[j]就不会再被用到,如果从右到左更新，j+1要变成j-1，不能让更新后的当前层数据影响到下一次更新
			//最小路径和等于下一层相邻两个位置中较小的路径和加上此时遍历位置的值
			dp[j] = temp[j] + min(dp[j], dp[j + 1]);
	}
	return dp[0];//最终到达第一层 dp[0]=min(dp[0],dp[1])+triangle[0][0],保存着最终从底层到最顶的最小路径和
}