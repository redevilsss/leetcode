#include<iostream>
#include<vector>
using namespace std;

//31 下一个排列

/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

//这个问题有一定难度，主要是对于概念的理解
//摘取评论区大神的思路：其实就是从数组倒着查找，找到nums[i] 比nums[i+1]小的时候，
//就将nums[i]跟nums[i+1]到nums[nums.length - 1]当中找到一个最小的比nums[i]大的元素交换。
//交换后，再把nums[i+1]到nums[nums.length-1]排序，就ok了
void nextPermutation(vector<int>& nums)
{
	if (nums.size() <= 1)
		return;
	if (nums.size() == 2)
	{
		int temp = nums[0];
		nums[0] = nums[1];
		nums[1] = temp;
		return;
	}
	//用flag表示是否进行了交换
	int flag = 0;
	for (int i = nums.size() - 1; i>0; i--)
	{
		//找第一个逆序的位置
		if (nums[i]>nums[i - 1])
		{
			//如果就是最后一个逆序，交换后直接退出
			if (i == nums.size() - 1)
			{
				int temp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = temp;
				flag = 1;
				break;
			}
			
			//找最小的比nums[i-1]大的数
			int min_index =i+1;
			int flag2 = 0;//能不能找到的标记
			for (int j = i+1; j<nums.size(); j++)
			{
				if (nums[j] > nums[i - 1] && nums[min_index] >= nums[j])
				{
					min_index = j;
					flag2 = 1;
				}	
			}
			if (flag2 == 0)//找不到，说明nums[i-1]大于所有下标超过i1的数
				//此时直接这两个数交换nums[i-1]和nums[i]
			{
				int temp = nums[i];
				nums[i] = nums[i-1];
				nums[i-1] = temp;
				reverse(nums.begin() + i, nums.end());
				flag = 1;
				break;
			}
			//否则，交换nums[i - 1]和找到的最小的大于nums[i-1]的数
			else
			{
				int temp = nums[i - 1];
				nums[i - 1] = nums[min_index];
				nums[min_index] = temp;
				reverse(nums.begin() + i, nums.end());
				flag = 1;
				break;
			}
			
		}
	}
	//如果全逆序，则直接翻转
	if (flag == 0)
		reverse(nums.begin(), nums.end());
}

int main()
{
	vector<int> vec = {1,5,1};
	nextPermutation(vec);
	return 0;
}
