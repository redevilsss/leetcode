#include<iostream>
#include<vector>
using namespace std;

//201 数字范围按位与

/*
给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。
示例 1:
输入: [5,7]
输出: 4
*/

/*
这道题的实现方法有很多
我用的方法的思路来自之前有一道计算二进制数1的个数的题
n&(n-1)表示将n最右的1置0
那么在此题中，只要n大于m，我就把n最右的一个1置0，等到n不再大于m的时候返回n，这个n就是所求的数
为什么呢？
这道题万万不可一个数一个数去试而是应该一位一位去判断
举个例子 5，6，7，8，...,15
从16到5直接相与需要11次，而如果按位去与，第一步就是把15变成了14，继续，把14变成12，再变成8，再变成0，此时退出循环，返回0
就拿从8-0这一段来说，按位与就一次，其效果就等于从8一直与到5
*/

int rangeBitwiseAnd(int m, int n)
{
	while (n>m)
		n &= n - 1;
	return n;
}