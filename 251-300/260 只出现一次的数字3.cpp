#include<iostream>
#include<vector>
using namespace std;
//260 只出现一次的数字3

/*
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
示例 :
输入: [1,2,1,3,2,5]
输出: [3,5]
*/


//类似136 只出现一次的数字1
//还是用异或的方法来求 只不过这次要对数字进行分类，因为有两个只出现一次的数字，所以要想办法把两个数放到两个不同的数组中
//这两个数组中除了一个出现一次的数字，其他数字都出现两次，此时用136题的方法分别异或两个数组就能得到结果
//问题就在于如何区分，首先把所有元素异或得到一个数，这个数其实就是两个只出现一次的数的异或结果，从右到左找到该数二进制形式出现的第一个1
//则这两个数在第一个1出现的下标处的值不同（否则异或应该是0的）
//根据这一位的值不同，可以把一个数组的元素一分为二
vector<int> singleNumber(vector<int>& nums) {
	//求异或值
	int Xor = nums[0];
	for (int i = 1; i<nums.size(); i++)
		Xor ^= nums[i];
	//找从右到左第一个1
	int mask = 1;
	while ((mask&Xor) == 0)
	{
		mask <<= 1;
	}
	//分别求两个子数组的异或
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		if ((nums[i] & mask) == 0)
			num1 ^= nums[i];
		else
			num2 ^= nums[i];
	}

	return { num1,num2 };

}