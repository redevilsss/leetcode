#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string addBinary(string a, string b) {
	if (a.length()<b.length())//a是较长的字符串
	{
		string temp = a;
		a = b;
		b = temp;
	}
	int dif = a.length() - b.length();
	string s;
	while (dif--)
		s += '0';
	b = s + b;
	int index = a.length() - 1;
	string res;
	int carry = 0;
	while (index >= 0)
	{
		int sum = a[index] - '0' + b[index] - '0' + carry;
		carry = 0;
		if (sum > 1)
		{
			carry = 1;
			sum -= 2;
		}
		res += ('0' + sum);
		index--;
	}
	if (carry == 1)
		res += '1';
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	string a = "1010";
	string b = "1011";
	string res = addBinary(a, b);
	return 0;
}