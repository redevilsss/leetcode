#include<iostream>
#include<vector>
using namespace std;
//303 区域和检索

/*
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
示例：
给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
说明:
你可以假设数组不可变。
会多次调用 sumRange 方法。
*/




class NumArray {
	vector<int> sums;
public:
	//重点在于多次调用，所以最好是用一个等长数组来存储部分和，这样在求和的时候只需要相减即可
	NumArray(vector<int> nums) {
		if (nums.size() == 0)
			return;
		sums.resize(nums.size());
		sums[0] = nums[0];
		for (int i = 1; i<nums.size(); i++)
			sums[i] += sums[i - 1] + nums[i];
	}

	int sumRange(int i, int j) {
		if (i == 0)
			return sums[j];
		else
			return sums[j] - sums[i - 1];
	}
};