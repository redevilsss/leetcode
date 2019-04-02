#include<iostream>
using namespace std;

//222 完全二叉树的节点个数
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//其实可以整个遍历来求，但是这样太慢了，要结合完全二叉树的特点：
//1.如果某节点左子树的高度和右子树的高度一样，则左子树为满树
//2.如果某节点左子树高度比右子树多1，则右子树为满树

/*
完全二叉树的高度可以直接通过不断地访问左子树就可以获取
判断左右子树的高度:
如果相等说明左子树是满二叉树, 然后进一步判断右子树的节点数(最后一层最后出现的节点必然在右子树中)
如果不等说明右子树是深度小于左子树的满二叉树, 然后进一步判断左子树的节点数(最后一层最后出现的节点必然在左子树中)
*/
int countNodes(TreeNode* root) {
	if (root == nullptr)
		return 0;
	int ld = getDepth(root->left);
	int rd = getDepth(root->right);
	if (ld == rd)//此时左右子树深度相等，左子树为满树，总节点个数就是左子节点2的(ld-1)次方+右子树节点数
		return (1 << ld) + countNodes(root->right);
	else//此时右子树深度比左子树少1，说明此时右子树是满树，总节点个数就是右子树节点2的(rd-1)次方+左子树节点数
		return (1 << rd) + countNodes(root->left);
}

//完全二叉树某点的高度就是最左路径的长度
int getDepth(TreeNode* node)
{
	int depth = 0;
	while (node != nullptr)
	{
		depth++;
		node = node->left;
	}
	return depth;
}