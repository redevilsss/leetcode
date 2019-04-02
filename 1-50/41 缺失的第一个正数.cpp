#include<iostream>
#include<vector>
using namespace std;

//41 缺失的第一个正数

/*
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:
输入: [1, 2, 0]
输出 : 3

示例 2 :
输入 : [3, 4, -1, 1]
输出 : 2

示例 3 :
输入 : [7, 8, 9, 11, 12]
输出 : 1
*/

//这个题类似剑指offer第3题
/*思路：
从前往后遍历数组，看该位置的值是否在它数组下标那个位置
比如：3,4，-1,1，3在第一个，应该和-1交换，如果该值大于数组长度，
或者该值为负数，那么就不进行交换，处理完所有的值，遍历数组，看哪个位置的
值不等于下标，这个位置就是要找的数
*/
//目的在于将所有正数放在该放的位置且按顺序排列好，和下标一一对应，第一个不与下标对应处的下标+1就是所求的结果
int firstMissingPositive(vector<int>& nums)
{
	if (nums.size() == 0)
		return 1;
	//遍历将所有正数n+1放在下标n处
	for (int i = 0; i<nums.size(); i++)
	{
		//若值小于长度大于0且下标+1不等于值，通过交换使其下标+1等于值
		while (nums[i]>0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
		{
			//交换后i=nums[i]-1
			int temp = nums[i];
			nums[i] = nums[temp - 1];
			nums[temp - 1] = temp;
		}
	}
	//再遍历找第一个值不等于下标加1的地方，其下标加1就是缺的最小正数
	for (int i = 0; i<nums.size(); i++)
	{
		if (nums[i] != i + 1)
			return i + 1;
	}
	return nums.size() + 1;

}

int main()
{
	vector<int > vec = { 4,3,6,5,1,-1 };
	int res=firstMissingPositive(vec);
	return 0;

}