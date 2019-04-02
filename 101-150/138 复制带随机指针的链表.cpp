#include<iostream>
#include<vector>
using namespace std;

//138 ���ƴ����ָ�������
/*
����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
Ҫ�󷵻��������������
*/

//����һ��
//˼·�����ճ�����˼��ֱ��ʵ���Ǻ��ѵģ���Ϊ������֪��ÿ���ڵ��randomָ������
//�������Ĺؼ�������θ�ֵrandom�������Կ��������������ȸ���ÿһ���ڵ㣬�������ԭ�ڵ�ĺ���
//Ϊʲô����������Ϊ����,��һ���ڵ�random��next����copy�ڵ�random��λ��copy->random=node->random->next
//Ȼ��ֻ��Ҫ������һ��Ϊ����һ��Ϊԭ����������һ��������copy����������
class Node {
public:
	int val;
	Node* next;
	Node* random;
	Node() {}
	Node(int _val, Node* _next, Node* _random) {val = _val;next = _next;random = _random;}
};

//��������������ƽڵ�
void copyNodes(Node* head)
{
	Node* node = head;
	while (node != nullptr)
	{
		Node* copy = new Node(node->val,nullptr,nullptr);//�����ڵ�
		copy->random = nullptr;//�½ڵ�randomָ���ÿգ���һ���ٸ���
		copy->next = node->next;//���½ڵ����ԭ�ڵ���棬���Ӻ�
		node->next = copy;
		node = copy->next;//���µ�ǰ��nodeֵ
	}
}
//���������������randomָ��
void connectRandomNodes(Node* head)
{
	Node* node = head;
	while (node != nullptr)
	{
		Node* copy = node->next;
		if (node->random != nullptr)
			copy->random = node->random->next;
		node = copy->next;
	}
}
//������������������
Node* devidedNode(Node* head)
{
	Node* node = head;
	Node* copyHead = nullptr;
	Node* copyNode = nullptr;
	//�����������ͷ�ڵ�
	if (node != nullptr)
	{
		copyHead = copyNode = node->next;
		node->next = copyNode->next;
		node = node->next;
	}
	while (node != nullptr)
	{
		copyNode->next = node->next;
		copyNode = copyNode->next;
		node->next = copyNode->next;
		node = node->next;
	}
	return copyHead;
}

Node* copyRandomList(Node* head) {
	copyNodes(head);
	connectRandomNodes(head);
	return devidedNode(head);
}

int main()
{
	Node* n2 = new Node(2, nullptr, nullptr);
	n2->random = n2;
	Node* n1 = new Node(1, n2, n2);
	copyRandomList(n1);
	return 0;
}