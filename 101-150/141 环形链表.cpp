#include<iostream>
#include<vector>
using namespace std;


/*
����һ�������ж��������Ƿ��л���
Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� 
��� pos �� -1�����ڸ�������û�л���
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

//�����ܼ򵥣��ж���û�л���һ���ʹ�ÿ�������ָ�룬��ָ��һ������������ָ��һ����һ��
//��������ڣ���ָ����ڻ��ж���һȦ׷����ָ��
//��Ϊ�����κ�һ���ڵ㶼�к�̽ڵ㣬������ʱ�����whileѭ��������ѭ��������ָ���һ��׷����ָ��ʱ��������ȷ
//��������ʱ����ָ�벻����׷����ָ�룬���ȵ���nullptr���˳�����false
bool hasCycle(ListNode *head) {
	if (head == nullptr)
		return false;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != nullptr&&slow != nullptr)
	{
		fast = fast->next;
		if (fast == nullptr)
			return false;
		fast = fast->next;
		if (fast == slow)
			return true;
		slow = slow->next;

	}
	return false;
}