#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//117 填充每个节点的下一个右侧节点指针
/*
给定一个二叉树
struct Node {
int val;
Node *left;
Node *right;
Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。
*/

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node() {}
	Node(int _val, Node* _left, Node* _right, Node* _next) { val = _val; left = _left; right = _right; next = _next; }
};

//方法一，和116题一模一样
Node* connect(Node* root) {
	if (root == nullptr)
		return root;
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		int n = q.size();
		for (int i = 0; i<n; i++)
		{
			Node* temp = q.front();
			q.pop();
			if (i != n - 1 && !q.empty())
				temp->next = q.front();
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
	return root;
}

//方法二 递归方法
//与前面类似，增加了判断和找子节点的next节点
Node* connect(Node* root) {
	if (root == nullptr)
		return root;
	//如果节点是叶子节点
	if (root->right == nullptr&&root->left == nullptr)
		return root;
	//获取该节点右子节点的next（通过该节点的next来获取，而不是单纯的直接取next的left,因为选择的二叉树不是完全二叉树）
	Node* next = getNext(root->next);
	//这里要分三种情况讨论了，不像上一题直接连
	if (root->left&&root->right)
	{
		root->left->next = root->right;
		root->right->next = next;
	}
	if (root->left == nullptr)
		root->right->next = next;
	if (root->right == nullptr)
		root->left->next = next;
	//为什么这里要先遍历右边后遍历左边？
	//回头看前面找与某节点的子节点相邻的非空节点时用到的getNext函数，如果先遍历左边后遍历右边，那么getNext的返回值都会是空
	//要从右向左遍历才行，因为只有这样下一次遍历的时候才能取到准确的next值
	connect(root->right);
	connect(root->left);
	return root;
}

Node* getNext(Node* next)
{
	//循环找next的第一个非空子节点
	while (next)
	{
		if (next->left)
			return next->left;
		if (next->right)
			return next->right;
		next = next->next;
	}
	return nullptr;
}
