#include<iostream>
#include<vector>
using namespace std;


/*
给定一个链表，判断链表中是否有环。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
如果 pos 是 -1，则在该链表中没有环。
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

//这道题很简单，判断有没有环的一般会使用快慢两个指针，快指针一次走两步，慢指针一次走一步
//如果环存在，快指针会在环中多走一圈追上慢指针
//因为环中任何一个节点都有后继节点，环存在时下面的while循环会变成死循环，当快指针第一次追上慢指针时，返回正确
//环不存在时，快指针不可能追上慢指针，会先到达nullptr，退出返回false
bool hasCycle(ListNode *head) {
	if (head == nullptr)
		return false;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != nullptr&&slow != nullptr)
	{
		fast = fast->next;
		if (fast == nullptr)
			return false;
		fast = fast->next;
		if (fast == slow)
			return true;
		slow = slow->next;

	}
	return false;
}