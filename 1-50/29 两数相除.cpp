#include<iostream>
#define MAX 0X7FFFFFFF
#define MIN 0X80000000

//29 两数相除

/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 dividend 除以除数 divisor 得到的商。
示例 1:
输入: dividend = 10, divisor = 3
输出: 3

示例 2:
输入: dividend = 7, divisor = -3
输出: -2
*/

//这个题还是很难的，刚拿到手没有想法，按照别人的想法写的
//主要是考察位运算，计算机基础的东西，说明我基础还是不扎实
int divide(int dividend, int divisor) {
	//如果dividend等于负最大值，而除数是-1，直接返回max
	if (dividend == MIN && divisor == -1)
		return MAX;
	//将除数和被除数都取绝对值
	unsigned long temp1 = abs(dividend);
	unsigned long temp2 = abs(divisor);
	if (temp1 < temp2)
		return 0;
	//flag标记结果是正还是负，若为负，在计算完后要取反
	int flag = 1;
	if ((dividend & divisor & MIN) == 0 && (dividend < 0 || divisor < 0))
		flag = -1;
	//i作为参照，用来体现temp1和temp2的差距
	int i = 1;
	unsigned long d = temp2;


	if (d == 1)
		i = temp1;
	else {
		//巧妙的用i来体现temp1和temp2的差距
		while (temp1 > d) {
			d <<= 1;
			i <<= 1;
		}
		//若temp1小于d，说明走过了。i和d各退回一步，继续进行除法
		//而如果等于就直接return i就可以了
		if (temp1 < d)
			i = (i >> 1) + divide(temp1 - (d >> 1), temp2);
	}

	if (flag < 0)
		i = -i;

	return i;
}

int main()
{
	int res = divide(-2147483648, 2);
	return 0;
}