#include<iostream>
using namespace std;

//147 对链表进行插入排序
/*
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
示例 1:
输入: 4->2->1->3
输出: 1->2->3->4
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
题目说要用复杂度O(nlongn)的算法，可以选择的就是归并和快排
都要用到递归，思想也类似
归并排序
1.使用快慢指针遍历当前链表，为了前后两端平均分，需要保存slow的前一个节点
  然后将该节点的next置为空，把当前链表一分为二
2.继续对两个子链表进行处理，返回这两个链表排好序的状态（过程也是递归是实现的）
3.再对这两个链表进行归并排序操作
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
//遍历两个链表，归并排序
ListNode* merge(ListNode* l1, ListNode* l2)
{
	//某一个链表已经遍历完
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

