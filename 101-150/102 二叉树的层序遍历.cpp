#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//102 二叉树的层序遍历
/*
给定一个二叉树，返回其按层次遍历的节点值。
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//思路很简单，就是通过队列实现
//首先放入根节点，然后当队列不为空时循环，有几层遍历几次
//count用于记录当前层的节点个数，定义temp数组存储该层元素
//对于每一个节点，保存节点，记录节点值并出队列，然后将该节点的左右子节点入队列
//每层节点遍历完成后，将所得temp数列放入res数组
vector<vector<int>> res;
vector<vector<int>> levelOrder(TreeNode* root) {
	if (root == nullptr)
		return res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int count = q.size();
		vector<int> temp;
		while (count--)
		{
			TreeNode* node = q.front();
			q.pop();
			temp.push_back(node->val);
			if (node->left != nullptr)
				q.push(node->left);
			if (node->right != nullptr)
				q.push(node->right);
		}
		res.push_back(temp);
	}
	return res;

}