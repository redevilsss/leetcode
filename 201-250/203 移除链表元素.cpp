#include<iostream>
#include<vector>
#include<set>
using namespace std;

//203 移除链表元素

/*
删除链表中等于给定值 val 的所有节点。
示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

struct ListNode {
    int val;   
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
这道题就是跳过值为val的节点，很简单，首先设置虚拟头节点（要不然还得判断head的值）
从newHead开始遍历，设置游标节点node为当前节点，当node的next值为val时，跳过其next
否则更新节点node继续遍历
*/

ListNode* removeElements(ListNode* head, int val) {
	ListNode* newHead = new ListNode(-1);
	newHead->next = head;
	ListNode* node = newHead;
	while (node != nullptr)
	{
		if (node->next->val == val)
			node ->next= node->next->next;
		else
			node = node->next;
	}
	return newHead->next;
}

int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(6);
	ListNode* l4 = new ListNode(3);
	ListNode* l5 = new ListNode(4);
	ListNode* l6 = new ListNode(5);
	ListNode* l7 = new ListNode(6);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	ListNode* res = removeElements(l1, 6);
	return 0;


}