#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//92 反转链表2

/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
说明:
1 ≤ m ≤ n ≤ 链表长度。
示例:
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/

//我的方法分为三步来完成
//1 先找到第m个节点，保存第m个节点之前的节点
//2 继续遍历找到第n+1个节点pEnd
//3 进行遍历，从第m个节点开始，每次先保存下一个节点，
//  将节点的next置为pEnd，并更新pEnd，循环次数为n-m+1

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
	if (m == n)
		return head;
	//创建新节点
	ListNode* newHead = new ListNode(-1);
	newHead->next = head;
	ListNode* pNode = head;//pNode充当线遍历链表
	ListNode* pPrev = newHead;//定义前驱节点，用于存储到达第m个点时其前一个节点
	int i = 1;
	while (m>i++)//找到第m个点所在的位置
	{
		pPrev = pNode;
		pNode = pNode->next;
	}
	ListNode* pEnd = pNode;//找到反转部分的下一个节点
	int steps = n - m + 1;
	while (steps--)
		pEnd = pEnd->next;
	//循环实现反转
	int length = n - m + 1;
	while (length--)
	{
		ListNode* pNext = pNode->next;//保存下一个节点
		pNode->next = pEnd;//修改当前节点指向刚才保存的pEnd
		pEnd = pNode;//更新pEnd
		pNode = pNext;//更新pNode;
	}
	pPrev->next = pEnd;//此时pEnd为pEnd初始值的前一个节点，此刻它是刚才保存的前驱节点的下一个
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
	n4->next = n5;
	reverseBetween(n1,2,4);
	return 0;
}