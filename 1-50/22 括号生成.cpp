#include<iostream>
#include<vector>
using namespace std;
// 22 ��������

/*���� n �����������ŵĶ���������д��һ��������ʹ���ܹ��������п��ܵĲ�����Ч��������ϡ�
���磬���� n = 3�����ɽ��Ϊ��
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

//˼�룺dfs+��֦
vector<string> generateParenthesis(int n) {
	vector<string> res;
	func(res, "", 0, 0, n);
	return res;
}
//l��ʾ��ǰ����������r��ʾ��ǰ����������n��ʾ���Ŷ���
void func(vector<string>& res, string str, int l, int r, int n)
{
	//�����Ŵ���n�������Ŵ���n�������Ŵ��������ţ���Ч�����˳���������������
	if (l>n || r>n || r>l)
		return;
	if (l == n&&r == n)//�������Ŷ�Ϊn��ʱ��ѹ���ʱstr������
	{
		res.push_back(str);
		return;
	}
	//�ֱ�ݹ������µĺ������̣�����������l��1������������r��1
	func(res, str + '(', l + 1, r, n);
	func(res, str + ')', l, r + 1, n);
	return;