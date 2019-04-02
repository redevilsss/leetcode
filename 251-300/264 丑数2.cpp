#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//264 丑数2
/*
编写一个程序，找出第 n 个丑数。
丑数就是只包含质因数 2, 3, 5 的正整数。
示例:
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
*/

//思路：可以逐个判断每个数是不是丑数，但是这样太慢
//用空间换时间，保存之前丑数的值，用之前的丑数去计算新的丑数，创建数组，里面的数字都是排好序的丑数，每个丑数都是前面的丑数乘以2、3或5得到的
//如何确保里面的丑数已经排好序？
//假设数组中已经有若干排好序的丑数，把最大的记为M
//考虑把已有的丑数乘2，找到第一个大于M的丑数M1，同理乘3和5，得到M3和M5，M2、M3、M5这三个数的最小值就是下一个丑数
//但是每一次对所有丑数进行乘运算也比较麻烦，所以定义指针，每次只进行少量的乘法和比较运算，控制指针指向，最终实现寻找丑数
int nthUglyNumber(int n) {
	if (n<1)
		return -1;
	int* uglyNumber = new int[n];
	uglyNumber[0] = 1;
	int nextUglyIndex = 1;
	int* multiply2 = uglyNumber;
	int* multiply3 = uglyNumber;
	int* multiply5 = uglyNumber;
	while (nextUglyIndex<n)
	{
		//举个例子方便理解为什么要这么做，初始时都指向1
		//最小值为2，则multiply2++，指向2，再下一步最小值为3，则multiply3++，再下一步为5，multiply2++，multiply5++
		//也就是说每次新的元素进入ugly数组后，当前指针所指的数字乘各自的因子(2、3或5)必须都大于这个新的元素，借此跳过不是丑数的数
		//在下一个的时候比较的是3*2，2*3和2*5，最小值是6，此时则multiply2++指向5，multiply3++指向3
		//可以看到这种方法没有漏过一个数，也不会多算一个数，所有的三个指针指到的都是加入数组的丑数，乘的也都是丑数因子，所以不会多算一个数
		//有当前数组已存储的元素作为参照，严格按照位置顺序一步步递进，也不会错过任何一个
		int Min = min(*multiply2 * 2, min(*multiply3 * 3, *multiply5 * 5));
		uglyNumber[nextUglyIndex] = Min;
		while (*multiply2 * 2 <= Min)
			multiply2++;
		while (*multiply3 * 3 <= Min)
			multiply3++;
		while (*multiply5 * 5 <= Min)
			multiply5++;
		++nextUglyIndex;
	}
	int ugly = uglyNumber[n - 1];
	delete[] uglyNumber;
	return ugly;
}