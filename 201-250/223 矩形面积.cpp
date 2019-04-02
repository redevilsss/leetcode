#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//223 矩形面积
/*
在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。
示例:
输入: -3, 0, 3, 4, 0, -1, 9, 2
输出: 45
*/

/*
很简单的问题，首先判断两矩形有没有重合，没有重合就直接面积相加
否则要找出重合部分的两个顶点坐标，进而计算重合部分面积
最终返回矩形1面积-重合面积+矩形2面积
*/
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	if (A >= G || C <= E || B >= H || D <= F)
		return (C - A)*(D - B) + (G - E)*(H - F);
	int bottomX = max(A, E);
	int TopX = min(C, G);
	int bottomY = max(B, F);
	int TopY = min(D, H);
	return (C - A)*(D - B) - (TopX - bottomX)*(TopY - bottomY) + (G - E)*(H - F);
}