#include<iostream>
using namespace std;
//236 二叉树的最近公共祖先

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//用递归来实现 后序遍历
/*
	分别在当前节点的左右子树里找是否有p节点和q节点
	如果有则返回那个节点，无则返回空指针
	如果当前节点的左右子树中分别有一个p和q，则当前节点就是最近公共祖先
	如果p和q都在当前节点的左子树中，则left为公共祖先
	都在右子树中同理

	递归的返回条件就是root为空或root==p或root==q
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == nullptr || p == root || q == root)
		return root;
	//分别在左右子树中找是否有p节点和q节点
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