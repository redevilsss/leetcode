#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//82 ɾ�����������е��ظ�Ԫ��2

/*
����һ����������ɾ�����к����ظ����ֵĽڵ㣬ֻ����ԭʼ������ û���ظ����� �����֡�
ʾ��:
����: 1->2->3->3->4->4->5
���: 1->2->5
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	//����һ����ͷ
	ListNode* newHead = new ListNode(0);
	newHead->next = head;
	//����ǰ�����
	ListNode* pPrev = newHead;
	ListNode* pNode = head;//���ñ������
	while (pNode != nullptr&&pNode->next != nullptr)
	{
		if (pNode->val == pNode->next->val)//��pNode��ֵ������һ�����ֵ��ͬʱ���������ҵ�һ�����䲻��ͬ��ֵ��Ȼ����ǰ��������ֵ��ʵ��ɾ��
		{
			int temp = pNode->val;
			while (pNode != nullptr&&pNode->val == temp)
			{
				pNode = pNode->next;
			}
			pPrev->next = pNode;
		}
		else//����pNode��������������ǰ�����
		{
			pPrev = pNode;
			pNode = pNode->next;
		}

	}
	return newHead->next;
}


int main()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(1);
	//ListNode* n3 = new ListNode(2);
	//ListNode* n4 = new ListNode(3);
	//ListNode* n5 = new ListNode(3);
	n1->next = n2;
	//n2->next = n3;
	//n3->next = n4;
	//n4->next = n5;
	deleteDuplicates(n1);
	return 0;
}