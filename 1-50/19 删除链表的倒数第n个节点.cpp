#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



//19 ɾ������ĵ�����N���ڵ�
/*
����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣
ʾ����
����һ������: 1->2->3->4->5, �� n = 2.
��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


//����1����Ҫ�������������2�����´�����ͷ�ڵ�ָ��ԭͷ�ڵ㣬����ʡȥ�ܶ��ж�
ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	ListNode* pNode1=head;
	//�ҵ�n���ڵ��λ��
	for(int i=0;i<n-1;i++)
		pNode1=pNode1->next;
	//�����ʱ��n���ڵ������һ����˵��������n����ͷ�ڵ㣬ɾ��ͷ�ڵ�
	if(pNode1->next==nullptr)
	{
		ListNode* ToBeDeleted=head;
		head=head->next;
		delete ToBeDeleted;
		return head;
	}
	//ȡ��һ��ָ��
	ListNode* pNode2=head;
	//Ϊ��֤pNode1->next��Ϊ�գ�����ʽΪ�ж�ʽ
	while(pNode1->next->next!=nullptr)
	{
		pNode1=pNode1->next;
		pNode2=pNode2->next;
	}
	//��ʱpNode1->next��ʾ���һ��Ԫ�أ�pNode1�ǵ����ڶ���Ԫ�أ���ʱ
	//pNode2��Ӧ������n��Ԫ�ص�ǰһ��Ԫ�أ�ɾ��������n��Ԫ��
	ListNode* ToBeDeleted=pNode2->next;
	pNode2->next=pNode2->next->next;
	delete ToBeDeleted;
	return head;


	}


//�����������ӱ������ͼ��
ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* h = new ListNode(0);//������ͷ
		h->next = head;
		ListNode* p = head;//pָ��ͷ
		ListNode* q = h;//qָ����ͷ
		while (n--) {
			p = p->next;//�ҵ���n��Ԫ��
		}
		//��Ϊq����p��һλ��ѭ������ʱqָ������n+1���ڵ㣬�������ɾ��
		while (p) {
			p = p->next;
			q = q->next;
		}
		//ɾ������
		q->next = q->next->next;
		return h->next;
	}
};