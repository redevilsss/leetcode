#include<iostream>
using namespace std;

//  9 回文数
/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:
输入: 121
输出: true
示例 2:
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
*/

//首先要知道，负数肯定不是回文数，先排除
bool isPalindrome(int x) {
	if (x<0)
		return false;
	int res = 0;
	int temp = x;
	//这里与第7题一样，当x为正数时，将其反转看与原数是否一样
	while (temp)
	{
		res = res * 10 + temp % 10;
		temp /= 10;
	}
	if (res == x)
		return true;
	else
		return false;
}

int main()
{
	bool res = isPalindrome(121);
	return 0;
}