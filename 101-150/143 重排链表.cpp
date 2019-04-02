#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//143 重排链表
/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
示例 1:
给定链表 1->2->3->4, 重新排列为 1->4->2->3.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//最简单的思路：借用双端队列deque来实现
//1 2 3 4 变成1 4 2 3，你想到了什么？
//双端队列，头取一个，尾取一个，先取出来的连后取出来的，直到队列为空
void reorderList1(ListNode* head) {
	if (head == nullptr)
		return;
	deque<ListNode*> q;
	ListNode* node = head;
	//遍历压入队列
	while (node != nullptr)
	{
		q.push_back(node);
		node = node->next;
	}
	//队列非空时，将队列中的元素一头一尾按顺序连接，每次操作处理两个节点
	while (!q.empty())
	{
		//node为空只会出现一次，就是第一次进入循环时，此时node刚遍历完，指向nullptr
		//此时把node作为头部（其实就是head）
		if (node == nullptr)
		{
			node = q.front();
			q.pop_front();
		}
		else//后序的节点，则用node连接，并更新node
		{
			node->next = q.front();
			q.pop_front();
			node = node->next;
		}
		//处理完队列头的元素再来处理队列尾，如果此时队列中还有元素
		//则用node连接队尾元素，并更新node
		if (!q.empty())
		{
			node->next = q.back();
			q.pop_back();
			node = node->next;
		}
	}
	//最后，node指向队列的最尾元素，将其next指针清空
	node->next = nullptr;
}


//方法二：快慢指针，然后将链表断开，后面的一半翻转，再和前面的一般交叉起来重新构建链表

//翻转链表的递归方法，还可以用栈来实现
ListNode* reverseList(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* node = reverseList(head->next);
	head->next->next = head;
	head->next = nullptr;
	return node;
}


void reorderList(ListNode* head) {
	if (head == nullptr)
		return;
	//快慢指针，快指针到空节点时慢指针刚好走到一般
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast->next!=nullptr&&fast->next->next!=nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//翻转后一半链表
	ListNode* node = slow->next;
	slow->next = nullptr;
	node = reverseList(node);
	//链表合并
	ListNode* firstCur= head;
	ListNode* secondCur = node;
	while (secondCur != nullptr)
	{
		//在每次进行合并前需要分别保存两个链表当前节点的下一个节点
		ListNode* firstNext = firstCur->next; 
		ListNode* secondNext = secondCur->next;
		//每次合并是两步
		firstCur->next = secondCur;
		secondCur->next = firstNext;
		//合并完一次后更新当前位置
		firstCur = firstNext;
		secondCur = secondNext;
	}
}



int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	reorderList(l1);
	return 0;
}