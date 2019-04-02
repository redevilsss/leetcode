#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//150 �������ʽ��ֵ

/*
�����沨����ʾ��������ʽ��ֵ��
��Ч����������� +, -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��
˵����
��������ֻ�����������֡�
�����沨�����ʽ������Ч�ġ����仰˵�����ʽ�ܻ�ó���Ч��ֵ�Ҳ����ڳ���Ϊ 0 �������
ʾ�� 1��
����: ["2", "1", "+", "3", "*"]
���: 9
����: ((2 + 1) * 3) = 9
*/

//��������֪��ɶ���沨�����ʽ�ͺܼ�...
//���沨�����ʽ�Ĺ��̾���������ջ���������ŵ��������������㣬�������ջ��ֱ����������꣬ջ��Ԫ�ؾ��ǽ������ʱջ����Ҳ����һ��Ԫ�أ�
//�������־���ջ���������ž͵������μ��㣬�����ٰѽ���Ż�ȥ
int evalRPN(vector<string>& tokens) {
	stack<int> s;
	for (int i = 0; i<tokens.size(); i++)
	{
		if (tokens[i] == "+")
		{
			int s1 = s.top();
			s.pop();
			int s2 = s.top();
			s.pop();
			s.push(s2 + s1);
		}
		else if (tokens[i] == "-")
		{
			int s1 = s.top();
			s.pop();
			int s2 = s.top();
			s.pop();
			s.push(s2 - s1);
		}
		else if (tokens[i] == "*")
		{
			int s1 = s.top();
			s.pop();
			int s2 = s.top();
			s.pop();
			s.push(s2*s1);
		}
		else if (tokens[i] == "/")
		{
			int s1 = s.top();
			s.pop();
			int s2 = s.top();
			s.pop();
			s.push(s2 / s1);
		}
		else
			s.push(stoi(tokens[i]));
	}
	return s.top();
} 