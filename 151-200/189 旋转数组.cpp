#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//189 旋转数组

/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
示例 1:
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
*/


//翻转应该是最快的方式
//先翻转整个数组，再分别翻转前k%len个元素和后面的元素
void rotate(vector<int>& nums, int k) {
	int len = nums.size();
	if (len == 0)
		return;
	int step = k%len;
	if (step == 0)
		return;
	for (int i = 0; i<len/2; i++)
	{
		int temp = nums[i];
		nums[i] = nums[len - 1 - i];
		nums[len - 1 - i] = temp;
	}
	for (int i = 0; i<step/2; i++)
	{
		int temp = nums[i];
		nums[i] = nums[step - 1 - i];
		nums[step - 1 - i] = temp;
	}
	for (int i = step; i<(step+len)/2; i++)
	{
		int temp = nums[i];
		nums[i] = nums[len+step-1  - i];
		nums[len + step - 1 - i] = temp;
	}
}


int main()
{
	vector<int> vec = { 1,2,3,4,5,6,7 };
	rotate(vec, 3);
	return 0;
}