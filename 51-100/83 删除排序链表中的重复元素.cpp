#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//83 删除排序链表中的重复元素
/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
示例:
输入: 1->1->2
输出: 1->2
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//比较简单，不做过多描述
ListNode* deleteDuplicates(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* pNode = head;
	while (pNode!=nullptr&&pNode->next != nullptr)
	{
		if (pNode->val == pNode->next->val)
			pNode->next = pNode->next->next;//遇到重复的就跳过
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