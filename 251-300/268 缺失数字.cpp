#include<iostream>
#include<vector>
using namespace std;
//268 缺失数字
/*
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
示例 1:
输入: [3,0,1]
输出: 2
*/



/*
这题我一开始想用求和减数组和来算的，但是发现有更简单的方法
0-n的数字缺一个，数组的下标是0-n-1，数组的大小是n
得嘞，这不就是只出现一次的数字吗？
我把所有下标异或，再把所有数组中的数异或，再和n异或(因为之前下标是从0-n-1)
这个时候我一共异或了一次0-n缺一个，一次0-n一个不缺,缺的那个就是所有异或后的结果
*/
int missingNumber(vector<int>& nums) {
	int res = nums.size();
	for (int i = 0; i<nums.size(); i++)
	{
		res ^= nums[i];
		res ^= i;
	}
	return res;
}