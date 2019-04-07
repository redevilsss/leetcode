#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//308 最佳买卖股票含冷冻期

/*
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:
输入: [1,2,3,0,2]
输出: 3
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
*/

//方法1：复杂度为o(n*n)的动态规划
//动态规划来解决问题
//首先，当数组长度为1时直接返回
/*
定义数组dp用来保存中间值，其中dp[i]表示到第i天为止的最高收益
每一步的dp[i]都需要遍历当前数组来求
首先考虑第i-1天没卖出股票的情况，令dp[i]=dp[i-1]
dp[i-1]表示当在第i-2天最后一次卖出股票时第i天的收益(第i-1天冻结)
接着遍历所有在第i-1天卖出股票的情况，令j=i-1~1,当prices[i-1]>prices[j-1]时，说明第j-1天买入第i-1天卖出有的赚，这种情况下的收益为
dp[j-2]+price[i-1]-price[j-1],其中dp[j-2]表示第j-2天的收益，如果j大于2取dp[j-2]，否则取0
i从2到size，j从i-1到0，复杂度o(n*n)，遍历整个数组后dp[size]表示最大收益
*/
int maxProfit1(vector<int>& prices)
{
	if (prices.size() <= 1)
		return 0;
	vector<int> dp(prices.size() + 1, 0);
	for (int i = 2; i <= prices.size(); i++)
	{
		//第i-1天没卖股票的情况，那dp[i]就等于dp[i-1]
		dp[i] = dp[i - 1];
		//后序分别遍历所有在第i-1天卖出股票的情况
		for (int j = i - 1; j>0; j--)
		{
			//如果第i-1天的价格大于第j-1天，在选择第j-1天买入而第i-1天卖出
			if (prices[i - 1]>prices[j - 1])
			{
				int temp = (j - 2>0) ? dp[j - 2] : 0;
				dp[i] = max(dp[i], temp + prices[i - 1] - prices[j - 1]);
			}

		}
	}
	return dp[prices.size()];
}
//方法2：复杂度为o(n)的动态规划
//动态规划的重点在于1.确定状态 2.状态转移方程的确立
//状态增多，保存的中间量也能相应增加，可能能够减少许多不必要的寻找
//所以方法2共设置了三个状态sell，buy和cool，使得复杂度降低了
//看来对动态规划的理解还有待提升
/*
sell[i]表示截至第i天，最后一个操作是卖时的最大收益；
buy[i]表示截至第i天，最后一个操作是买时的最大收益；
cool[i]表示截至第i天，最后一个操作是冷冻期时的最大收益；
递推公式：
sell[i] = max(buy[i-1]+prices[i], sell[i-1]) (第一项表示第i天卖出，第二项表示第i天冷冻)
buy[i] = max(cool[i-1]-prices[i], buy[i-1]) （第一项表示第i天买进，第二项表示第i天冷冻）
cool[i] = sell[i-1]
*/
int maxProfit(vector<int>& prices)
{
	if (prices.size() <= 1)
		return 0;
	vector<int> sell(prices.size(), 0);
	vector<int> buy(prices.size(), 0);
	vector<int> cool(prices.size(), 0);
	buy[0] = -prices[0];
	for (int i = 1; i < prices.size(); i++)
	{
		//截止第i天，最后一个操作是卖出时的收益
		//等于max(截止第i-1天最后一个操作是买入的最大收益+第i天卖出的收益,截止第i-1天最后一个操作是卖出的最大收益)
		sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
		//截至第i天，最后一个操作是买时的最大收益
		//等于max(第i-1天是冷冻期的最大收益-第i天买入的支出，第i-1天买入的最大收益)
		buy[i] = max(cool[i - 1] - prices[i], buy[i - 1]);
		//若第i天为冷冻期，则i-1天肯定为卖出，也就是说
		cool[i] = sell[i - 1];
	}
	//最大收益就是截止第size天，最后一个操作是卖出时的收益，下标为size-1
	return sell[prices.size()-1];
}



int main()
{
	vector<int> v = { 1,2,3,0,2 };
	int res = maxProfit(v);
	return 0;
}


