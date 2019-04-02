#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// 21 合并两个有序链表
/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

//核心思想：创建新头，并设置针线，用类似归并的方式对两链表进行合并
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;
	ListNode* head = new ListNode(0);
	ListNode* p = head;
	while (l1 != nullptr&&l2 != nullptr)
	{
		//谁小接谁，接完后p和原链表位置更新
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