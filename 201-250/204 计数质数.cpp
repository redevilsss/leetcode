#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

//204 计数质数
/*
统计所有小于非负整数 n 的质数的数量。
示例:
输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/


/*
用到素数筛方法
思想就是定义一个与当前数同长的数组flag，除前两个位置全设为1
然后从第三个位置，也就是2开始遍历
如果flag[i]为1，把下标从i*i开始的所有位置的数值都置零,为什么不是从i*2、i*3呢？
因为此前这些位置已经置零过了，可以用笔画画验证一下
然后继续如此，直到遍历完数组
此时数组中留下的所有值为1的位置对应的下标就是当前1~n之间的素数
*/
int countPrimes(int n) {
	if (n<3)
		return 0;
	vector<int> flag(n, 1);//表示0~n-1
	flag[0] = 0;
	flag[1] = 0;
	for (long long i = 2; i<n; i++)
	{
		if (flag[i] == 1)
		{
			for (long long j = i*i; j<n; j += i)
				flag[j] = 0;
		}
	}
	int res = accumulate(flag.begin(), flag.end(), 0);
	return res;
}


int main()
{
	int res = countPrimes(10);
	return 0;
}