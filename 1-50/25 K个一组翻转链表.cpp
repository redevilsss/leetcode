#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

//25 k个一组翻转链表
/*
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。
示例 :
给定这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5
*/


//此题重点和24一样，在于如何实现持续翻转，即需要合理保存下一步需要的量
ListNode* reverseKGroup(ListNode* head, int k) {
	//L当成一根线
	ListNode* L = head;
	ListNode* res = new ListNode(0);//res指向一个新链表头，下一个结点是原头
	ListNode* pPrev = res;
	res->next = head;
	while (L)
	{
		//n变量用来控制翻转循环的进出
		int n = k;
		ListNode* check = L;//check标记下一次翻转的开始
		while (n>0 && check != nullptr)
		{
			n--;
			check = check->next;//找第n个结点的位置，即下一次翻转的头
		}
		//n可能不为0，若链表很短而n大于链表长度，不为0则直接返回
		if (n == 0)
		{
			n = k;
			ListNode *p1 = check;
			//是下一个循环的开始，即翻转部分结尾的下一个，用来保存信息
			ListNode* p2 = L;//p2和p3指向第一个完成翻转的两个数
			ListNode* p3 = p2;
			while (n)
			{
				//若n=3，用1 2 3 4 5做示范
				//1为前驱pPrev，p2、p3、L此时指向2，check为后继结点，指向5
				//目标是翻转2 3 4，需要翻转三次
				p3 = p2->next;//p3指向3
				p2->next = p1;//p2下一个结点指向p1，即让2的下一个连到5上
				p1 = p2;//p1更新，指向2，p1表示链接后最后的结点
				p2 = p3;//p2更新，指向3，p2指向即将进行交换的结点
				n--;
				//下一步：p3指向4，3的下一个指向2，更新p1为3，更新p2为4
				//下一步：p3指向5，4的下一个指向3，更新p1为4，p2为5
			}
			pPrev->next = p1;//用前驱链接现在的p1
			pPrev = L;//把前驱本次翻转的头（2），现在顺序是1 4 3 2 5，2是下一次翻转的前驱
		}
		L = check;//更新L为check，若链表长度小于n则L为空，直接返回了
	}
	return res->next;
}