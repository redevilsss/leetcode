#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//231 2����
//����һ����������дһ���������ж����Ƿ��� 2 ���ݴη���


/*
�ǳ���...Ȼ���ҵķ����Ƚ����ǣ����˴��е�һ��ʵ�֣�����
ֱ�ӿ�n&(n-1)�ǲ���0�������2���ݣ���ôn&(n-1)�͵���0
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