#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

//232 ��ջʵ�ֶ���

/*
ʹ��ջʵ�ֶ��е����в�����
push(x) -- ��һ��Ԫ�ط�����е�β����
pop() -- �Ӷ����ײ��Ƴ�Ԫ�ء�
peek() -- ���ض����ײ���Ԫ�ء�
empty() -- ���ض����Ƿ�Ϊ�ա�
*/

//������ջʵ�ֶ��У�s1Ϊ����ջ��s2Ϊ��ջ
//pushԪ�ؽ�s1��popԪ�ش�s2��
//��popԪ�ص�s2Ϊ��ʱ����s1����s2
//��ջ�ٳ�ջ˳�򲻱�
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		s1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (s2.empty())
		{
			while (!s1.empty())
			{
				int temp = s1.top();
				s1.pop();
				s2.push(temp);
			}
		}
		int res = s2.top();
		s2.pop();
		return res;

	}

	/** Get the front element. */
	int peek() {
		if (s2.empty())
		{
			while (!s1.empty())
			{
				int temp = s1.top();
				s1.pop();
				s2.push(temp);
			}
		}
		return s2.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s1.empty() && s2.empty();
	}
private:
	stack<int> s1;
	stack<int> s2;
};

int main()
{
	MyQueue q;
	q.push(1);
	q.push(2);
	int res1=q.peek();
	int res2 = q.pop();
	bool res3 = q.empty();
	return 0;

}
