#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//101 对称二叉树

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//方法1：递归方法
bool isSymmetric(TreeNode* left, TreeNode* right)
{
	if (left == nullptr&&right == nullptr)
		return true;
	if (left == nullptr || right == nullptr)
		return false;
	if (left->val != right->val)
		return false;
	//比较左子树的右节点和右子树的左节点  左子树的左节点和右子树的右节点
	return isSymmetric(left->right, right->left) && isSymmetric(left->left, right->right);
}

bool isSymmetric(TreeNode* root) {
	return isSymmetric(root, root);
}

/*
* 方法二 非递归
* 使用栈对节点进行处理
* 首先将根节点的左右子树入栈，当栈不为空时做如下操作：
* 1.先将栈顶的两个节点保存，然后弹出
* 2.判断这两个节点是否同时为空，同时为空则跳过接下来的处理，继续回到1，往出弹元素
*   2中为空的情况一般出现在遍历到所有非空节点都入栈时
* 3.若两元素同时非空，比较其值是否相等，不等则返回false，
*   否则依次置入节点1的左子节点 节点2的右子节点 节点1的右子节点 节点2的左子节点
*  重复上述操作直到栈为空，返回结果，注意栈中元素无论什么时候都是2的倍数，每次都是对某节点的左右节点共同操作
*  重点就在于要让两个节点的左右子节点交叉入栈
*/
bool isSymmetric(TreeNode* root) {
	if (root == nullptr)
		return true;
	stack<TreeNode*> s;
	s.push(root->right);
	s.push(root->left);
	while (!s.empty())
	{
		TreeNode* node1 = s.top();
		s.pop();
		TreeNode* node2 = s.top();
		s.pop();
		if (node1 == nullptr&&node2 == nullptr)
			continue;
		if (node1 != nullptr&&node2 != nullptr)
		{
			if (node1->val != node2->val)
				return false;
			s.push(node1->right);
			s.push(node2->left);
			s.push(node1->left);
			s.push(node2->right);
		}
		else
			return false;
	}
	return true;
}