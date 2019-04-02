#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//152 乘积最大子序列
/*
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
*/


/*
这道题主要问题就在于正数和负数都存在，在计算最大值的过程中，既要保存最大的数imax，也要保存最小的数imin
定义最大值为max，则每一步要先判断当前最大最小值，再更新max
因为如果当前数是负数，那么之前最小的数就会变成一个有竞争力的正数，所以在此时交换imax和imin
还有一点，如何控制开始乘的地方？-需要每一次对imax*nums[i]和nums[i]进行比较，如果小于nums[i]，那么imax就会变成nums[i]
起始乘的位置更新为从i开始，同理imin也是如此
遍历完数组后max就是所求的最大子序列
这道题的重点在于当前最大值和最小值都要保存
*/
int maxProduct(vector<int>& nums) {
	int Max = INT_MIN;
	int imax = 1;//当前位置为止的最大值
	int imin = 1;//当前位置为止的最小值
	for (int i = 0; i<nums.size(); i++)
	{
		//此时nums[i]为负数，那么下一步可能出现的较大值应该是imin*nums[i]，所以交换imin和imax
		if (nums[i]<0)
		{
			int temp = imax;
			imax = imin;
			imin = temp;
		}
		//比较imax*nums[i]和 nums[i]，更新当前最大值
		imax = max(imax*nums[i], nums[i]);
		//比较imin*nums[i]和 nums[i]，更新当前最小值
		imin = min(imin*nums[i], nums[i]);
		//更新Max
		Max = max(Max, imax);

	}
	return Max;
}