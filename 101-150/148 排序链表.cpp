#include<iostream>
using namespace std;

//147 ��������в�������
/*
�� O(n log n) ʱ�临�ӶȺͳ������ռ临�Ӷ��£��������������
ʾ�� 1:
����: 4->2->1->3
���: 1->2->3->4
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
��Ŀ˵Ҫ�ø��Ӷ�O(nlongn)���㷨������ѡ��ľ��ǹ鲢�Ϳ���
��Ҫ�õ��ݹ飬˼��Ҳ����
�鲢����
1.ʹ�ÿ���ָ�������ǰ����Ϊ��ǰ������ƽ���֣���Ҫ����slow��ǰһ���ڵ�
  Ȼ�󽫸ýڵ��next��Ϊ�գ��ѵ�ǰ����һ��Ϊ��
2.������������������д������������������ź����״̬������Ҳ�ǵݹ���ʵ�ֵģ�
3.�ٶ�������������й鲢�������
*/

ListNode* sortList(ListNode* head) {
	return mergeSort(head);
}
ListNode* mergeSort(ListNode* node)
{
	if (node == nullptr || node->next == nullptr)
		return node;
	ListNode* fast = node;
	ListNode* slow = node;
	ListNode* mid = node;
	while (fast != nullptr&&fast->next != nullptr)
	{
		fast = fast->next->next;
		mid = slow;
		slow = slow->next;
	}
	mid->next = nullptr;
	ListNode* l1 = mergeSort(node);
	ListNode* l2 = mergeSort(slow);
	return merge(l1, l2);
}
//�������������鲢����
ListNode* merge(ListNode* l1, ListNode* l2)
{
	//ĳһ�������Ѿ�������
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;
	if (l1->val <= l2->val)
	{
		l1->next = merge(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = merge(l1, l2->next);
		return l2;
	}
}

