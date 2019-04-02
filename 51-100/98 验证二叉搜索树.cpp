#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//98 验证二叉搜索树

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//用中序遍历的思想，二叉搜索树中序遍历是严格升序，所以每次遍历完保存当前遍历到的值，如果下一个值大于这个值，更新这个值继续遍历
//否则停止遍历返回false

//设置变量保存值
long last = LONG_MIN;//考虑到根节点可能是INT_MIN，初始的last变量得是long类型的最小值
bool isValidBST(TreeNode* root) {
	if (root == nullptr)
		return true;
	if (isValidBST(root->left))//若该节点的左子树为二叉搜索树，判断该节点，若该节点值大于当前保存值，则更新保存值，继续遍历其右子树，否则直接返回false
	{
		if (last<root->val)
		{
			last = root->val;
			return isValidBST(root->right);
		}
	}
	return false;
}
