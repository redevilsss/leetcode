#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//143 ��������
/*
����һ�������� L��L0��L1������Ln-1��Ln ��
�����������к��Ϊ�� L0��Ln��L1��Ln-1��L2��Ln-2����
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
ʾ�� 1:
�������� 1->2->3->4, ��������Ϊ 1->4->2->3.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//��򵥵�˼·������˫�˶���deque��ʵ��
//1 2 3 4 ���1 4 2 3�����뵽��ʲô��
//˫�˶��У�ͷȡһ����βȡһ������ȡ����������ȡ�����ģ�ֱ������Ϊ��
void reorderList1(ListNode* head) {
	if (head == nullptr)
		return;
	deque<ListNode*> q;
	ListNode* node = head;
	//����ѹ�����
	while (node != nullptr)
	{
		q.push_back(node);
		node = node->next;
	}
	//���зǿ�ʱ���������е�Ԫ��һͷһβ��˳�����ӣ�ÿ�β������������ڵ�
	while (!q.empty())
	{
		//nodeΪ��ֻ�����һ�Σ����ǵ�һ�ν���ѭ��ʱ����ʱnode�ձ����ָ꣬��nullptr
		//��ʱ��node��Ϊͷ������ʵ����head��
		if (node == nullptr)
		{
			node = q.front();
			q.pop_front();
		}
		else//����Ľڵ㣬����node���ӣ�������node
		{
			node->next = q.front();
			q.pop_front();
			node = node->next;
		}
		//���������ͷ��Ԫ�������������β�������ʱ�����л���Ԫ��
		//����node���Ӷ�βԪ�أ�������node
		if (!q.empty())
		{
			node->next = q.back();
			q.pop_back();
			node = node->next;
		}
	}
	//���nodeָ����е���βԪ�أ�����nextָ�����
	node->next = nullptr;
}


//������������ָ�룬Ȼ������Ͽ��������һ�뷭ת���ٺ�ǰ���һ�㽻���������¹�������

//��ת����ĵݹ鷽������������ջ��ʵ��
ListNode* reverseList(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* node = reverseList(head->next);
	head->next->next = head;
	head->next = nullptr;
	return node;
}


void reorderList(ListNode* head) {
	if (head == nullptr)
		return;
	//����ָ�룬��ָ�뵽�սڵ�ʱ��ָ��պ��ߵ�һ��
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast->next!=nullptr&&fast->next->next!=nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//��ת��һ������
	ListNode* node = slow->next;
	slow->next = nullptr;
	node = reverseList(node);
	//����ϲ�
	ListNode* firstCur= head;
	ListNode* secondCur = node;
	while (secondCur != nullptr)
	{
		//��ÿ�ν��кϲ�ǰ��Ҫ�ֱ𱣴���������ǰ�ڵ����һ���ڵ�
		ListNode* firstNext = firstCur->next; 
		ListNode* secondNext = secondCur->next;
		//ÿ�κϲ�������
		firstCur->next = secondCur;
		secondCur->next = firstNext;
		//�ϲ���һ�κ���µ�ǰλ��
		firstCur = firstNext;
		secondCur = secondNext;
	}
}



int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	reorderList(l1);
	return 0;
}