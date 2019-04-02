#include<iostream>
#include<vector>
using namespace std;

//167 两数之和2-输入有序数组

/*
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
说明:
返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:
输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
*/


//很简单的一道题，头尾双指针，比较和与目标值差距，比目标值小头指针后移，比目标值大尾指针前移
vector<int> twoSum(vector<int>& numbers, int target) {
	if (numbers.size()<2)
		return {};
	vector<int> res(2, 0);
	res[1] = numbers.size() - 1;
	while (res[0]<res[1])
	{
		int sum = numbers[res[0]] + numbers[res[1]];
		if (sum == target)
		{
			res[0]++;
			res[1]++;
			return res;
		}

		else if (sum>target)
			res[1]--;
		else
			res[0]++;
	}
	return {};

}