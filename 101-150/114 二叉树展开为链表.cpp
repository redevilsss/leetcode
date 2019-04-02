#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/*
114 给定一个二叉树，原地将它展开为链表。
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//1 后序遍历
//思路：从最左的叶子节点开始，保存其兄弟节点，并取代其兄弟节点的位置，成为其父节点新的右子节点
//将父节点的左子节点置空，然后将原来的右子节点变成这个新右子节点的右子节点，如此展开
//展开到某一步时的步骤：
//首先看该node节点有没有左子节点，没有就继续检查其父节点的右子节点，若左子节点不为空
//1 先找该节点左子节点的最右子节点
//2 将该最右子节点的右子节点（原为空）置为node节点的右子节点
//  也就是说这一步把node的右子节点连到左子节点上了
//3 让上一步连接后的node左子树变成node节点的右子节点
//4 node左子节点清空
//递归版本：
void flatten(TreeNode* root) {
	if (root == nullptr)
		return;
	flatten(root->left);
	flatten(root->right);
	if (root->left != nullptr)
	{
		TreeNode* p = root->left;
		while (p->right)
			p = p->right;
		p->right = root->right;
		root->right = root->left;
		root->left = nullptr;
	}
}
//2 前序遍历,思路都差不多
TreeNode* last = new TreeNode(0);
void flatten(TreeNode* root) {
	if (root == nullptr)
		return;
	//让root成为上一个节点的右节点
	last->right = root;
	//上一个节点的左节点为空
	last->left = nullptr;
	//last更新为root
	last = last->right;
	//保存root节点的右子树,因为下一次递归时会将root的right更新掉，所以要保存右子树
	TreeNode* temp = root->right;
	//遍历左节点
	flatten(root->left);
	//遍历右节点，上面提到了，这里要用temp而不是root->right，因为随着遍历的深入root->right是变化的
	//这是因为每一次遍历都会修改last的right值
	flatten(temp);
}

//3 非递归方法（和方法1类似）
void flatten(TreeNode* root)
{
	TreeNode* now = root;
	while (now)
	{
		if (now->left)
		{
			TreeNode* p = now->left;
			while (p->right)
				p = p->right;
			p->right = now->right;
			now->right = now->left;
			now->left = nullptr;
		}
	}
}