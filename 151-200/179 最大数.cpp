#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//179 最大数

/*
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
示例 1:
输入: [10,2]
输出: 210
*/

//其实就是自定义排序，比较a+b和b+a哪个大（这里的+是连接在一块）
//既可以选择先转字符串再比，也可以直接比数字

//方法一：剑指offer上就是用类似的方法，先转字符串，再比字符串，最后判断所得字符串第一位是不是0，如果是0那就直接返回“0”，否则返回res
//因为如果第一位最高位是0，那整个字符串就都是0
static bool compare(const int a, const int b)
{
	string str1 = to_string(a);
	string str2 = to_string(b);
	return str1 + str2>str2 + str1;
}

string largestNumber(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	sort(nums.begin(), nums.end(), compare);
	string res = "";
	for (int i = 0; i<nums.size(); i++)
		res += to_string(nums[i]);
	int len = res.size();
	int begin = 0;
	while (begin<len&&res[begin] == '0')
		++begin;
	if (begin == len)
		return "0";
	else
		return res.substr(begin, len);
}




//方法二：直接比较数字相连接后的大小
string largestNumber(vector<int>& nums) {
	//这里的思路就是计算每个数的位数，那么a接b的值就是a*10的b的位数次方（下面程序中的b2），同理
	//b接a的值就是b*a2+a
	sort(nums.begin(), nums.end(), [](int a, int b)
	{
		int a1 = a;
		long a2 = 10;
		while (a1 >= 10)
		{
			a1 /= 10;
			a2 *= 10;
		}

		int b1 = b;
		long b2 = 10;
		while (b1 >= 10)
		{
			b1 /= 10;
			b2 *= 10;
		}
		return a*b2 + b>b*a2 + a;
	});

	if (nums[0] == 0)
	{
		return "0";
	}
	string res = "";
	for (int i = 0; i < nums.size(); i++)
	{
		res += to_string(nums[i]);
	}
	return res;
}
