#include<iostream>
#include<vector>
using namespace std;

//160 相交链表
/*
编写一个程序，找到两个单链表相交的起始节点。
*/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


/*
这是剑指offer第52题，求相交链表的交点
剑指offer的方法思路如下：
首先暴力搜索是肯定不行的，先排除掉
因为相交链表是 倒Y 型的，分支在前，而且两个分叉不一样长，考虑先把分叉修齐
然后同时遍历，如果能相遇且不是空，就返回当前节点，否则遍历完返回空节点
思路如下：
1. 计算两链表长度和差值
2. 找到长的链表和短的链表
3. 长链表先走 差值 步
4. 长短链表同时走，判断节点是否相等
*/

//计算长度
int getLength(ListNode* head)
{
	ListNode* temp = head;
	int i = 0;
	while (temp != nullptr)
	{
		i++;
		temp = temp->next;
	}
	return i;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA == nullptr || headB == nullptr)
		return nullptr;
	int lengthOfA = getLength(headA);
	int lengthOfB = getLength(headB);
	//找长链表和短链表
	int length = lengthOfA;
	ListNode* Long = headA;
	ListNode* Short = headB;
	int dif = lengthOfA - lengthOfB;
	if (dif<0)
	{
		Long = headB;
		Short = headA;
		length = lengthOfB;
		dif = -dif;
	}
	//长的先走
	for (int i = 0; i<dif; i++)
		Long = Long->next;
	//长短一块走
	while (Long != nullptr&&Short != nullptr)
	{
		if (Long == Short)
			return Long;
		Long = Long->next;
		Short = Short->next;
	}
	return nullptr;
}


//当然还有其他的方法
/*
还记得之前的那道判断链表是否有环存在的题吗？
当然这道题里没有环但是我们可以制造一个环，如果我让一个链表的尾节点指向它的头
如果两个链表相交，此时链表就变成了一个带环的链表
可以先用快慢指针来判断有没有环，如果有环再去找到环的入口，就是所求的相交节点
思路如下
1. 先让链表B的尾连上头，构造环
2. 快慢指针判断有没有环
3. 如果有环就找环，没环就返回nullptr
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if (headA == nullptr || headB == nullptr)
		return nullptr;
	ListNode* last = headB;
	while (last->next != nullptr)
		last = last->next;
	last->next = headB;

	ListNode* fast = headA;
	ListNode* slow = headA;
	while (fast!=nullptr&&fast->next!=nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)//说明有环
		{
			//证明为什么当两节点相遇时，让其中一个节点从起点出发，两节点同步走
			//相遇时就在入口处
			/*
			假设非环部分长度为l，环部分长度为r。快节点追上慢节点时为t时刻
			有(2t-l)%r==(t-l)%r,也就是说t能被r整除，对慢节点来说，它在环中走了t-l步
			此时如果让其中一个节点从头出发，该节点要走l步到达入口，而环中节点走l步正好在环中走满t
			t能被r整除，此时环中节点也在入口处

			*/
			slow = headA;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			last->next = nullptr;
			return fast;
		}
	}
	last->next = nullptr;
	return nullptr;
}