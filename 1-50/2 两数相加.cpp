#include<iostream>
using namespace std;
/*�������� �ǿ� ������������ʾ�����Ǹ���������
���У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�
�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
ʾ����
���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//˼·���������ʵ���ǰ�λ����ʮ���Ƽӷ���Ҫע���Ƿ����һλ�н�λ

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	//����һ��ͷ��㣬��������Ĵ�������ʱֱ�ӷ����������next����
	ListNode* pNode = new ListNode(0);
	ListNode* pHead = pNode;

	int flag = 0;//��λ��־
	while (l1 != nullptr&&l2 != nullptr)//��һ�����Ϊ����ѭ������
	{
		int val = l1->val + l2->val + flag;
		ListNode* pCur = new ListNode(val % 10);//��������ʾ�����ĺ�
		if (val >= 10)
			flag = 1;//���ý�λ��־
		else
			flag = 0;
		pNode->next = pCur;//��pNode���ߣ��ѽڵ㴮����
		pNode = pNode->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	//��ʱ�Ѿ���һ������Ϊ�գ�����l1����l2
	ListNode* pTemp = l1;
	if (l1 == nullptr)
		pTemp = l2;
	while (pTemp != nullptr)//��ʱֻ�н�λ��ʣ��������мӷ����㣬��������������
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
	//������λ��Ϊ1������Ҫ�½�ֵΪ1�Ľڵ��������
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
