#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//类似剑指offer第40题
/*
不用整个排序，而是每次用快排，因为快排有一个特点就是每次可以把一组数分成大于枢纽元和小于枢纽元的
此时看枢纽元的位置，如果大于k，就再给前一半快排，继续比，否则就给后一半快排继续比
如果当前枢纽元的位置正好是k-1，就返回这个值
这样就能避免对整个数组的排序
*/
//交换数组中的两个元素
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//partition函数，对当前数组进行排序，并返回参考元素的下标
int partition(vector<int>& nums, int left, int right)
{
	//选取参考元素并和right位置交换
	int index = (left + right) / 2;
	swap(&nums[index], &nums[right]);

	int flag = left - 1;
	for (index = left; index<right; index++)
	{
		//如果当前节点值大于参考值
		if (nums[index]>nums[right])
		{
			++flag;
			//不相等时证明index之前（flag处）有比参考值小的数，要把这个数换出来
			//保证最后在参考值前都是大于参考值的数
			if (flag != index)
				swap(&nums[index], &nums[flag]);
		}
	}
	//更新一步flag，此时flag指向的是小于参考值的数，把参考值换回来
	++flag;
	swap(&nums[flag], &nums[right]);
	return flag;
}

int findKthLargest(vector<int>& nums, int k) {
	if (nums.size()<k)
		return -1;
	int left = 0;
	int right = nums.size() - 1;
	//取第一个参考元素的下标
	int index = partition(nums, left, right);
	//该下标不为k-1，说明还没找到，继续找
	while (index != k - 1)
	{
		//index>k-1,表明第k大的元素在index之前
		if (index>k - 1 && left<right)
		{
			right = index - 1;
			index = partition(nums, left, right);
		}
		//表明第k大的元素在index之后
		else if (left<right)
		{
			left = index + 1;
			index = partition(nums, left, right);
		}
		else
			break;
	}
	return nums[index];
}

int main()
{
	vector<int> vec = { 3,2,1,5,6,4 };
	int res = findKthLargest(vec, 2);
	return 0;
}