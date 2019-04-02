#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//217 存在重复元素
/*
给定一个整数数组，判断是否存在重复元素。
如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
示例 1:
输入: [1,2,3,1]
输出: true
*/

//这道题没事考的，一开始我还以为有位运算之类的方法，结果没有
//sort排序是最好的...直接调算了。。。
bool containsDuplicate(vector<int>& nums) {
	if (nums.size()<2)
		return false;
	sort(nums.begin(), nums.end());
	for (int i = 1; i<nums.size(); i++)
	{
		if (nums[i] == nums[i - 1])
			return true;
	}
	return false;

}