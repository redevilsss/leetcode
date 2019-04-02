#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//123 买卖股票的最佳时机3
/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
*/

//方法一：类似于动态规划，遍历数组，更新变量
//这题本来想找峰值处理的，看到了大佬的答案，很简洁
/*
对于任意某一天考虑四个变量：
firstBuy:在该天第一次买入股票可以获得的最大收益
firstSell:在该天第一次卖出股票可以获得的最大收益
secondBuy: 在该天第二次买入股票可获得的最大收益
secondSell: 在该天第二次卖出股票可获得的最大收益
*/

int maxProfit(vector<int>& prices) {
	//初始化变量
	int firstBuy = INT_MIN;
	int secondBuy = INT_MIN;
	int firstSell = 0;
	int secondSell = 0;
	//遍历数组，更新变量
	for (int p : prices)
	{
		firstBuy = max(firstBuy, -p);//更新firstBuy,等号右边的firstBuy是之前保存的第一次买入可获得的最大收益，如果是今天买入，收益就是0-p，更新firstBuy
		firstSell = max(firstSell, firstBuy + p);//firstSell,等号右边的firstBuy是更新后第一次买入可获得的最大收益，如果是今天第一次卖出，总收益就是更新firstBuy+p，更新firstSell
		secondBuy = max(secondBuy, firstSell - p);//等号右边的firstSell是更新后第一次卖出可获得的最大收益，如果今天第二次买入，总收益变为firstSell-p,更新secondBuy
		secondSell = max(secondSell, secondBuy + p);//等号右边的secondBuy是更新后第二次买入可获得的最大收益，如果今天第二次买出，总收益变为secondBuy+p,更新secondSell
	}
	return secondSell;

}


//思路：从前往后遍历一次，得到从第1天到第i天之间只买卖一次获得的最大利润，保存进数组1
//从后往前遍历一次，得到从到第i天到最后一天之间只买卖一次获得的最大利润，保存进数组2
//那么我将数组1和数组2两数组相同下标处的数值（以下标i为例）相加，就表示从第1天到最后一天(以第i天为间隔)两次买入卖出得到的最大利润
//遍历取最大值就是所求结果
//方法二：
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	if (n<2)
		return 0;
	vector<int> dp1(n, 0);
	vector<int> dp2(n, 0);
	int minval = prices[0];//从前到后遍历，当前股票价格的最低值（买入值）
	int maxval = prices[n - 1];//从后到前遍历，当前股票价格的最大值（卖出值）
	for (int i = 1; i<n; i++)
	{
		dp1[i] = max(dp1[i - 1], prices[i] - minval);//记录第i天卖出股票可以获得的最大利润
		minval = min(minval, prices[i]);//更新当前股票最低价
	}
	for (int i = n - 2; i >= 0; i--)
	{
		dp2[i] = max(dp2[i + 1], maxval - prices[i]);//记录第i天卖出股票可以获得的最大利润
		maxval = max(maxval, prices[i]);//更新当前股票最低价
	}
	//遍历求最大值
	int maxPro = dp1[0] + dp2[0];
	for (int i = 1; i<n; i++)
		maxPro = max(maxPro, dp1[i] + dp2[i]);
	return maxPro;

}

int main()
{
	vector<int> vec = {6,1,3,2,4,7 };
	int res = maxProfit(vec);
	return 0;
}