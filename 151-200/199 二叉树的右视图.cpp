#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 这道题可以用递归也可以用非递归
//非递归方式使用数据结构queue，递归方式则是用前序遍历

/*
方法一：层序遍历
类似于之前的按层打印二叉树元素，只不过要把每一层的最后一个元素值置入res，
这个元素就是当前层从右边看到的元素
*/
vector<int> rightSideView(TreeNode* root) {
	if (root == nullptr)
		return {};
	vector<int> res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		//当前层节点个数
		int size = q.size();
		//用于计数
		int count = 0;
		while (count<size)
		{
			TreeNode* node = q.front();
			q.pop();
			//和逐层打印唯一的不同，就是每一层的最后一个元素入res数组
			if (count == size - 1)
				res.push_back(node->val);
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
			count++;
		}

	}
	return res;
}

/*
方法二：前序遍历
用前序遍历来实现，设置数组res表示右视图，遍历顺序为中右左，因为要求的是右视图
当res的元素数小于当前节点深度时，才将节点值加入res
换句话就是，只有遍历到第一个深度为i+1的节点时，将节点加入res中，res元素个数也从i变成i+1
所以，只要我向下遍历的时候是先右后左，就能保证每次加入res的元素值是当前层最右节点的元素值
*/
vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	if (root == nullptr)
		return res;
	dfs(root, res, 1);
	return res;
}
void dfs(TreeNode* node, vector<int>& res, int depth)
{
	if (depth>res.size())
		res.push_back(node->val);
	if (node->right)
		dfs(node->right, res, depth + 1);
	if (node->left)
		dfs(node->left, res, depth + 1);
}

int main()
{
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	t1->left = t2;
	t1->right = t3;
	t2->right = t5;
	t3->right = t4;
	vector<int> res=rightSideView(t1);
	return 0;
}