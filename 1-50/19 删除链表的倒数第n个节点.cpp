#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



//19 删除链表的倒数第N个节点
/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


//方法1：需要分情况，而方法2由于新创建了头节点指向原头节点，可以省去很多判断
ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	ListNode* pNode1=head;
	//找第n个节点的位置
	for(int i=0;i<n-1;i++)
		pNode1=pNode1->next;
	//如果此时第n个节点是最后一个，说明倒数第n个是头节点，删除头节点
	if(pNode1->next==nullptr)
	{
		ListNode* ToBeDeleted=head;
		head=head->next;
		delete ToBeDeleted;
		return head;
	}
	//取另一个指针
	ListNode* pNode2=head;
	//为保证pNode1->next不为空，以下式为判断式
	while(pNode1->next->next!=nullptr)
	{
		pNode1=pNode1->next;
		pNode2=pNode2->next;
	}
	//此时pNode1->next表示最后一个元素，pNode1是倒数第二个元素，此时
	//pNode2对应倒数第n个元素的前一个元素，删除倒数第n个元素
	ListNode* ToBeDeleted=pNode2->next;
	pNode2->next=pNode2->next->next;
	delete ToBeDeleted;
	return head;


	}


//方法二：更加便于理解和简便
ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* h = new ListNode(0);//创建新头
		h->next = head;
		ListNode* p = head;//p指向头
		ListNode* q = h;//q指向新头
		while (n--) {
			p = p->next;//找到第n个元素
		}
		//因为q起点比p早一位，循环结束时q指向倒数第n+1个节点，方便进行删除
		while (p) {
			p = p->next;
			q = q->next;
		}
		//删除操作
		q->next = q->next->next;
		return h->next;
	}
};