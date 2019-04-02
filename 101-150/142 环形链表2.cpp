#include<iostream>
#include<vector>
using namespace std;

//142 ��������2
/*
����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���
˵�����������޸ĸ���������
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

//˼·�����ж���û�л�������У����ػ�������һ�㣬��ͨ�����������ҵ�����ڣ��ж���û�л��Ĳ��־���141��
ListNode *detectCycle(ListNode *head) {
	ListNode* meetingNode = hasCycle(head);
	if (meetingNode == nullptr)
		return nullptr;
	//���㻷�нڵ�ĸ���length
	ListNode* node1 = meetingNode;
	int length = 1;
	while (node1->next != meetingNode)
	{
		length++;
		node1 = node1->next;
	}
	//node1��ͷ�ڵ㿪ʼ��length��
	node1 = head;
	for (int i = 0; i<length; i++)
		node1 = node1->next;
	//������һ��ָ��node2��ͷ�ڵ㿪ʼ��node1��node2ͬʱ��ǰ�ߣ�ĳһʱ������ָ��ͬһ�ڵ㣬�ýڵ���ǻ�����ڽڵ�
	//Ϊʲô�أ���������ǻ�����Ϊl������Ϊr���������l������εõ�l�أ�
	//���ýڵ�1����r������ڵ�1�뻷��ڵľ���Ϊl-r��r-l
	//��������r-l��˵����ʱ�ڵ�1�Ѿ����뻷������r�����뻷��r-l����ʱ�ڵ�2Ҳ��ʼ�ߣ����ڵ�ͬʱ��r-(r-l)=l�������ڵ�������������lλ��
	//��������l-r��˵����ʱ�ڵ�1��û����������r������l-r�뻷����ʱ�ڵ�2Ҳ��ʼ�ߣ����ڵ�ͬʱ��l-r+r=l�������ڵ���������lλ��
	ListNode* node2 = head;
	while (node1 != node2)
	{
		node1 = node1->next;
		node2 = node2->next;
	}
	return node1;


}
//��ǰһ�����һ��
ListNode *hasCycle(ListNode *head) {
	if (head == nullptr)
		return nullptr;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != nullptr&&slow != nullptr)
	{
		fast = fast->next;
		if (fast == nullptr)
			return nullptr;
		fast = fast->next;
		if (fast == slow)
			return fast;
		slow = slow->next;

	}
	return nullptr;
}