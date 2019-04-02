#include<iostream>
using namespace std;
//235 二叉搜索树的最近公共祖先
/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
示例 1:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6
解释: 节点 2 和节点 8 的最近公共祖先是 6。
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//递归解法
/*
充分利用二叉搜索树的特点，如果root的值在p值和q值中间，说明当前root节点就是最近公共祖先
否则，如果root的值比q值和p值都大，说明p和q都在root的左子树中
如果root的值比q值和p值都小，说明p和q都在root的右子树中
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == nullptr || root == p || root == q)
		return root;
	if (root->val>p->val&&root->val>q->val)
		return lowestCommonAncestor(root->left, p, q);
	else if (root->val<p->val&&root->val<q->val)
		return lowestCommonAncestor(root->right, p, q);
	return root;
}
//非递归解法
/*
思路类似，
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	int max = p->val>q->val ? p->val : q->val;
	int min = p->val + q->val - max;
	TreeNode* temp = root;
	//如果当前两个节点在temp的同侧，继续循环
	while (temp != nullptr && (temp->val>max || temp->val<min))
	{
		//如果两个节点的值都比temp小，temp取其左子节点
		if (temp->val>min)
			temp = temp->left;
		//如果两个节点的值都比temp大，temp取其右子节点
		else if (temp->val<min)
			temp = temp->right;
	}
	return temp;
}