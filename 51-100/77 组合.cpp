#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 77 组合
/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
示例:
输入: n = 4, k = 2
输出:
[[2,4],[3,4],[2,3],[1,2],[1,3],[1,4],]
*/


//分析：典型的回溯递归类型的题目，重点在于如何控制能取到整个数组的所有值
//举个例子 n=4， 1 2 3 4 k=2，如何取到后面的值，要设置一个变量用于存储当前递归遍历的下标数
//作为下一次遍历的起点，这一就不会出现重复，也能遍历到所有的数
vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> res;
	vector<int> temp;
	if (n == 0 || k == 0 || n<k)
		return res;
	func(res, temp, n, k, 1);
	return res;
}
void func(vector<vector<int>>& res, vector<int>& temp, int n, int k, int index)
{
	if (k == temp.size())
	{
		res.push_back(temp);
		return;
	}
	for (int i = index; i <= n; i++)
	{
		temp.push_back(i);
		//这里的i很重要，实现多排少的时候一定要定义变量来控制递归时对数组的标记
		func(res, temp, n, k, i + 1);
		temp.pop_back();
	}
}