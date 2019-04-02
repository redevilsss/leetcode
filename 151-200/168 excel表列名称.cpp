#include<iostream>
#include<vector>
using namespace std;

//168 excel表列名称
/*给定一个正整数，返回它在 Excel 表中相对应的列名称。
例如，
1->A
2->B
3->C
...
26->Z
27->AA
28->AB
...
*/

//这道题需要注意的地方就是26对应的是z，遍历的时候需要减1再求余，然后余数直接加A就可以
//直接除的话如果n时26 remain会是0，对应的就不是z了
//或者修改一下后面的部分，如果remain是0，就加z
string convertToTitle(int n) {
	string res = "";
	int carry = 0;
	while (n != 0)
	{
		n--;
		int remain = n % 26;
		n /= 26;
		res += remain + 'A';
	}
	reverse(res.begin(), res.end());
	return res;
}