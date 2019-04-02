#include<iostream>
#include<stack>
using namespace std;

//155 最小栈

/*
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
*/

//创建辅助栈s_min用来存储当前的最小元素，最小元素即为栈顶
//辅助栈和栈中有相同的元素个数
//对s_data的处理没有变化
//当辅助栈s_min为空或当前要压入的值小于栈顶值时，将该值压入s_min中，否则压入s_min的栈顶元素
class MinStack {
public:
	/** initialize your data structure here. */
	//无参构造函数
	MinStack() {
	}
	//入栈
	void push(int x) {
		s_data.push(x);
		if (s_min.size() == 0 || s_min.top()>x)
			s_min.push(x);
		else
			s_min.push(s_min.top());
	}

	void pop() {
		s_min.pop();
		s_data.pop();
	}

	int top() {
		return s_data.top();
	}

	int getMin() {
		return s_min.top();
	}
private:
	stack<int> s_data;
	stack<int> s_min;

};