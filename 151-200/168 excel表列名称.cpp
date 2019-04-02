#include<iostream>
#include<vector>
using namespace std;

//168 excel��������
/*����һ������������������ Excel �������Ӧ�������ơ�
���磬
1->A
2->B
3->C
...
26->Z
27->AA
28->AB
...
*/

//�������Ҫע��ĵط�����26��Ӧ����z��������ʱ����Ҫ��1�����࣬Ȼ������ֱ�Ӽ�A�Ϳ���
//ֱ�ӳ��Ļ����nʱ26 remain����0����Ӧ�ľͲ���z��
//�����޸�һ�º���Ĳ��֣����remain��0���ͼ�z
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