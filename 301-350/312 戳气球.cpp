#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//用动态规划来解决问题
/*
定义二维数组dp，dp[i][j]表示从i到j的可以获得的最大硬币
递推式是dp[i][j] = max(dp[i][j], nums[k] * right*left + before + after);
其中right和left分别是nums[i-1]和nums[j-1]，k表示i到j之间最后一个戳破的气球的位置
before表示dp[i][k-1],after表示dp[k+1][j]
三重循环，第一层确定区间长度，第二层确定起点终点，第三层找dp[i][j]的最大值，通过区间的合并来实现
*/
int maxCoins(vector<int>& nums) {
	int len = nums.size();
	if (len == 0)
		return 0;
	vector<vector<int>> dp(len, vector<int>(len, 0));
	//l表示当前长度
	for (int l = 1; l <= len; l++)
	{
		//i从0~len-l+1(当i为len-l时，j指向最后一个数字)，表示当前包含范围的左边界
		for (int i = 0; i + l - 1<len; i++)
		{
			//j表示长度为l时包含范围的右边界
			int j = i + l - 1;
			//在这里需要求出以i和j为边界的气球能获得的最多硬币
			//left和right分别表示当前范围的左右相邻元素值
			int left = i == 0 ? 1 : nums[i - 1];
			int right = j == len - 1 ? 1 : nums[j + 1];
			//k表示i到j中间最后一个戳破的位置
			for (int k = i; k <= j; k++)
			{
				//before和after表示从i到k-1和k+1到j的最多硬币值,其中k取值为从i到j
				int before = k == i ? 0 : dp[i][k - 1];
				int after = k == j ? 0 : dp[k + 1][j];
				dp[i][j] = max(dp[i][j], nums[k] * right*left + before + after);
			}
		}
	}
	return dp[0][len - 1];
}
/*
int main()
{
	vector<int> v = { 3,1,5,8 };
	int res = maxCoins(v);
	return 0;
}
*/