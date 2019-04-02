#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// 21 �ϲ�������������
/*
��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
ʾ����
���룺1->2->4, 1->3->4
�����1->1->2->3->4->4
*/

//����˼�룺������ͷ�����������ߣ������ƹ鲢�ķ�ʽ����������кϲ�
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;
	ListNode* head = new ListNode(0);
	ListNode* p = head;
	while (l1 != nullptr&&l2 != nullptr)
	{
		//˭С��˭�������p��ԭ����λ�ø���
		if (l1->val <= l2->val)
		{
			p->next = l1;
			p = p->next;
			l1 = l1->next;
		}
		else
		{
			p->next = l2;
			p = p->next;
			l2 = l2->next;
		}
	}
	if (l1 == nullptr)
		p->next = l2;
	else
		p->next = l1;
	return head->next;

}