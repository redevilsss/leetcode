#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//86 �ָ�����

/*
����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��
��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�
ʾ��:
����: head = 1->4->3->2->5->2, x = 3
���: 1->2->2->4->3->5
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//����һ˼�룺�������ڵ���Ŀ��ֵ������Ų
ListNode* partition(ListNode* head, int x) {
	//�ų�������Ϊ0��1�����
	if (head == nullptr || head->next == nullptr)
		return head;
	//������ͷ�������ͷָ����������
	ListNode* newHead = new ListNode(0);
	newHead->next = head;
	ListNode* pPrev = newHead;//ǰ��ָ�룬���浱ǰ����ǰһ�����
							  //���ý���Ƶ����ʱ��ʹǰ�������������һ�����
	ListNode* pEnd = head;
	int length = 1;//���������Ȳ������������һ���ǿս��
	while (pEnd->next != nullptr)//pEndָ�����һ���ǿս��
	{
		pEnd = pEnd->next;
		length++;
	}

	ListNode* pNode = head;
	while (length>0 && pNode != pEnd)//pNode==pEnd˵��û�н��з�ת��ֱ���˳�
	{
		//�����ֵС��Ŀ��ֵʱ������ǰ����㲢��������
		if (pNode->val<x)
		{
			pPrev = pNode;
			pNode = pNode->next;
		}
		else if (pNode->val >= x)//���ֵ���ڵ���Ŀ��ֵʱ�������Ų�����
		{
			pEnd->next = pNode;//�����Ų�����
			pEnd = pNode;//����β���
			pPrev->next = pNode->next;//ǰ�����ָ��ý�����һ�����
			pNode->next = nullptr;//����next�ÿ�
			pNode = pPrev->next;//����PNodeΪǰ��ָ��ĺ��
		}
		length--;
	}
	return newHead->next;
}


//�������������������������ϲ�
ListNode* partition(ListNode* head, int x) {
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* pNode = head;
	//��������ͷ������������
	ListNode* SmallHead = new ListNode(-1);
	ListNode* BigHead = new ListNode(-1);
	ListNode* pSmallNode = nullptr;
	ListNode* pBigNode = nullptr;
	while (pNode != nullptr)
	{
		//����pNode��nextֵ�������������ͷ���Ӻ�pNode��nextҪ���
		ListNode* pNext = pNode->next;
		//����ֵ�Ĵ�С�����ֽ��ĸ�������
		if (pNode->val<x)
		{
			//��ǰ������Ϊ�գ�������һ��Ԫ��ʱ
			if (pSmallNode == nullptr)
			{
				pSmallNode = pNode;//��pSmallNode��ֵ
				SmallHead->next = pNode;//��ͷ���ӵ�һ���ڵ�
				pSmallNode->next = nullptr;//���˽��next���
			}
			else
			{//������Ϊ�գ�ÿ�θ����ߣ�Ҳ����pSmallNode����һ�����ڵ㴮����
				pSmallNode->next = pNode;//���ӽڵ�
				pSmallNode = pNode;//����pSmallNode
				pSmallNode->next = nullptr;//pNode��next���
			}
		}
		else//����������
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
		pNode = pNext;//������һ���ڵ�
	}

	if (SmallHead->next != nullptr)//С������Ϊ�գ�������ָ�����һ���ڵ��pSmallNodeָ���������ĵ�һ��Ԫ��
		pSmallNode->next = BigHead->next;
	else//����ֱ������С���������Ӵ�������
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