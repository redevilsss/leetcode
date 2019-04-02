#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;
//187 重复的DNA序列
/*
所有 DNA 由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。
编写一个函数来查找 DNA 分子中所有出现超过一次的10个字母长的序列（子串）。
示例 :
输入: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出 : ["AAAAACCCCC", "CCCCCAAAAA"]
*/

//这道题是找出现次数超过一次的10个字母长的序列
/*
思路1，就是直接刚，利用map的键值对或者set的重复元素插入失败来实现
以set为例，创建两个set，当set1中插入不进去的时候插入到set2，那么遍历完成后set2中保存的就是出现超过一次的字串
*/

vector<string> findRepeatedDnaSequences(string s) {
	if (s.length() < 10)
		return {};
	set<string> s1;
	set<string> s2;
	for (int i = 0; i<s.length()-9; i++)
	{
		string temp = s.substr(i,10);
		auto ret = s1.insert(temp);
		if (!ret.second)
			s2.insert(temp);
	}
	return vector<string>(s2.begin(),s2.end());
}

//方法二
/*
前面的方法复杂度很高，用到了比较复杂的数据结构，效率最好的代码是用类似于滑窗的方法来做的
因为只有四种不同的结构，可以用0 1 2 3来代替，也就是两位二进制来表示，那么长度为10的串就需要20位的二进制来表示，再定义一个1<<20位的数组来表示滑窗表示的数字是否出现
先构造一个数组来表示前10位，然后把标志矩阵中以滑窗当前值为下标的位置的值置为true
遍历数组，滑窗每移动一次，对应字符串的第一位要去掉，加上接下来的一位，滑窗的值也改变
每次对当前滑窗表示的数字进行判断，如果为true，说明之前已经出现过，直接insert,否则将值置位true;
*/
int ctoi(char c)
{
	switch (c)
	{
		case 'A':return 0;
		case 'C':return 1;
		case 'G':return 2;
		case 'T':return 3;
	}
}

vector<string> findRepeatedDnaSequences(string s) {
	unordered_set<string> res;
	vector<bool> nums(1 << 20, false);
	int mask = 1 << 20 - 1;//类似于掩码，用来保留低20位
	int temp = 0;
	//构造初始滑窗
	for (int i = 0; i < 10; i++)
		temp = (temp << 2 | s[ctoi(i)]);
	nums[temp] = true;
	for (int i = 10; i < s.length(); i++)
	{
		temp = (temp << 2)&mask | s[ctoi(i)];//temp先左移两位和当前字符表示的二进制数相或，再与mask相与用来保留低20位，也就是每次计算的都是当前10个字符对应的值
		//当前位为true,插入，哈希表是无重复值的，只会插入一次
		if (nums[temp])
			res.insert(s.substr(i - 9, 10));
		else
			nums[temp] = true;
	}
	return vector<string>(res.begin(), res.end());
}
int main()
{
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	findRepeatedDnaSequences(s);

	return 0;
}