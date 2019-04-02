#include<iostream>
#include<vector>
using namespace std;

//出现超过n/3的元素最多有两个，用两个变量num1和num2来表示
/*
类似于之前求超过一半的元素，用抵消法来实现，只不过这里变成两个变量和两个记录值count1和count2
*/
vector<int> majorityElement(vector<int>& nums) {
	vector<int> res;
	//定义变量和变量出现的次数，用抵消法来做
	int count1 = 0;
	int count2 = 0;
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		//当前值等于num1则count1加，否则count减，如果count1为0则重置num1
		//num2同理
		if (count1 != 0 && nums[i] == num1)
			count1++;
		else if (count2 != 0 && nums[i] == num2)
			count2++;
		else if (count1 == 0)
		{
			num1 = nums[i];
			count1 = 1;
		}
		else if (count2 == 0)
		{
			num2 = nums[i];
			count2 = 1;
		}
		else
		{
			count1--;
			count2--;
		}
	}
	//统计num1和num2出现的次数
	count1 = 0;
	count2 = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		if (nums[i] == num1)
			count1++;
		else if (nums[i] == num2)
			count2++;
	}
	//如果超过1/3就入数组
	if (count1>nums.size() / 3)
		res.push_back(num1);
	if (count2>nums.size() / 3)
		res.push_back(num2);
	return res;
}