#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//283 移动零
/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
*/


//方法一：双指针，找到0就放到数组末尾
void moveZeroes(vector<int>& nums) {
	int len = nums.size();
	int start = 0;
	int end = len - 1;
	while (start <= end)
	{
		while (start <= end&&nums[end] == 0)
			end--;
		while (start <= end && nums[start] != 0)
			start++;
		if (start>end)
			break;
		for (int i = start; i<end; i++)
			nums[i] = nums[i + 1];
		nums[end] = 0;
	}
}

//方法二：一种更快的方法，定义一个新指针，遍历数组把所有非零元素重新填充数组，最后末尾全部赋零
void moveZeroes(vector<int>& nums) {
	int index = 0;
	for (int i = 0; i<nums.size(); i++)
		if (nums[i] != 0)
			nums[index++] = nums[i];
	for (int i = index; i<nums.size(); i++)
		nums[i] = 0;
}

int main()
{
	vector<int> vec = { 0,1,0,3,12 };
	moveZeroes(vec);
	return 0;
}