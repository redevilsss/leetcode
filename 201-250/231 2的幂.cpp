#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//231 2的幂
//给定一个整数，编写一个函数来判断它是否是 2 的幂次方。


/*
非常简单...然而我的方法比较弱智，看了大佬的一步实现，难受
直接看n&(n-1)是不是0，如果是2的幂，那么n&(n-1)就等于0
*/

bool isPowerOfTwo(int n) {
	return (n>0) && (!(n&(n - 1)));
}

bool isPowerOfTwo(int n) {
	if (n <= 0)
		return false;
	int mask = 1;
	while (mask <= n)
	{
		if ((mask&n) == 0)
		{
			mask = mask << 1;
		}
		else
			break;
	}
	if (mask >= n)
		return true;
	else
		return false;
}