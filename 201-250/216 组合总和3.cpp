#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//216 组合总和3

/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
说明：
所有数字都是正整数。
解集不能包含重复的组合。
示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]
*/


/*
典型的回溯递归问题
在进入递归前需要注意的几点：
一.如何满足组合有三个限制条件：
1.相加之和为n：通过在递归中设置rest变量，保存当前剩余和，当剩余和小于0时，返回
2.k个数：通过对临时数组temp的元素个数进行判断，来保证每个组合中出现k个数，当temp.size()大于k时返回
3.不重复：通过变量index来实现，保证在找组合下一个数时是从当前temp.back（）+1开始找起
4.只含有1-9正整数：递归中设置循环从1-9
二.递归推出条件
1.当temp.size()>k或n<0时，退出
2.当temp.size()==k且n恰好为0时，保存当前的temp，退出
*/
vector<vector<int>> res;
vector<vector<int>> combinationSum3(int k, int n) {
	vector<int> temp;
	dfs(1, k, n, temp);
	return res;
}
//index用来记录上一步遍历到的位置，这样就能避免元素重复
//rest用来记录当前的剩余和
//k用来限制每个组合的个数
void dfs(int index, int k, int& rest, vector<int>& temp)
{
	if (temp.size()>k || rest<0)
		return;
	if (temp.size() == k&&rest == 0)
	{
		res.push_back(temp);
		return;
	}
	for (int i = index; i <= 9; i++)
	{
		temp.push_back(i);
		rest -= i;
		dfs(i + 1, k, rest, temp);
		temp.pop_back();
		rest += i;
	}
}