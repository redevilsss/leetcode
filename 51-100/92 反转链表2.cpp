#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//92 ��ת����2

/*
��ת��λ�� m �� n ��������ʹ��һ��ɨ����ɷ�ת��
˵��:
1 �� m �� n �� �����ȡ�
ʾ��:
����: 1->2->3->4->5->NULL, m = 2, n = 4
���: 1->4->3->2->5->NULL
*/

//�ҵķ�����Ϊ���������
//1 ���ҵ���m���ڵ㣬�����m���ڵ�֮ǰ�Ľڵ�
//2 ���������ҵ���n+1���ڵ�pEnd
//3 ���б������ӵ�m���ڵ㿪ʼ��ÿ���ȱ�����һ���ڵ㣬
//  ���ڵ��next��ΪpEnd��������pEnd��ѭ������Ϊn-m+1

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
	if (m == n)
		return head;
	//�����½ڵ�
	ListNode* newHead = new ListNode(-1);
	newHead->next = head;
	ListNode* pNode = head;//pNode�䵱�߱�������
	ListNode* pPrev = newHead;//����ǰ���ڵ㣬���ڴ洢�����m����ʱ��ǰһ���ڵ�
	int i = 1;
	while (m>i++)//�ҵ���m�������ڵ�λ��
	{
		pPrev = pNode;
		pNode = pNode->next;
	}
	ListNode* pEnd = pNode;//�ҵ���ת���ֵ���һ���ڵ�
	int steps = n - m + 1;
	while (steps--)
		pEnd = pEnd->next;
	//ѭ��ʵ�ַ�ת
	int length = n - m + 1;
	while (length--)
	{
		ListNode* pNext = pNode->next;//������һ���ڵ�
		pNode->next = pEnd;//�޸ĵ�ǰ�ڵ�ָ��ղű����pEnd
		pEnd = pNode;//����pEnd
		pNode = pNext;//����pNode;
	}
	pPrev->next = pEnd;//��ʱpEndΪpEnd��ʼֵ��ǰһ���ڵ㣬�˿����Ǹղű����ǰ���ڵ����һ��
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