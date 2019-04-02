#include<iostream>
#include<vector>
using namespace std;

//138 复制带随机指针的链表
/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
要求返回这个链表的深拷贝。
*/

//方法一：
//思路：按照常理来思考直接实现是很难的，因为根本不知道每个节点的random指向哪里
//这个问题的关键在于如何赋值random链表，所以考虑这样来做：先复制每一个节点，将其插入原节点的后面
//为什么这样做？因为这样,上一个节点random的next就是copy节点random的位置copy->random=node->random->next
//然后只需要将链表一分为二，一个为原来的链表，另一个就是新copy出来的链表
class Node {
public:
	int val;
	Node* next;
	Node* random;
	Node() {}
	Node(int _val, Node* _next, Node* _random) {val = _val;next = _next;random = _random;}
};

//这个函数用来复制节点
void copyNodes(Node* head)
{
	Node* node = head;
	while (node != nullptr)
	{
		Node* copy = new Node(node->val,nullptr,nullptr);//创建节点
		copy->random = nullptr;//新节点random指针置空，下一步再复制
		copy->next = node->next;//将新节点接在原节点后面，连接好
		node->next = copy;
		node = copy->next;//更新当前的node值
	}
}
//这个函数用来复制random指针
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
//这个函数用来拆分链表
Node* devidedNode(Node* head)
{
	Node* node = head;
	Node* copyHead = nullptr;
	Node* copyNode = nullptr;
	//创建新链表的头节点
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