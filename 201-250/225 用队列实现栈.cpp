#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

//225 用队列实现栈

/*
使用队列实现栈的下列操作：
push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
*/

/*
用两个队列实现栈，保证任意时刻都一个队列为空
若某时刻空队列为q1，非空队列为q2
push时把元素放到非空队列q2中
pop时弹出栈顶元素，即q2的back元素，为了弹出该元素，把其前面的q2.size()-1个元素都放入q1中，再弹出该元素
top时返回当前栈顶元素但不弹出，直接返回q2的back元素
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
