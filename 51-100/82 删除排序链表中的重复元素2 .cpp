#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//82 删除排序链表中的重复元素2

/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
示例:
输入: 1->2->3->3->4->4->5
输出: 1->2->5
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	//构造一个新头
	ListNode* newHead = new ListNode(0);
	newHead->next = head;
	//设置前驱结点
	ListNode* pPrev = newHead;
	ListNode* pNode = head;//设置遍历结点
	while (pNode != nullptr&&pNode->next != nullptr)
	{
		if (pNode->val == pNode->next->val)//当pNode的值与它下一个结点值相同时，继续查找第一个与其不相同的值，然后让前驱连到该值上实现删除
		{
			int temp = pNode->val;
			while (pNode != nullptr&&pNode->val == temp)
			{
				pNode = pNode->next;
			}
			pPrev->next = pNode;
		}
		else//否则pNode继续遍历，更新前驱结点
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