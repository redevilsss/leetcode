#include<iostream>
#include<string>
#include<vector>
using namespace std;


//6 Z字形变换
/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:
输入: s = "LEETCODEISHIRING", numRows = 3
输出 : "LCIRETOESIIGEDHN"

示例 2 :
输入 : s = "LEETCODEISHIRING", numRows = 4
输出 : "LDREOEIIECIHNTSG"
解释 :
	L     D     R
	E   O E   I I
	E C   I H   N
	T     S     G
*/


//思想：核心在于一个循环中行数的控制，以上面示例2为例
//LEETCO为一个循环，一个循环的字符数为行数*2-2
//0-3时为正序，而4 5为逆序，LEETCO分别放在下标为 0 1 2 3 2 1的行
//也就是说核心在于如何实现这个序列
//如下所示
string convert(string s, int numRows) {
	vector<string> vec(numRows);
	string res;
	int check = numRows * 2 - 2;
	for (int i = 0; i<s.length(); i++)
	{
		//当i在循环中的位置为0-numRows(不含numRows)，则直接写入行数%循环数中
		if (i%check<numRows)
			vec[i%check]+=s[i];
		else//否则需要放在循环数-当前下标%循环数处
			vec[check - i%check]+=s[i];

	}
	//连成字符串
	for (int i = 0; i < numRows; i++)
		res += vec[i];
	return res;
	
}

int main()
{
	string s = "LEETCODEISHIRING";
	string res = convert(s, 3);
	return 0;
}