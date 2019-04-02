#include<iostream>
using namespace std;
/*给出两个 非空 的链表用来表示两个非负的整数。
其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//思路：这个题其实就是按位计算十进制加法，要注意是否最后一位有进位

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	//构造一个头结点，方便后续的处理，返回时直接返回这个结点的next即可
	ListNode* pNode = new ListNode(0);
	ListNode* pHead = pNode;

	int flag = 0;//进位标志
	while (l1 != nullptr&&l2 != nullptr)//有一个结点为空则循环结束
	{
		int val = l1->val + l2->val + flag;
		ListNode* pCur = new ListNode(val % 10);//创建结点表示两数的和
		if (val >= 10)
			flag = 1;//设置进位标志
		else
			flag = 0;
		pNode->next = pCur;//用pNode当线，把节点串起来
		pNode = pNode->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	//此时已经有一个链表为空，不是l1就是l2
	ListNode* pTemp = l1;
	if (l1 == nullptr)
		pTemp = l2;
	while (pTemp != nullptr)//此时只有进位和剩余链表进行加法计算，其余与上面类似
	{
		int val = pTemp->val + flag;
		pNode->next = new ListNode(val % 10);
		if (val >= 10)
			flag = 1;
		else
			flag = 0;
		pNode = pNode->next;
		pTemp = pTemp->next;
	}
	//若最后进位仍为1，则需要新建值为1的节点置于最后
	if (flag == 1)
		pNode->next = new ListNode(1);
	return pHead->next;
}

int main()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(9);
	ListNode* n3 = new ListNode(9);
	ListNode* n4 = new ListNode(9);
	ListNode* n5 = new ListNode(1);
	ListNode* n6 = new ListNode(1);
	ListNode* n7 = new ListNode(1);
	ListNode* n8 = new ListNode(1);
	n2->next = n3;
	n3->next = n4;
	ListNode* res=addTwoNumbers(n1, n2);
	return 0;

}
