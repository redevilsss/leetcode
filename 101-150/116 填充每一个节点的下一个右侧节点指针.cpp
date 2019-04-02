#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

//116 ���ÿ���ڵ����һ���Ҳ�ڵ�ָ��

/*
����һ��������������������Ҷ�ӽڵ㶼��ͬһ�㣬ÿ�����ڵ㶼�������ӽڵ㡣�������������£�
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
	Node(int _val, Node* _left, Node* _right, Node* _next) {val = _val;left = _left;right = _right;next = _next;}
};

//�ö��н��
//�������һ��ʼ����Ƿǵݹ��㷨����Ϊ�ҿ�����ÿһ��Ĺ�ϵ���뵽ÿһ������ͬʱ��һ��������
//ֻ�е�ǰ�����һ��Ԫ�س����ǲ��ø�next��ֵ�������ڵ����һ���Ҳ�ָ����ǵ������front�ڵ㣨��ͼ��������һЩ��
//Ȼ����������̫���ˣ����Ҳ�����������Ӧ�ö��Ƚ�С�������õݹ鷴����ܶ�
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

//�������������õݹ�����
//��ʱ���������������ڵ㣬һ���ǵ�ǰ�ڵ���ڵ���ҽڵ㣬һ�����ҽڵ����ڵ�
//�᲻�ô�����Ϊ���Ҳ����ң������������������������Ļ����ڴ�֮ǰ���������ڵ�ĸ��ڵ��Ѿ�����һ����
//���Եݹ�����ȫ���Ե�
Node* connect(Node* root) {
	connectCore(root);
	return root;
}
Node* connectCore(Node* root) {
	if (root == nullptr)
		return ;
	//����ڵ���Ҷ�ӽڵ�
	if (root->right == nullptr&&root->left == nullptr)
		return;
	//���������ӽڵ�
	root->left->next = root->right;
	if (root->next != nullptr)//��ʱ�Ӹ���root��·����϶���������һ��left����ͼ��⣩
		root->right->next = root->next->left;
	else
		root->right->next = nullptr;//��ʱ����root��·����ֻ����right
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