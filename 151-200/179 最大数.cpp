#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//179 �����

/*
����һ��Ǹ������������������ǵ�˳��ʹ֮���һ������������
ʾ�� 1:
����: [10,2]
���: 210
*/

//��ʵ�����Զ������򣬱Ƚ�a+b��b+a�ĸ��������+��������һ�飩
//�ȿ���ѡ����ת�ַ����ٱȣ�Ҳ����ֱ�ӱ�����

//����һ����ָoffer�Ͼ��������Ƶķ�������ת�ַ������ٱ��ַ���������ж������ַ�����һλ�ǲ���0�������0�Ǿ�ֱ�ӷ��ء�0�������򷵻�res
//��Ϊ�����һλ���λ��0���������ַ����Ͷ���0
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




//��������ֱ�ӱȽ����������Ӻ�Ĵ�С
string largestNumber(vector<int>& nums) {
	//�����˼·���Ǽ���ÿ������λ������ôa��b��ֵ����a*10��b��λ���η�����������е�b2����ͬ��
	//b��a��ֵ����b*a2+a
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
