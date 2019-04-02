#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

//116 填充每个节点的下一个右侧节点指针

/*
给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
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
	Node(int _val, Node* _left, Node* _right, Node* _next) {val = _val;left = _left;right = _right;next = _next;}
};

//用队列解决
//这道题我一开始想的是非递归算法，因为我看到了每一层的关系，想到每一层正好同时在一个队列里
//只有当前层最后一个元素出队是不用给next赋值，弹出节点的下一个右侧指针就是弹出后的front节点（画图理解会好理解一些）
//然而测试用例太少了，而且测试用例的树应该都比较小，所以用递归反而快很多
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
			if (i != n - 1&&!q.empty())
				temp->next = q.front();
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
	return root;
}

//方法二：大佬用递归做的
//当时我想的是如果两个节点，一个是当前节点左节点的右节点，一个是右节点的左节点
//会不好处理，因为想找不好找，但是我忘了如果是先序遍历的话，在此之前，这两个节点的父节点已经连到一块了
//所以递归是完全可以的
Node* connect(Node* root) {
	connectCore(root);
	return root;
}
Node* connectCore(Node* root) {
	if (root == nullptr)
		return ;
	//如果节点是叶子节点
	if (root->right == nullptr&&root->left == nullptr)
		return;
	//连接两个子节点
	root->left->next = root->right;
	if (root->next != nullptr)//此时从根到root的路径里肯定包含至少一个left（画图理解）
		root->right->next = root->next->left;
	else
		root->right->next = nullptr;//此时根到root的路径里只包含right
	connect(root->left);
	connect(root->right);
}
int main()
{
	Node* n7 = new Node(7, nullptr, nullptr, nullptr);
	Node* n6 = new Node(6, nullptr, nullptr, nullptr);
	Node* n5 = new Node(5, nullptr, nullptr, nullptr);
	Node* n4 = new Node(4, nullptr, nullptr, nullptr);
	Node* n3 = new Node(3, n6, n7, nullptr);
	Node* n2 = new Node(2, n4, n5, nullptr);
	Node* n1 = new Node(1, n2, n3, nullptr);
	connect(n1);
	return 0;
}