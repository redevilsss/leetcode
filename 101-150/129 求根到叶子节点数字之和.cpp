#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//129 求根到叶子节点数字之和
/*
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
例如，从根到叶子节点路径 1->2->3 代表数字 123。
计算从根到叶子节点生成的所有数字之和。
说明: 叶子节点是指没有子节点的节点。
*/

//类似于112 113题，没什么技术含量，简单修改拿来直接用
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//思路：遍历求每条路径的节点数字和，到叶子节点时叠加到最终结果上
//sum表示当前路径和，res表示当前路径总和
int sumNumbers(TreeNode* root) {
	if (root == nullptr)
		return 0;
	int res = 0;
	sumNumbers(root, 0, res);
	return res;
}
void sumNumbers(TreeNode* root, int sum, int& res)
{
	if (root == nullptr)
		return;
	//root非空，叠加当前节点值，通过 *10+ 实现路径到数字的转换
	sum = sum * 10 + root->val;
	//叶子节点，叠加到res上，返回
	if (root->left == nullptr&&root->right == nullptr)
	{
		res += sum;
		return;
	}
	//遍历左右子树
	if (root->left)
		sumNumbers(root->left, sum, res);
	if (root->right)
		sumNumbers(root->right, sum, res);
}