#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//112 ·���ܺ�

/*
����һ����������һ��Ŀ��ͣ��жϸ������Ƿ���ڸ��ڵ㵽Ҷ�ӽڵ��·����
����·�������нڵ�ֵ��ӵ���Ŀ��͡�
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode* root, int sum) {
	if (root == nullptr)
		return false;
	if (root->left == nullptr&&root->right == nullptr&&root->val == sum)
		return true;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}