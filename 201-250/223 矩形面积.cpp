#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//223 �������
/*
�ڶ�άƽ���ϼ����������ֱ�߹��ɵľ����ص����γɵ��������
ʾ��:
����: -3, 0, 3, 4, 0, -1, 9, 2
���: 45
*/

/*
�ܼ򵥵����⣬�����ж���������û���غϣ�û���غϾ�ֱ��������
����Ҫ�ҳ��غϲ��ֵ������������꣬���������غϲ������
���շ��ؾ���1���-�غ����+����2���
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