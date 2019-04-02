#include<iostream>
#include<stack>
using namespace std;

//155 ��Сջ

/*
���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
push(x) -- ��Ԫ�� x ����ջ�С�
pop() -- ɾ��ջ����Ԫ�ء�
top() -- ��ȡջ��Ԫ�ء�
getMin() -- ����ջ�е���СԪ�ء�
*/

//��������ջs_min�����洢��ǰ����СԪ�أ���СԪ�ؼ�Ϊջ��
//����ջ��ջ������ͬ��Ԫ�ظ���
//��s_data�Ĵ���û�б仯
//������ջs_minΪ�ջ�ǰҪѹ���ֵС��ջ��ֵʱ������ֵѹ��s_min�У�����ѹ��s_min��ջ��Ԫ��
class MinStack {
public:
	/** initialize your data structure here. */
	//�޲ι��캯��
	MinStack() {
	}
	//��ջ
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