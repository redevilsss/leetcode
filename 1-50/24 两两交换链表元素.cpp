#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

//24 ������������Ԫ��

/*
����һ���������������������ڵĽڵ㣬�����ؽ����������
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
ʾ�� :
���� 1->2->3->4, ��Ӧ�÷��� 2->1->4->3.
*/
//�ڽ��н���ʱ��Ҫ�ĸ����������������ֱ𱣴�ǰһ���ڵ�ͺ�һ���ڵ㣬����������ʾ���е����������ڵ�
ListNode* swapPairs(ListNode* head) {
	//����С��2ֱ�ӷ���
	if (head == nullptr || head->next == nullptr)
		return head;
	//Ϊ���㴴����ͷ
	ListNode* newHead = new ListNode(-1);
	newHead->next = head;
	//ǰ�����
	ListNode* pPrev = newHead;
	//��ǰ���
	ListNode* pCur = head;
	//��ʱ��ǰ����������һ�������ǿգ����Խ��н���
	while (pCur!=nullptr&&pCur->next != nullptr)
	{
		ListNode* pNext = pCur->next->next;//�����̽��
		//�ҷֱ���1 2 3 4��ʾǰ����㡢���������Ľ��ͺ�̽��
		pPrev->next = pCur->next;//1����һ��ָ��3
		pCur->next->next = pCur;//2����һ������һ��ָ������,��3ָ��2
		pCur->next = pNext;//2����һ��ָ��4
		pPrev = pCur;//1����2
		pCur=pNext;//2����4��һ��ѭ����ɣ�һ��ѭ����Ҫ�ı�ָ��3�� ����ָ��2�Σ�����ǰ�����ͺ�̽�㣩
	}
	return newHead->next;
}

int main()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	//n4->next = n5;
	swapPairs(n1);
	return 0;
}