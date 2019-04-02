#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//84 柱状图中最大的矩形

/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
输入: [2,1,5,6,2,3]
输出: 10
*/

//暴力搜索...没有办法的办法
int largestRectangleArea1(vector<int>& heights) {
	int n = heights.size();
	if (n == 0) return 0;
	int maxSquare = 0;
	int curSquare = 0;
	for (int i = 0; i<n - 1; i++)
	{
		int height = heights[i];
		for (int j = i; j<n; j++)
		{
			height = min(height, heights[j]);
			curSquare = (j - i + 1)*height;
			if (curSquare>maxSquare)
				maxSquare = curSquare;
		}
	}
	if (maxSquare < heights[n - 1])
		maxSquare = heights[n - 1];
	return maxSquare;
}
//单调栈实现
//使用单调增栈用一次入栈一次出栈解决问题
//其实核心问题就是求出以每个柱子为高的最大面积，并进行比较
//如果采用两次循环来暴力搜索，思路是很清晰的但是运算复杂度会很高，尤其当数组很长的时候
//这里采用了单调增栈，使得通过一次入栈出栈就解决了问题
int largestRectangleArea(vector<int>& heights) {
	int len = heights.size();
	if (len == 0) 
		return 0;
	int maxSquare = 0;//最大值
	int curSquare = 0;//局部最大值
	int i = 0;
	stack<int> s;//用于存储下标的栈
	while (i < len)
	{
		//如果栈为空或即将进栈下标处的元素入栈后依然保持增序时，该下标进栈，且下标值+1
		if (s.empty() || heights[s.top()] <= heights[i])
			s.push(i++);
		else
		{
			//否则，说明此时栈顶下标对应的高度大于即将进栈下标对应的高度
			//说明此时以栈顶下标对应高度为最低点的矩形宽的上限值为即将进栈下标-1，也就是i-1
			int temp = s.top();//保存栈顶下标值并弹出栈顶下标
			s.pop();
			//计算以此高度为最低点的矩形面积，该面积是一个局部最大值
			if (s.empty())//若栈为空，直接用该高度乘当前下标，也就是说此时宽的下限值是0
				curSquare = heights[temp] * i;//这里可以看成是栈顶下标为-1
			else//若栈非空，此时宽的下限值为s.top()+1(因为刚才出栈后此时的top处值是小于该高度的)
				//而s.top()下标的右侧，即下标s.top()+1其值是大于等于该高度的
				curSquare = heights[temp] * (i-s.top()-1);//这里等于(i-1)-(s.top()+1)+1
		}
		//更新最大值
		if (maxSquare < curSquare)
			maxSquare = curSquare;
	}
	//与前面同理，此时的i所指的位置在最右柱子的外侧
	while (!s.empty())
	{
		int temp = s.top();
		s.pop();
		if (s.empty())
			curSquare = heights[temp] * i;
		else
			curSquare = heights[temp] * (i - s.top() - 1);
		if (maxSquare < curSquare)
			maxSquare = curSquare;
	}
	return maxSquare;
	
}

int main()
{
	vector<int> heights = { 2,1,5,6,2,3 };
	int res = largestRectangleArea(heights);
	return 0;

}