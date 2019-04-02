#include<iostream>
#include<vector>
#include<set>
using namespace std;

//203 �Ƴ�����Ԫ��

/*
ɾ�������е��ڸ���ֵ val �����нڵ㡣
ʾ��:
����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5
*/

struct ListNode {
    int val;   
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
������������ֵΪval�Ľڵ㣬�ܼ򵥣�������������ͷ�ڵ㣨Ҫ��Ȼ�����ж�head��ֵ��
��newHead��ʼ�����������α�ڵ�nodeΪ��ǰ�ڵ㣬��node��nextֵΪvalʱ��������next
������½ڵ�node��������
*/

ListNode* removeElements(ListNode* head, int val) {
	ListNode* newHead = new ListNode(-1);
	newHead->next = head;
	ListNode* node = newHead;
	while (node != nullptr)
	{
		if (node->next->val == val)
			node ->next= node->next->next;
		else
			node = node->next;
	}
	return newHead->next;
}

int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(6);
	ListNode* l4 = new ListNode(3);
	ListNode* l5 = new ListNode(4);
	ListNode* l6 = new ListNode(5);
	ListNode* l7 = new ListNode(6);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	ListNode* res = removeElements(l1, 6);
	return 0;


}