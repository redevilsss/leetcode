#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//99 恢复二叉搜索树
/*
二叉搜索树中的两个节点被错误地交换。
请在不改变其结构的情况下，恢复这棵树。
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* mistakeNode1;
TreeNode* mistakeNode2;
TreeNode* pre = nullptr;
//用来记录遍历节点的前一个节点
//中序遍历正常情况下为升序排列，出现降序排列即为错误，需要交换两个错误节点
//出现两次降序时则交换第一次降序val值较大的错误节点和第二次降序val值较小的错误节点
//出现一次降序的情况发生在父节点与某个子节点交换时
//举例 4 2 7 1 3 5 nullptr，此时2和3位置错误，将其交换
//出现两次降序时，错误发生的节点没有直接的父子关系
//举例 4 5 7 1 2 3 nullptr，此时中序遍历为1 5 2 4 3 7 可以看到有5 2和4 3两个降序序列
//此时交换第一次降序值较大的节点 也就是5 和第二次降序值较小的节点 也就是3
void dfsTree(TreeNode* root) {
	if (root == nullptr)
		return;
	if (root->left != nullptr)//遍历其左子树
		dfsTree(root->left);
	if (pre != nullptr&&pre->val>root->val)//pre为中序遍历当前root的前一个节点，若其值大于当前节点值说明出现错位
	{
		//第一次发现降序，分别记录当前的pre节点和root节点
		if (mistakeNode1 == nullptr)
		{
			mistakeNode1 = pre;
			mistakeNode2 = root;
		}
		//第二次发现降序时，更新错误节点2为当前节点
		else
			mistakeNode2 = root;
	}
	pre = root;
	if (root->right != nullptr)//遍历其右子树
		dfsTree(root->right);
}

void recoverTree(TreeNode* root)
{
	dfsTree(root);//遍历二叉搜索树找到两个错误节点
	//交换节点值
	int temp = mistakeNode1->val;
	mistakeNode1->val = mistakeNode2->val;
	mistakeNode2->val = temp;
}