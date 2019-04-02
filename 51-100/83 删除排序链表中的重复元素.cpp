#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//83 ɾ�����������е��ظ�Ԫ��
/*
����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�
ʾ��:
����: 1->1->2
���: 1->2
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//�Ƚϼ򵥣�������������
ListNode* deleteDuplicates(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* pNode = head;
	while (pNode!=nullptr&&pNode->next != nullptr)
	{
		if (pNode->val == pNode->next->val)
			pNode->next = pNode->next->next;//�����ظ��ľ�����
		else
			pNode = pNode->next;
	}
	return head;
}


int main()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(1);
	ListNode* n3 = new ListNode(2);
	ListNode* n4 = new ListNode(3);
	ListNode* n5 = new ListNode(3);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	deleteDuplicates(n1);
	return 0;
}