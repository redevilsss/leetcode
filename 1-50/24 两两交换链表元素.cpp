#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

//24 两两交换链表元素

/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
示例 :
给定 1->2->3->4, 你应该返回 2->1->4->3.
*/
//在进行交换时需要四个变量，其中两个分别保存前一个节点和后一个节点，其余两个表示进行调换的两个节点
ListNode* swapPairs(ListNode* head) {
	//长度小于2直接返回
	if (head == nullptr || head->next == nullptr)
		return head;
	//为方便创建新头
	ListNode* newHead = new ListNode(-1);
	newHead->next = head;
	//前驱结点
	ListNode* pPrev = newHead;
	//当前结点
	ListNode* pCur = head;
	//此时当前结点和它的下一个结点均非空，可以进行交换
	while (pCur!=nullptr&&pCur->next != nullptr)
	{
		ListNode* pNext = pCur->next->next;//保存后继结点
		//我分别用1 2 3 4表示前驱结点、两个交换的结点和后继结点
		pPrev->next = pCur->next;//1的下一个指向3
		pCur->next->next = pCur;//2的下一个的下一个指向自身,即3指向2
		pCur->next = pNext;//2的下一个指向4
		pPrev = pCur;//1等于2
		pCur=pNext;//2等于4，一个循环完成，一个循环需要改变指向3次 更新指针2次（更新前驱结点和后继结点）
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