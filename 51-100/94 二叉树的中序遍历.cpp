#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//94 二叉树的前序遍历 递归和迭代


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//递归方法，无脑简单
vector<int> res;
vector<int> inorderTraversal(TreeNode* root) {
	if (root == nullptr)
		return res;
	inorderTraversalCore(root);
	return res;
}
void inorderTraversalCore(TreeNode* root)
{
	if (root->left)
		inorderTraversalCore(root->left);
	res.push_back(root->val);
	if (root->right)
		inorderTraversalCore(root->right);

}


//非递归实现
//用栈来实现，因为前序遍历的第一个节点是最左叶子节点，在向左的时候要把路径上的节点都保存下来，方便获取节点右子节点的值
//和非递归先序遍历类似，唯一区别是考查到当前节点时，并不直接输出该节点
//而是当考查节点为空时，从栈中弹出的时候再进行输出(永远先考虑左子树，直到左子树为空才访问根节点)。
vector<int> res;
vector<int> inorderTraversal(TreeNode* root) {
	// 用来暂存节点的栈
	stack<TreeNode* > treeNodeStack;
	// 新建一个游标节点为根节点
	TreeNode* pNode = root;
	// 当遍历到最后一个节点的时候，无论它的左右子树都为空，并且栈也为空
	// 所以，只要不同时满足这两点，都需要进入循环
	while (pNode != nullptr || !treeNodeStack.empty())
	{
		while (pNode != nullptr)
		{
			// 由考查顺序得知，需要一直往左走
			// 为了之后能找到该节点的右子树，暂存该节点
			treeNodeStack.push(pNode);
			pNode = pNode->left;
		}
		if (!treeNodeStack.empty())
		{
			// 一直到左子树为空，则开始考虑右子树
			// 如果栈已空，就不需要再考虑
			// 弹出栈顶元素，将栈顶元素值放入数组，将游标等于该节点的右子树
			pNode = treeNodeStack.top();
			treeNodeStack.pop();
			res.push_back(pNode->val);
			pNode = pNode->right;
		}
	}
	return res;
}
