#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//78 子集

/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。
示例:
输入: nums = [1,2,3]
输出:
[[3],[1],[2],[1,2,3],[1,3],[2,3],[1,2],[]]
*/


//首先想到用回溯递归，重点在于如何控制子集的元素个数
//如果用回溯和递归来解决问题，那么重点就是如何控制子集长度，还有退出条件
//借鉴了别人的代码，这里index一举两得，在push当前index对应的值前后各进行一次递归，前面一次递归中未加入当前index的值，后面一次则是加入当前index值后
//比如 1 2 3 4，前一次递归直接从2开始，后一次则是先保存1，再从2开始，以此类推
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> res;
	if (nums.size() == 0)
		return res;
	vector<int> temp;
	sort(nums.begin(), nums.end());
	func(res, temp, nums, 0);
	return res;
}
void func(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int index)
{
	if (index == nums.size())
	{
		res.push_back(temp);
		return;
	}
	func(res, temp, nums, index + 1);
	temp.push_back(nums[index]);
	func(res, temp, nums, index + 1);
	temp.pop_back();
}


//更加便于理解和简洁的算法，使用位运算，从0000...~11111...，每一位表示这一位对应在数组中的数取不取，若取则加入数组，循环2的n次方次，可以得到全部2的n次方个子集
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> res;
	int n = nums.size();
	for (int i = 0; i<(1 << n); i++)//1<<n就是2的n次方,最终的结果子集就是2的n次方个，所以每次循环得到一个子集，这里i的二进制每一位表示是否取数组中某一位的元素
	{
		vector<int> temp;
		//这一过程产生一个子集，举个例子，如果nums={1，2，3},则000对应空集，001 010 100分别对应[1] [2] [3]，011 101 110分别表示[2,3] [1,3] [1,2] 111表示[1,2,3]
		//对i的每一位进行判断就能得到子集
		for (int j = 0; j<n; j++)
			if (i >> j & 1)
				temp.push_back(nums[j]);
		res.push_back(temp);
	}
	return res;
}