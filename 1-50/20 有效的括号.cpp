#include<iostream>
#include<stack>
#include<string>
using namespace std;
// 20  ��Ч������

/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ע����ַ����ɱ���Ϊ����Ч�ַ�����

ʾ�� 1:
����: "()"
��� : true

ʾ�� 2 :
���� : "()[]{}"
��� : true

ʾ�� 3 :
���� : "(]"
��� : false

ʾ�� 4 :
���� : "([)]"
��� : false

ʾ�� 5 :
���� : "{[]}"
��� : true
*/

//����˼�룺��ջ��ѹ�뵯����ģ���жϹ��̣�������ͬ�ľ͵�����������ջ�ǲ���Ϊ��
bool isValid(string s) {
	if (s.size() == 0)
		return true;
	//��Ԫ�ظ���Ϊ���������϶���Ч
	if (s.size() % 2 != 0)
		return false;
	stack<char> temp;
	//����Ԫ�أ������ж�
	for (int i = 0; i<s.size(); i++)
	{
		//��Ϊջ�պͷǿ����������ջ����ֻ�ܽ������ţ����򱨴�
		int flag = temp.empty();
		if (flag)
		{
			if (s[i] == '}' || s[i] == ']' || s[i] == ')')
				return false;
			else
				temp.push(s[i]);
		}
		//ջ�ǿ�ʱҪ�ж���һ��Ԫ���Ƿ���ջ��Ԫ����ԣ�����򵯳�ջ��Ԫ�أ�����ѹ����һ��Ԫ��
		else
		{
			if (temp.top() == '['&&s[i] == ']')
				temp.pop();
			else if (temp.top() == '('&&s[i] == ')')
				temp.pop();
			else if (temp.top() == '{'&&s[i] == '}')
				temp.pop();
			else
				temp.push(s[i]);
		}
	}
	return temp.empty();
}

int main()
{
	string s = "()";
	bool res = isValid(s);
	return 0;
}
