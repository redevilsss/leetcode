#include<iostream>
#include<vector>
#include<string>
using namespace std;

// 38 报数
/*
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。
其前五项如下：
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
注意：整数顺序将表示为一个字符串。
示例 1:
输入: 1
输出: "1"

示例 2:
输入: 4
输出: "1211"
*/

//主要考察对字符串的处理，通过循环来实现，其实就是循环统计上一个结果中每个连续数出现的次数
//定义一个c保存当前字符，如果下一个字符还是c，则次数加1，否则次数就是1 字符串里输入本次结果
//更新c，继续循环
string countAndSay(int n) {
	if (n == 1)
		return "1";
	if (n == 2)
		return "11";
	string temp = "11";
	while (n>2)
	{
		string s = "";
		int i = 0;
		int num = 0;
		int c = temp[0] - '0';
		while (i<temp.size())
		{
			//如果c的值等于当前字符，增加重复次数
			if (c == temp[i] - '0')
			{
				num++;
				i++;
			}
			else
			{
				s += to_string(num);
				s += to_string(c);
				num = 0;
				c = temp[i] - '0';//此时c不等于当前字符，才会走到这一步
				//更新c的值继续循环
			}
		}
		//最后一次结果肯定没有保存，因为只有if语句里面会改变i，退出前最后一次到的是if语句
		//把最后一次的次数和字符也加上，完成一次循环，然后更新temp，继续处理temp
		s += to_string(num);
		s += to_string(c);
		temp = s;
		n--;
	}
	return temp;
}
int main()
{
	string res = countAndSay(5);
	return 0;
}