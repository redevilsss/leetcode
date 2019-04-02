#include<iostream>
#include<vector>
using namespace std;

//160 �ཻ����
/*
��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
*/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


/*
���ǽ�ָoffer��52�⣬���ཻ����Ľ���
��ָoffer�ķ���˼·���£�
���ȱ��������ǿ϶����еģ����ų���
��Ϊ�ཻ������ ��Y �͵ģ���֧��ǰ�����������ֲ治һ�����������Ȱѷֲ�����
Ȼ��ͬʱ����������������Ҳ��ǿգ��ͷ��ص�ǰ�ڵ㣬��������귵�ؿսڵ�
˼·���£�
1. �����������ȺͲ�ֵ
2. �ҵ���������Ͷ̵�����
3. ���������� ��ֵ ��
4. ��������ͬʱ�ߣ��жϽڵ��Ƿ����
*/

//���㳤��
int getLength(ListNode* head)
{
	ListNode* temp = head;
	int i = 0;
	while (temp != nullptr)
	{
		i++;
		temp = temp->next;
	}
	return i;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA == nullptr || headB == nullptr)
		return nullptr;
	int lengthOfA = getLength(headA);
	int lengthOfB = getLength(headB);
	//�ҳ�����Ͷ�����
	int length = lengthOfA;
	ListNode* Long = headA;
	ListNode* Short = headB;
	int dif = lengthOfA - lengthOfB;
	if (dif<0)
	{
		Long = headB;
		Short = headA;
		length = lengthOfB;
		dif = -dif;
	}
	//��������
	for (int i = 0; i<dif; i++)
		Long = Long->next;
	//����һ����
	while (Long != nullptr&&Short != nullptr)
	{
		if (Long == Short)
			return Long;
		Long = Long->next;
		Short = Short->next;
	}
	return nullptr;
}


//��Ȼ���������ķ���
/*
���ǵ�֮ǰ���ǵ��ж������Ƿ��л����ڵ�����
��Ȼ�������û�л��������ǿ�������һ�������������һ�������β�ڵ�ָ������ͷ
������������ཻ����ʱ����ͱ����һ������������
�������ÿ���ָ�����ж���û�л�������л���ȥ�ҵ�������ڣ�����������ཻ�ڵ�
˼·����
1. ��������B��β����ͷ�����컷
2. ����ָ���ж���û�л�
3. ����л����һ���û���ͷ���nullptr
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if (headA == nullptr || headB == nullptr)
		return nullptr;
	ListNode* last = headB;
	while (last->next != nullptr)
		last = last->next;
	last->next = headB;

	ListNode* fast = headA;
	ListNode* slow = headA;
	while (fast!=nullptr&&fast->next!=nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)//˵���л�
		{
			//֤��Ϊʲô�����ڵ�����ʱ��������һ���ڵ�������������ڵ�ͬ����
			//����ʱ������ڴ�
			/*
			����ǻ����ֳ���Ϊl�������ֳ���Ϊr����ڵ�׷�����ڵ�ʱΪtʱ��
			��(2t-l)%r==(t-l)%r,Ҳ����˵t�ܱ�r�����������ڵ���˵�����ڻ�������t-l��
			��ʱ���������һ���ڵ��ͷ�������ýڵ�Ҫ��l��������ڣ������нڵ���l�������ڻ�������t
			t�ܱ�r��������ʱ���нڵ�Ҳ����ڴ�

			*/
			slow = headA;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			last->next = nullptr;
			return fast;
		}
	}
	last->next = nullptr;
	return nullptr;
}