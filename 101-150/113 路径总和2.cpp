#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//113 路径总和2
/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//和112题相比多了对于路径节点值的存储
//paths为最终的结果，path为一条路径
//进入递归后，首先更新sum剩余值，将当前节点的值入数组
//如果当前节点为叶子节点且此时sum剩余值为0，就将此时的path存入最终paths中
//否则，分别遍历左右子树

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> paths;
	vector<int> path;
	if (root == nullptr)
		return paths;
	pathSum(root, paths, path, sum);
	return paths;
}
void pathSum(TreeNode* root, vector<vector<int>>& paths, vector<int>& path, int sum)
{
	sum -= root->val;
	path.push_back(root->val);

	if (root->right == nullptr&&root->left == nullptr&&sum == 0)
		paths.push_back(path);
	if (root->left != nullptr)
		pathSum(root->left, paths, path, sum);
	if (root->right != nullptr)
		pathSum(root->right, paths, path, sum);
	path.pop_back();
}