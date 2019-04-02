#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//279 完全平方数
/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
示例 1:
输入: n = 12
输出: 3
解释: 12 = 4 + 4 + 4.
*/

//方法一：
//用动态规划来解
//dp[i]表示数字i最少需要几个完全平方数来表示，dp[i]=min(dp[i-j*j])+1,
//也就是说我需要遍历在小于i的下标k中找到最小的值，满足i-k是完全平方数
int numSquares(int n) {
	//初始化dp数组
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		//在满足i-k为完全平方数的k中找最小的dp[k],dp[i]=dp[k]+1
		int temp = INT_MAX;
		for (int j = 1; j*j <= i; j++)
			temp = min(temp, dp[i - j*j]);
		dp[i] = temp + 1;
	}
	return dp[n];
}

//方法二：
//根据 拉格朗日四平方和定理，可以得知答案必定为 1, 2, 3, 4 中的一个。
//其次根据 勒让德三平方和定理，可以得知当 n=4^a *(8b+7)时，n不能写成 3 个数的平方和。
//然后可以根据以上定理和枚举，判断出答案是否为 1, 2, 3，若都不是则答案为 4。
int numSquares1(int n)
{
	//先根据上面提到的公式来缩小n
	while (n % 4 == 0)
		n /= 4;
	//如果满足公式 则返回4
	if (n % 8 == 7)
		return 4;
	//在判断缩小后的数是否可以由一个数的平方或者两个数平方的和组成
	//因为前面除的都是4，不会影响最后的结果，举个例子48和3的结果都是3，因为48=16*3=16*（1+1+1）=(16+16+16)
	int a = 0;
	while (a*a <= n)
	{
		int b = sqrt(n - a*a);
		//如果可以在这里返回
		if (a*a + b*b == n)
		{
			if (a != 0 && b != 0)
				return 2;
			else
				return 1;
		}
		a += 1;
	}
	//否则返回3
	return 3;


}

