#include<iostream>
using namespace std;

//234 回文链表

/*
请判断一个链表是否为回文链表。
示例 1:
输入: 1->2
输出: false
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//分三步来完成：
/*
1. 快慢指针找到中点
2. 后一半链表翻转
3. 分别从head和反转后的后半链表头节点开始比较
*/
bool isPalindrome(ListNode* head) {
	if (head == nullptr)
		return true;
	//快慢指针找中点
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast->next != nullptr&&fast->next->next != nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode* node = slow->next;
	slow->next = nullptr;
	//翻转后一半链表
	ListNode* prev = nullptr;
	while (node != nullptr)
	{

		ListNode* next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}
	//检查两链表是否一致(prev链表长度可能等于head，也可能)
	while (prev != nullptr)
	{
		if (head->val != prev->val)
			return false;
		head = head->next;
		prev = prev->next;
	}
	return true;
}