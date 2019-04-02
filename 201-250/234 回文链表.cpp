#include<iostream>
using namespace std;

//234 ��������

/*
���ж�һ�������Ƿ�Ϊ��������
ʾ�� 1:
����: 1->2
���: false
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//����������ɣ�
/*
1. ����ָ���ҵ��е�
2. ��һ������ת
3. �ֱ��head�ͷ�ת��ĺ������ͷ�ڵ㿪ʼ�Ƚ�
*/
bool isPalindrome(ListNode* head) {
	if (head == nullptr)
		return true;
	//����ָ�����е�
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast->next != nullptr&&fast->next->next != nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode* node = slow->next;
	slow->next = nullptr;
	//��ת��һ������
	ListNode* prev = nullptr;
	while (node != nullptr)
	{

		ListNode* next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}
	//����������Ƿ�һ��(prev�����ȿ��ܵ���head��Ҳ����)
	while (prev != nullptr)
	{
		if (head->val != prev->val)
			return false;
		head = head->next;
		prev = prev->next;
	}
	return true;
}