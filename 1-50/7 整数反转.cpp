
#include<iostream>
#include<vector>
using namespace std;
// 7 整数反转
/*给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:
输入: 123
输出 : 321
示例 2 :
输入 : -123
输出 : -321
示例 3 :
输入 : 120
输出 : 21
*/

//核心思想：重点在于对正数和负数的无差别对待，看似要面对最低为为0，正负号的问题
//其实直接进行一次循环就可以搞定，每次除完得到的最低位正好是反转后的最高位
//若超出计算范围则返回0
int reverse(int x) 
{
	long long ans = 0;
	while (x != 0) {
		ans = ans * 10 + x % 10;
		x /= 10;
	}
	return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;
}