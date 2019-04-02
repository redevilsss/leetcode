#include<iostream>
using namespace std;

//147 ��������в�������
/*
���������㷨��
���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
�ظ�ֱ�������������ݲ�����Ϊֹ��
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
��������ĸ��Ӷ���O(n)����ȫ�Ȳ���ֱ����mapֱ��ȥװȻ�����
map�Ľṹ�Ǻ������ÿ�β��븴�Ӷ�O(logn)��װ��ȫ�����Ӷ���O(nlogn)��Ҫ�Ȳ��������ܶ�
���������˾�д�����Ĳ���˼��Ĵ��������ٶȶ�����
��Ȼ��Ҫ���ǿ�˼�룺
��ͷ��β�����ڵ㣬���ڵ�ǰҪ���в�������Ĳ����Ľڵ㣬���������ǰ�󶼶Ͽ�
Ҳ����˵ÿ������ʼʱ���������   ���������򲿷� XXX  ��ǰ�ڵ�  XXX  ����δ���򲿷�
Ҳ����˵��ǰ�ڵ���Ҫ��ǰ�󶼷��뿪�ģ�������Ҫprevָ����ָ�������������ĩλ��nextָ��ʣ�ಿ�ֵ���λ
������ĳ���ڵ㣬��tempָ���ͷ�����ҵ�һ�����ڸýڵ�ֵ�Ľڵ㣬������õ���temp�ڵ���ǵ�ǰ�ڵ��ǰ��
���ʱ��������������ģ�
1. temp�ڵ㲻�������򲿷ֵ�β�ڵ㣬�Ǿͽ���ǰ�ڵ�node���� temp��temp->next�м�
2. ����temp�ڵ���ǵ�ǰ��β�ڵ㣬�Ǿͽ���ǰ�ڵ�node����temp��next�м�

��Ҫע���2�����ʱҪ����prevֵ����Ϊ��ʱ�����������β�ڵ���Ǹող���ĵ�ǰ�ڵ�
*/
ListNode* insertionSortList(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode*node = head->next;
	head->next = nullptr;
	ListNode* prev = head;
	//��������
	while (node != nullptr)
	{
		ListNode* next = node->next;
		node->next = nullptr;
		//��ǰ�ڵ�Ҫ������λ
		if (node->val<head->val)
		{
			node->next = head;
			head = node;
		}
		else
		{
			ListNode* temp = head;
			//������node��ǰ��
			while (temp->next != nullptr&&node->val>temp->next->val)
				temp = temp->next;
			//�������2�����ӽڵ㣬����prev
			if (temp->next == nullptr)
			{
				node->next = next;
				temp->next = node;
				prev = node;
				prev->next = nullptr;
			}
			//�������1�����ӽڵ�
			else
			{
				node->next = temp->next;
				temp->next = node;
			}
		}
		//����node
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