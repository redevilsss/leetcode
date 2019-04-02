#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//42 接雨水

/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
示例:
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/



//这个题当时做的很挣扎，因为我是直接考虑数字的起伏特征，而没有先遍历将信息获取
//所以在一次遍历过程中很多信息没有现前直到，导致很挣扎，改了很久还是不能通过全部案例
//最后看了答案发现原来很简单，主要是思路不对

//收获：在处理一些抽象问题时先考虑遍历数组将一些先验信息保存


int trap(vector<int>& height) {
	int n = height.size();
	vector<int> left(n), right(n);
	//left数组和right数组分别记录所有下标左侧的最大值和右侧的最大值
	for (int i = 1; i<n; i++)//left[i]表示i以左的最大柱高
		//可以通过left[i-1]与第i个柱高共同得出
		left[i] = max(left[i - 1], height[i - 1]);
	for (int i = n - 2; i >= 0; i--)//right数组同理
		right[i] = max(right[i + 1], height[i + 1]);
	//保存这些信息后遍历直接求解
	int res = 0;
	for (int i = 0; i<n; i++)
	{
		//取left[i]和right[i]的较小值，木桶原理，由低的一端决定容积
		int level = min(left[i], right[i]);
		//如果level值小于当前高度，说明left[i]就是height[i]，此时i处不能存水
		//给它加上0
		res += max(0, level - height[i]);
	}
	return res;
}

//我自己的方法，放在这里，应该是无法实现的
int trap(vector<int>& height) {
	if (height.size()<3)
		return 0;
	vector<int> index;
	int res = 0;
	if (height[0]>=height[1])
		index.push_back(0);
	for (int i = 1; i<height.size() - 1; i++)
	{
		if (height[i]>=height[i - 1] && height[i]>=height[i + 1])
			index.push_back(i);
	}
	if (height[height.size() - 2]<=height[height.size() - 1])
		index.push_back(height.size() - 1);
	//删掉凹口
	vector<int> index2;
	if (index.size() >= 3)
	{
		index2.push_back(index[0]);
		int compIndex = 0;
		for (int i = 1; i < index.size(); i++)
		{
			if (height[index[i]] >= height[index[compIndex]])
			{
				index2.push_back(index[i]);
				compIndex = i;
			}
		}
		if (height[index[compIndex]] > height[index[index.size() - 1]])
			for (int i = compIndex + 1; i < index.size(); i++)
				index2.push_back(index[i]);
	}
	else
		index2 = index;
	for (int i = 1; i < index2.size(); i++)
	{
		int min = height[index2[i - 1]] < height[index2[i]] ? height[index2[i - 1]] : height[index2[i]];
		for (int j = index2[i - 1]+1; j < index2[i]; j++)
			if(height[j]<min)
				res += min - height[j];
	}
	return res;
}



int main()
{
	vector<int> vec = {9, 2, 9, 3, 2, 2, 1, 4, 8};
	int res = trap(vec);
	return 0;
}