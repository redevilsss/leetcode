#include<iostream>
#include<stack>
using namespace std;
//230 二叉搜索树第k小的元素
/*
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//可以递归解决也可以用栈来实现中序遍历

//递归方法1
//getNum函数用于计算当前节点的子节点个数
int getNum(TreeNode* node)
{
	if (node == nullptr)
		return 0;
	int left = getNum(node->left);
	int right = getNum(node->right);
	return 1 + left + right;
}

int kthSmallest(TreeNode* root, int k) {
	//如果当前节点的左子节点比k小，说明第k小的元素在右子树中
	if (getNum(root->left)<k-1)
		return kthSmallest(root->right, k - getNum(root->left)-1);
	//如果当前节点的左子节点比k大，说明第k小的元素在左子树中
	else if (getNum(root->left)>k-1)
		return kthSmallest(root->left, k );
	//否则，当前节点就是第k小的元素
	else
		return root->val;
}

//递归方法2

//非递归方法 中序遍历 左中右，符合二叉搜索树的特点
int kthSmallest(TreeNode* root, int k) {
	stack<TreeNode*> s;
	int res;
	while ((root != nullptr || !s.empty()) && k)
	{
		if (root != nullptr)
		{
			s.push(root);
			root = root->left;
		}
		else
		{
			root = s.top();
			s.pop();
			--k;
			res = root->val;
			root = root->right;
		}
	}
	return res;
}


int main()
{
	TreeNode* t1 = new TreeNode(3);
	TreeNode* t2 = new TreeNode(1);
	TreeNode* t3 = new TreeNode(4);
	TreeNode* t4 = new TreeNode(2);
	t1->left = t2;
	t1->right = t3;
	t2->right = t3;
	int res = kthSmallest(t1,1);
	return 0;
}
