#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//313 超级丑数

/*
编写一段程序来查找第 n 个超级丑数。
超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。
示例:
输入: n = 12, primes = [2,7,13,19]
输出: 32
解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
*/


/*
思路和264题丑数一致，只不过这里给的因子是列表给出并不确定
那么需要和264题一样构造指针，有多少个因子就构造多少个，保存在数组p中，初始值都为0
其中p[index]表示当前因子prime[i]的指针，类似于264题中的mutiply2、mutiply3和mutiply5
定义uglyNumber数组长度为n，第一个数为1，所有的指针p[i]初始状态都指向0
开始遍历，每一步分三步进行：
1.查找下一个丑数，这个数是min(primes[i]*uglyNumbers[p[index]]),i从0到primes.size()
2.更新uglyNumbers[nextUglyIndex]
3.更新指针的指向，当primes[i]*uglyNumbers[p[index]等于最小值时，将p[index]++,使其表示的下标前进1位

我的一点理解：这道题和264题的不同在于，没有明确的说明哪些数构成丑数，而是通过数组给出，继续按照多指针的思路走，
首先要做的就是构造指针，有多少个因子就有多少个指针，正好指针数组p的下标能和prime的元素对应上
接下来要做的就和264题几乎一样了，为什么这种方法不会重复也不会缺失之前已经说过了，因为是严格按照升序来进行排列的，
所有uglyNumbers数组的元素都是丑数，而每次乘的也都是丑数，所以数组元素只可能会是丑数，指针的更新避免了重复，而每次选取最小值保证了不会缺失
*/

int nthSuperUglyNumber(int n, vector<int>& primes) {
	if (primes.size() == 0 || n<1)
		return 0;
	vector<int> uglyNumbers(n, 0);
	uglyNumbers[0] = 1;
	int nextUglyIndex = 1;
	vector<int> p(primes.size(), 0);
	while (nextUglyIndex<n)
	{
		int Min = INT_MAX;
		int index = 0;
		//找当前下一个可能的丑数，有多少个指针就有多少个可能的取值，最终选取其中最小的
		for (int i = 0; i<primes.size(); i++)
		{
			if ((primes[i] * uglyNumbers[p[index]])<Min)
				Min = primes[i] * uglyNumbers[p[index]];
			index++;
		}
		//更新下一个丑数值
		uglyNumbers[nextUglyIndex] = Min;
		//遍历更新指针位置，使得当前指针所指位置再乘对应的因子都大于Min
		index = 0;
		for (int num : primes)
		{
			if (Min == num*uglyNumbers[p[index]])
				++p[index];
			index++;
		}
		nextUglyIndex++;
	}
	return uglyNumbers[n - 1];
}
int main()
{
	vector<int> v = { 2,7,13,19 };
	int res = nthSuperUglyNumber(12,v);
	return 0;
}