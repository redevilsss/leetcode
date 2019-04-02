#include<iostream>
using namespace std;
//236 �������������������

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//�õݹ���ʵ�� �������
/*
	�ֱ��ڵ�ǰ�ڵ���������������Ƿ���p�ڵ��q�ڵ�
	������򷵻��Ǹ��ڵ㣬���򷵻ؿ�ָ��
	�����ǰ�ڵ�����������зֱ���һ��p��q����ǰ�ڵ���������������
	���p��q���ڵ�ǰ�ڵ���������У���leftΪ��������
	������������ͬ��

	�ݹ�ķ�����������rootΪ�ջ�root==p��root==q
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == nullptr || p == root || q == root)
		return root;
	//�ֱ����������������Ƿ���p�ڵ��q�ڵ�
	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);
	if (left != nullptr&&right != nullptr)
		return root;
	else if (left != nullptr)
		return left;
	else if (right != nullptr)
		return right;
	return nullptr;
}