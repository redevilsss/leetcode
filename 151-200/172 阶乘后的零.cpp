#include<iostream>
#include<vector>
using namespace std;

//172 阶乘后的零
/*
给定一个整数 n，返回 n! 结果尾数中零的数量。
示例 1:
输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。
*/

//只有2和5能构成结果末尾的0，而5的数量比2少，所以是5的多少觉得阶乘中末尾0的个数
//要特别注意5的次方，比如25 125，25能凑两个0，125能凑3个0，625也能凑3个0
int trailingZeroes(int n) {
	int res = 0;
	while (n / 5)
	{
		res += n / 5;
		n /= 5;
	}
	return res;
}