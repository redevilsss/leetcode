#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//95 不同的二叉搜索树2

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//start和end分别表示所取节点值大小的上下限
vector<TreeNode*> generateTrees(int start, int end)
{
	vector<TreeNode*> res;
	if (start>end)//当start>end时子树为空
	{
		res.push_back(nullptr);
		return res;
	}
	//分别以start~end为根节点
	//每次遍历先求出左右子树，再用根节点去连接左右子树
	for (int i = start; i <= end; i++)
	{
		vector<TreeNode*> subLeftTree = generateTrees(start, i - 1);
		vector<TreeNode*> subRightTree = generateTrees(i + 1, end);
		for (TreeNode* left : subLeftTree)
		{
			for (TreeNode* right : subRightTree)
			{
				//构造节点，并使该节点分别连接其左右子树，然后将该节点置入数组
				//最终的结果是层序遍历
				TreeNode* node = new TreeNode(i);
				node->left = left;
				node->right = right;
				res.push_back(node);
			}
		}
	}
	return res;
}

vector<TreeNode*> generateTrees(int n) {
	vector<TreeNode*> res;
	if (n == 0)
		return res;
	return generateTrees(1, n);
}

int main()
{
	vector<TreeNode*> res = generateTrees(3);
	return 0;
}