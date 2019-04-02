#include<iostream>
using namespace std;

//147 对链表进行插入排序
/*
插入排序算法：
插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
插入排序的复杂度是O(n)，完全比不上直接用map直接去装然后遍历
map的结构是红黑树，每次插入复杂度O(logn)，装完全部复杂度是O(nlogn)，要比插入排序快很多
所以正儿八经写出来的插入思想的代码运行速度都不快
当然主要还是看思想：
从头到尾遍历节点，对于当前要进行插入排序的操作的节点，必须和它的前后都断开
也就是说每次排序开始时，链表会变成   链表已排序部分 XXX  当前节点  XXX  链表未排序部分
也就是说当前节点是要和前后都分离开的，所以需要prev指针来指向已排序链表的末位，next指向剩余部分的首位
对于在某个节点，用temp指针从头遍历找第一个大于该节点值的节点，遍历后得到的temp节点就是当前节点的前驱
这个时候是有两种情况的：
1. temp节点不是已排序部分的尾节点，那就将当前节点node放在 temp和temp->next中间
2. 否则，temp节点就是当前的尾节点，那就将当前节点node放在temp和next中间

还要注意第2种情况时要更新prev值，因为此时已排序链表的尾节点就是刚刚插入的当前节点
*/
ListNode* insertionSortList(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode*node = head->next;
	head->next = nullptr;
	ListNode* prev = head;
	//遍历链表
	while (node != nullptr)
	{
		ListNode* next = node->next;
		node->next = nullptr;
		//当前节点要放在首位
		if (node->val<head->val)
		{
			node->next = head;
			head = node;
		}
		else
		{
			ListNode* temp = head;
			//遍历找node的前驱
			while (temp->next != nullptr&&node->val>temp->next->val)
				temp = temp->next;
			//上述情况2，连接节点，更新prev
			if (temp->next == nullptr)
			{
				node->next = next;
				temp->next = node;
				prev = node;
				prev->next = nullptr;
			}
			//上述情况1，连接节点
			else
			{
				node->next = temp->next;
				temp->next = node;
			}
		}
		//更新node
		node = next;
	}
	return head;
}

int main()
{
	ListNode* l1 = new ListNode(6);
	ListNode* l2 = new ListNode(5);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(1);
	ListNode* l5 = new ListNode(8);
	ListNode* l6 = new ListNode(7);
	ListNode* l7 = new ListNode(4);
	ListNode* l8 = new ListNode(2);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	l7->next = l8;
	ListNode* head=insertionSortList(l1);
	return 0;

}