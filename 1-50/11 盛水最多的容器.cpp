#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。
图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
示例:
输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/

//此题的核心在于如何能减少重复计算，降低复杂度，及早的进行判断和舍弃很重要
int maxArea(vector<int>& height) 
{
	//设置初始时的两边位置
	int end = height.size() - 1;
	int begin = 0;
	int res = 0;
	//循环找最大值
	while (begin<end)
	{
		int high = min(height[begin], height[end]);
		res = max(res, high*(end - begin));
		//保留高的一边，因为此时的res大于所有以低边为一边而以两边之间任意一边为另一边组成的水桶的容积
		//木桶效应，其容积由低边和宽决定，当宽逐渐缩小时，去掉高边只会使容积变小
		if (height[begin]>height[end])				  
			end--;
		else
			begin++;
	}
	return res;
}