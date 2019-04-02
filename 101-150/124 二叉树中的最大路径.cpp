#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

/*
这道题是看着大佬的思路做的，看到通过率30%的题就发怵，但其实也不难
后序遍历子树，从叶子节点到根节点进行统计，有两种情况需要考虑
1.以当前节点为根，可以构成的最大和可能有4种：
 (1)节点值加左子树最大和（右子树最大路径和小于0）
 (2)节点值加右子树最大和（左子树最大路径和小于0）
 (3)节点值（左右子树最大路径和都小于0）
 (4)节点值加左右子树最大和
 在这里，首先判断左右子树最大和是不是大于0，如果小于0，则将其置零，
 因为某个子树的最大路径和小于0时，以当前节点为根节点的子数组的最大路径不包括这个子树
2.以当前节点为最大路径和的中间某一点时（非根节点），只能选取其中一侧的子树(要配合当前的根节点构成路径)
 所以有三种情况，分别为1中提到的(1)(2)(3)
 以当前节点为根节点得到的最大路径和可以直接用来更新最大路径和maxValue
 以当前节点为非根节点得到的最大路径和需要return给上一步，返回给getMax(node->left)和getMax(node->right)
 数组遍历完即可得到最大路径和
*/
int maxValue =INT_MIN;//记录当前最大和

int getMax(TreeNode* node)
{
	if (node == nullptr)
		return 0;
	//求当前节点左右子树的最大路径和
	int left = max(0, getMax(node->left));
	int right = max(0, getMax(node->right));
	//以当前节点为根节点的最大路径和node->val + left + right，更新maxValue
	maxValue = max(maxValue, node->val + left + right);
	//以当前节点为非根节点的最大路径和，需要return给上一层
	return max(left, right) + node->val;
}

int maxPathSum(TreeNode* root) {
	getMax(root);
	return maxValue;
}
int main()
{
	TreeNode* n1 = new TreeNode(-1);
	TreeNode* n2 = new TreeNode(-2);
	TreeNode* n3 = new TreeNode(-3);
	n1->left = n2;
	n1->right = n3;
	int res = maxPathSum(n1);
	return 0;
}