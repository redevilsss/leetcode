#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

//232 用栈实现队列

/*
使用栈实现队列的下列操作：
push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。
*/

//用两个栈实现队列，s1为辅助栈，s2为主栈
//push元素进s1，pop元素从s2出
//当pop元素但s2为空时，把s1倒入s2
//进栈再出栈顺序不变
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
