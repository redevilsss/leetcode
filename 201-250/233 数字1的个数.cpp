#include<iostream>
#include<algorithm>
using namespace std;

//233 数字1的个数
/*
给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
示例:
输入: 13
输出: 6
解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
*/


/*
思路：
对一个数abcde来说，题目要求0-abcde中1的个数，可以先划分为0-e，e-de，de-cde，cde-bcde，bcde-abcde
然后再分别去讨论，从bcde-abcde开始，1出现有两种情况，1出现在最高位和出现在其他位置，具体的计算在函数中有详细说明
计算完后将原数除10000，剩下bcde，递归以此类推，直到e，当长度为1时返回1，逐层返回最终得到结果

*/
//获取n的位数
int getLength(int n)
{
	int len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return len;
}
//递归计算
int countDigitOne(int n) {
	if (n<1)
		return 0;
	int len = getLength(n);
	if (len == 1)
		return 1;
	int temp = pow(10, len - 1);
	int first = n / temp;
	//获取最高位数字
	//当前最高位的值不同，最高位出现1的次数也不同
	//最高位为1，则最高位出现1的个数为n除temp的余数+1，以12345为例
	//最高位出现1的个数为12345%10000+1=2346
	//如果最高位大于1，则最高位出现1的个数为temp
	int firstNumOf1 = first == 1 ? n%temp + 1 : temp;
	// 在介于n%tmp到n之间的数字中，除了最高位为1，其余各个数字分别为1的总数和
	//举个例子，一个数12345，则firstNumOf1就是2345-12345之间最高位出现1的次数
	//otherNumOf1是2345-12345之间除最高位之外出现1的次数，RecursiveOf1表示的是1-2345上1的次数
	//为什么是first*(len-1)*(temp/10)?
	//first决定了将这些数分成多少块，如果数是12345，这部分求的就是2345-12345中1的个数
	//如果数是22345，这部分求的就是2345-12345和12345-22345两部分
	//因为每一位都可能为1，所以有len-1种可能，而每一种可能下其余为止都可以取0-9这10个数
	//所以总数如公式表达，这里求的是1的个数，不是数字的个数，要注意
	int otherNumOf1 = first*(len - 1)*(temp / 10);
	return firstNumOf1 + otherNumOf1 + countDigitOne(n%temp);
}