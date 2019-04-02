#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//86 分隔链表

/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置。
示例:
输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//方法一思想：遇到大于等于目标值就往后挪
ListNode* partition(ListNode* head, int x) {
	//排除链表长度为0和1的情况
	if (head == nullptr || head->next == nullptr)
		return head;
	//构造新头，避免对头指针的特殊操作
	ListNode* newHead = new ListNode(0);
	newHead->next = head;
	ListNode* pPrev = newHead;//前驱指针，保存当前结点的前一个结点
							  //当该结点移到最后时，使前驱结点连接其下一个结点
	ListNode* pEnd = head;
	int length = 1;//计算链表长度并标明链表最后一个非空结点
	while (pEnd->next != nullptr)//pEnd指向最后一个非空结点
	{
		pEnd = pEnd->next;
		length++;
	}

	ListNode* pNode = head;
	while (length>0 && pNode != pEnd)//pNode==pEnd说明没有进行翻转，直接退出
	{
		//当结点值小于目标值时，更新前驱结点并继续遍历
		if (pNode->val<x)
		{
			pPrev = pNode;
			pNode = pNode->next;
		}
		else if (pNode->val >= x)//结点值大于等于目标值时，将结点挪到最后
		{
			pEnd->next = pNode;//将结点挪到左后
			pEnd = pNode;//更新尾结点
			pPrev->next = pNode->next;//前驱结点指向该结点的下一个结点
			pNode->next = nullptr;//结点的next置空
			pNode = pPrev->next;//更新PNode为前驱指针的后继
		}
		length--;
	}
	return newHead->next;
}


//方法二：建立两个子链表，最后合并
ListNode* partition(ListNode* head, int x) {
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* pNode = head;
	//建立两个头，创建两根线
	ListNode* SmallHead = new ListNode(-1);
	ListNode* BigHead = new ListNode(-1);
	ListNode* pSmallNode = nullptr;
	ListNode* pBigNode = nullptr;
	while (pNode != nullptr)
	{
		//保存pNode的next值，被子链表的新头连接后pNode的next要清空
		ListNode* pNext = pNode->next;
		//按照值的大小来区分进哪个子链表
		if (pNode->val<x)
		{
			//当前子链表为空，遇到第一个元素时
			if (pSmallNode == nullptr)
			{
				pSmallNode = pNode;//给pSmallNode赋值
				SmallHead->next = pNode;//新头连接第一个节点
				pSmallNode->next = nullptr;//将此结点next清空
			}
			else
			{//子链表不为空，每次更新线，也就是pSmallNode，把一个个节点串起来
				pSmallNode->next = pNode;//连接节点
				pSmallNode = pNode;//更新pSmallNode
				pSmallNode->next = nullptr;//pNode的next清空
			}
		}
		else//和上面类似
		{
			if (pBigNode == nullptr)
			{
				pBigNode = pNode;
				BigHead->next = pNode;
				pBigNode->next = nullptr;
			}
			else
			{
				pBigNode->next = pNode;
				pBigNode = pNode;
				pBigNode->next = nullptr;
			}
		}
		pNode = pNext;//遍历下一个节点
	}

	if (SmallHead->next != nullptr)//小子链表不为空，让最终指向最后一个节点的pSmallNode指向大子链表的第一个元素
		pSmallNode->next = BigHead->next;
	else//否则直接跳过小子链表，连接大子链表
		SmallHead->next = BigHead->next;
	return SmallHead->next;


}
int main()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	//ListNode* n3 = new ListNode(3);
	//ListNode* n4 = new ListNode(2);
	//ListNode* n5 = new ListNode(5);
	//ListNode* n6 = new ListNode(2);
	n1->next = n2;
	//n2->next = n3;
	//n3->next = n4;
	//n4->next = n5;
	//n5->next = n6;
	ListNode* res=partition(n1,2);
	return 0;
}