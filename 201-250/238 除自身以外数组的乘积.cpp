#include<iostream>
#include<vector>
using namespace std;

//238 除自身以外数组的乘积

/*
给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
示例:
输入: [1,2,3,4]
输出: [24,12,8,6]
*/

/*
定义输出数组output
既然不让用除法，就考虑保存前缀积
也就是说，首先遍历数组，求当前节点左侧元素的乘积，通过迭代每次乘新的元素进来即可实现
完成后再定义变量t表示当前右侧元素的乘积
倒序遍历数组，每次更新t，再用t*原output[i]来更新output数组得到最终结果
*/
vector<int> productExceptSelf(vector<int>& nums) {
	int len = nums.size();
	vector<int> output(len, 1);
	for (int i = 1; i<len; i++)
		output[i] = output[i - 1] * nums[i - 1];
	int t = 1;
	for (int i = len - 2; i >= 0; i--)
	{
		t = t*nums[i + 1];
		output[i] = output[i] * t;
	}
	return output;
}