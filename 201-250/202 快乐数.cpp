#include<iostream>
#include<vector>
#include<set>
using namespace std;

//202 快乐数

/*
编写一个算法来判断一个数是不是“快乐数”。
一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。
示例:
输入: 19
输出: true
解释:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

/*
方法一：这道题的关键就是判断当前是不是陷入了循环，可以利用一个set来保存每次计算后的数
如果当前计算的数之前已经出现过，就break，否则就将这个新值插入set
break后进行判断，如果n是1就返回true，否则就返回false
*/
bool isHappy(int n) {
	set<int> s;
	while (n != 1)
	{
		int temp = 0;
		while (n)
		{
			temp += (n % 10)*(n % 10);
			n /= 10;
		}
		n = temp;
		if (s.count(temp))
			break;
		else
			s.insert(temp);
	}
	return n == 1;
}


//方法二：还记得之前的快慢指针法吗，这里也可以用，分别将n每次变换1次和2次，如果某一刻两次的值相等，这时要么是1，要么在死循环里
//什么时候是1呢？如果n是快乐数，因为快指针走的快，当快指针的值变为1时，慢指针才走了一半，此后快指针一直是1，而慢指针也会再继续走变成1
//否则就是快指针和慢指针都进了死循环，当快指针比慢指针多走一圈循环的时候，两者相等

int calcSum(int n)
{
	int temp = 0;
	while (n)
	{
		temp += (n % 10)*(n % 10);
		n /= 10;
	}
	return temp;
}

bool isHappy(int n) {
	int slow = n;
	int fast = n;
	do 
	{
		slow = calcSum(slow);
		fast = calcSum(fast);
		fast = calcSum(fast);
	} while (slow != fast);
	return slow == 1;
}


//方法三：
//这道题其实就是找规律，百度了一下，说只要某一步出现4，就会进入死循环，而当出现1时就可以返回true
//所以构造一个循环，进入条件是n不等于1或4，只要一旦n等于1或4，就直接根据n的值确定返回值，即n为1返回true，否则返回false
bool isHappy(int n) {
	while (n != 1 && n != 4)
	{
		int temp = 0;
		while (n)
		{
			temp += (n % 10)*(n % 10);
			n /= 10;
		}
		n = temp;
	}
	return n == 1;
}