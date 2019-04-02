#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

//225 �ö���ʵ��ջ

/*
ʹ�ö���ʵ��ջ�����в�����
push(x) -- Ԫ�� x ��ջ
pop() -- �Ƴ�ջ��Ԫ��
top() -- ��ȡջ��Ԫ��
empty() -- ����ջ�Ƿ�Ϊ��
*/

/*
����������ʵ��ջ����֤����ʱ�̶�һ������Ϊ��
��ĳʱ�̿ն���Ϊq1���ǿն���Ϊq2
pushʱ��Ԫ�طŵ��ǿն���q2��
popʱ����ջ��Ԫ�أ���q2��backԪ�أ�Ϊ�˵�����Ԫ�أ�����ǰ���q2.size()-1��Ԫ�ض�����q1�У��ٵ�����Ԫ��
topʱ���ص�ǰջ��Ԫ�ص���������ֱ�ӷ���q2��backԪ��
*/

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
	}
	/** Push element x onto stack. */
	void push(int x) {
		if (!q2.empty())
			q2.push(x);
		else
			q1.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (q2.empty())
		{
			while (q1.size()>1)
			{
				int temp = q1.front();
				q1.pop();
				q2.push(temp);
			}
			int res = q1.front();
			q1.pop();
			return res;
		}
		else
		{
			while (q2.size()>1)
			{
				int temp = q2.front();
				q2.pop();
				q1.push(temp);
			}
			int res = q2.front();
			q2.pop();
			return res;
		}
	}

	/** Get the top element. */
	int top() {
		if (q2.empty())
			return q1.back();
		else
			return q2.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty() && q2.empty();
	}
private:
	queue<int> q1;
	queue<int> q2;
};


int main()
{
	MyStack s;
	s.push(1);
	s.push(2);
	int res1=s.top();
	int res2=s.pop();
	bool res3 = s.empty();
	return 0;
}
