#include<iostream>
#include<string>
using namespace std;

//171 列表序号
/*
给定一个Excel表格中的列名称，返回其相应的列序号。
例如，
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
*/

//和168正好是一对，一个是数字转字符串一个是字符串转数字
//因为A对应的是1，所以-A转成数字后要+1，遍历即可
long titleToNumber(string s)
{
	long num = s[0] - 'A' + 1;
	for (int i = 1; i<s.length(); i++)
	{
		num = num * 26 + s[i] - 'A' + 1;
	}
	return num;
}
