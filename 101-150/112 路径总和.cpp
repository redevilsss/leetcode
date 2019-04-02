#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//112 路径总和

/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，
这条路径上所有节点值相加等于目标和。
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