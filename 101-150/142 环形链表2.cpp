#include<iostream>
#include<vector>
using namespace std;

//142 环形链表2
/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
说明：不允许修改给定的链表。
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

//思路：先判断有没有环，如果有，返回环中任意一点，再通过其他操作找到环入口，判断有没有环的部分就是141题
ListNode *detectCycle(ListNode *head) {
	ListNode* meetingNode = hasCycle(head);
	if (meetingNode == nullptr)
		return nullptr;
	//计算环中节点的个数length
	ListNode* node1 = meetingNode;
	int length = 1;
	while (node1->next != meetingNode)
	{
		length++;
		node1 = node1->next;
	}
	//node1从头节点开始走length步
	node1 = head;
	for (int i = 0; i<length; i++)
		node1 = node1->next;
	//定义另一个指针node2从头节点开始，node1和node2同时向前走，某一时刻两者指向同一节点，该节点就是环的入口节点
	//为什么呢？假设链表非环部分为l，环长为r，则环入口在l处，如何得到l呢？
	//我让节点1先走r步，则节点1与环入口的距离为l-r或r-l
	//若距离是r-l，说明此时节点1已经进入环，环长r，进入环内r-l，此时节点2也开始走，两节点同时走r-(r-l)=l步，两节点相遇，正好是l位置
	//若距离是l-r，说明此时节点1还没到环，环长r，还有l-r入环，此时节点2也开始走，两节点同时走l-r+r=l步，两节点相遇，在l位置
	ListNode* node2 = head;
	while (node1 != node2)
	{
		node1 = node1->next;
		node2 = node2->next;
	}
	return node1;


}
//与前一题基本一致
ListNode *hasCycle(ListNode *head) {
	if (head == nullptr)
		return nullptr;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != nullptr&&slow != nullptr)
	{
		fast = fast->next;
		if (fast == nullptr)
			return nullptr;
		fast = fast->next;
		if (fast == slow)
			return fast;
		slow = slow->next;

	}
	return nullptr;
}