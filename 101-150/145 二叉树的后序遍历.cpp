#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//145 二叉树的后序遍历 递归和迭代

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归实现
vector<int> res;
vector<int> postorderTraversal(TreeNode* root) {
	if (root == nullptr)
		return res;
	postorderTraversalCore(root);
	return res;
}
void postorderTraversalCore(TreeNode* root)
{
	if (root == nullptr)
		return;
	postorderTraversalCore(root->left);
	postorderTraversalCore(root->right);
	res.push_back(root->val);
}

//非递归实现
vector<int> res;
vector<int> postorderTraversal(TreeNode* root) {
	if (root == nullptr)
		return res;
	stack<TreeNode*> treeNodeStack;
	TreeNode* pNode = root;
	TreeNode* pLastVisited = root;
	while (pNode != nullptr || !treeNodeStack.empty())
	{
		while (pNode != nullptr)
		{
			treeNodeStack.push(pNode);
			pNode = pNode->left;
		}
		//查看当前栈顶元素
		pNode = treeNodeStack.top();
		//如果其右子树也为空，或者右子树已经访问
		//则可以直接输出当前节点的值
		if (pNode->right == nullptr || pNode->right == pLastVisited)
		{
			res.push_back(pNode->val);
			treeNodeStack.pop();
			pLastVisited = pNode;
			pNode = nullptr;
		}
		//否则，继续遍历右子树
		else
			pNode = pNode->right;
	}
	return res;
}