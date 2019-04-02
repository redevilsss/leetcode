#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//85 最大矩形

/*
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
输入:
[["1","0","1","0","0"],
 ["1","0","1","1","1"],
 ["1","1","1","1","1"],
 ["1","0","0","1","0"]]
输出: 6
*/

//这道题个上一道思路相同，只是要先将字符矩阵做一定的处理变成数字矩阵
//然后就是几个解决柱状图最大值的问题
//以上面输入为例，转换完后的矩阵为
/*
** 1 0 1 0 0
** 2 0 2 1 1
** 3 1 3 2 2
** 4 0 0 3 0
*/
//然后对这个矩阵的每一行进行84题中一样的运算处理，求出最大值
//注意，无论某一行某一列元素之上有多少个1，只要该坐标处为0，数字矩阵在该处值就为0

int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return 0;
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>> heights(m, vector<int>(n, 0));
	int maxSquare = 0;
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			if (i == 0)
			{
				//先初始化第一行
				if (matrix[i][j] == '1')
					heights[i][j] = 1;
			}
			if (i != 0 && matrix[i][j] == '1')
			{
				//齐宇航以第一行为基准进行转换
				if (matrix[i][j] == '1')
					heights[i][j] = 1 + heights[i - 1][j];
			}
		}
		maxSquare = max(maxSquare, largestRectangleArea(heights[i]));
	}
	return maxSquare;
}


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
			else//若栈非空，此时宽的下限值为s.top()+1(因为刚才出栈后此时的top处值是小于该高度的)				//而s.top()下标的右侧，即下标s.top()+1其值是大于等于该高度的
				curSquare = heights[temp] * (i - s.top() - 1);//这里等于(i-1)-(s.top()+1)+1
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