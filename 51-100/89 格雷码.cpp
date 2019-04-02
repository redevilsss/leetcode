#include<iostream>
#include<vector>
using namespace std;

//89 格雷码

/*
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。
示例 :
输入: 2
输出: [0,1,3,2]
*/


//方法一：用公式。整数 n 的格雷码是 n ⊕ ( n/2)。(实际是由n的自然二进制码转换为格雷码，然后由格雷码转换为十进制数
vector<int> grayCode(int n) {
	//格雷码的生成公式，通过位运算
	//G(i)=i^(i/2)
	vector<int> res;
	for(int i=0;i<(1<<n);i++)//因为下面将i右移了一次，这里应该左移回来
		res.push_back(i^(i>>1));
	return res;
}

/*方法二：通过递归推导，由n-1位格雷码得出
这种方法基于格雷码是反射码的事实，利用递归的如下规则来构造：
1位格雷码有两个码字
(n+1)位格雷码中的前2^n个码字等于n位格雷码的码字，按顺序书写，加前缀0
(n+1)位格雷码中的后2^n个码字等于n位格雷码的码字，按逆序书写，加前缀1
*/
vector<int> grayCode(int n)
{
	vector<int> result;
	result.push_back(0);
	for (int i = 0; i < n; i++)
	{
		//这里的highest_bit类似于掩码，后一半的数其实就是给前一半逆序补1，这里的highest_bit就是起补1的作用
		const int highest_bit = 1 << i;//2^i位的前2^(i-1)位不需要改变，后2^(i-1)位为用1<<i与前2^(i-1)位的逆序取或
		for (int j = result.size() - 1; j >= 0; j--) // 要反着遍历，才能对称，
		{
			result.push_back(highest_bit | result[j]);
		}
	}
	return result;
}