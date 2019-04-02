#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//117 ���ÿ���ڵ����һ���Ҳ�ڵ�ָ��
/*
����һ��������
struct Node {
int val;
Node *left;
Node *right;
Node *next;
}
�������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL��
��ʼ״̬�£����� next ָ�붼������Ϊ NULL��
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

//����һ����116��һģһ��
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

//������ �ݹ鷽��
//��ǰ�����ƣ��������жϺ����ӽڵ��next�ڵ�
Node* connect(Node* root) {
	if (root == nullptr)
		return root;
	//����ڵ���Ҷ�ӽڵ�
	if (root->right == nullptr&&root->left == nullptr)
		return root;
	//��ȡ�ýڵ����ӽڵ��next��ͨ���ýڵ��next����ȡ�������ǵ�����ֱ��ȡnext��left,��Ϊѡ��Ķ�����������ȫ��������
	Node* next = getNext(root->next);
	//����Ҫ��������������ˣ�������һ��ֱ����
	if (root->left&&root->right)
	{
		root->left->next = root->right;
		root->right->next = next;
	}
	if (root->left == nullptr)
		root->right->next = next;
	if (root->right == nullptr)
		root->left->next = next;
	//Ϊʲô����Ҫ�ȱ����ұߺ������ߣ�
	//��ͷ��ǰ������ĳ�ڵ���ӽڵ����ڵķǿսڵ�ʱ�õ���getNext����������ȱ�����ߺ�����ұߣ���ôgetNext�ķ���ֵ�����ǿ�
	//Ҫ��������������У���Ϊֻ��������һ�α�����ʱ�����ȡ��׼ȷ��nextֵ
	connect(root->right);
	connect(root->left);
	return root;
}

Node* getNext(Node* next)
{
	//ѭ����next�ĵ�һ���ǿ��ӽڵ�
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
