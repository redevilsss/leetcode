#include<iostream>
#include<string>
#include<vector>
using namespace std;

//13 罗马数字转整数

/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。
但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:
输入: "III"
输出: 3

示例 2:
输入: "IV"
输出: 4

示例 3:
输入: "IX"
输出: 9

示例 4:
输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.

示例 5:
输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/

//方法一
int romanToInt(string s) {
	int res = 0;
	int i = 0;
	//遍历字符串求值
	while (i<s.length())
	{
		//先列出出现特殊情况时的取值
		if (s[i] == 'I'&&s[i + 1] == 'V')
		{
			res += 4;
			i += 2;
		}
		else if (s[i] == 'I'&&s[i + 1] == 'X')
		{
			res += 9;
			i += 2;
		}
		else if (s[i] == 'X'&&s[i + 1] == 'L')
		{
			res += 40;
			i += 2;
		}
		else if (s[i] == 'X'&&s[i + 1] == 'C')
		{
			res += 90;
			i += 2;
		}
		else if (s[i] == 'C'&&s[i + 1] == 'D')
		{
			res += 400;
			i += 2;
		}
		else if (s[i] == 'C'&&s[i + 1] == 'M')
		{
			res += 900;
			i += 2;
		}
		//再列举一般情况
		else switch (s[i])
		{
		case 'I':res += 1; i += 1; break;
		case 'V':res += 5; i += 1; break;
		case 'X':res += 10; i += 1; break;
		case 'L':res += 50; i += 1; break;
		case 'C':res += 100; i += 1; break;
		case 'D':res += 500; i += 1; break;
		case 'M':res += 1000; i += 1; break;
		}

	}
	return res;
}

//方法二：方法二与方法一没有本质上的差别，方法一边走边算，方法二先存后算，代码更简练
int romanToInt(string s)
{
	int n[s.size() + 1];
	n[s.size()] = 0;
	int res = 0;
	for (int i = 0; i<s.length(); i++)
	{
		switch (s[i])
		{
		case 'I':n[i] = 1;   break;
		case 'V':n[i] = 5;   break;
		case 'X':n[i] = 10;  break;
		case 'L':n[i] = 50;  break;
		case 'C':n[i] = 100; break;
		case 'D':n[i] = 500; break;
		case 'M':n[i] = 1000; break;
		}
	}
	//对出现4 和 9的处理方法比较简练，不像方法1一样繁杂，有概括性 
	for (int i = 0; i<s.length(); i++)
	{
		if (n[i]<n[i + 1])
		{
			res = res + n[i + 1] - n[i];
			i++;
		}
		else
			res += n[i];
	}
	return res;
}