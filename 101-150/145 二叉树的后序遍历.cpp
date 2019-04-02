#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//145 �������ĺ������ �ݹ�͵���

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//�ݹ�ʵ��
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

//�ǵݹ�ʵ��
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
		//�鿴��ǰջ��Ԫ��
		pNode = treeNodeStack.top();
		//�����������ҲΪ�գ������������Ѿ�����
		//�����ֱ�������ǰ�ڵ��ֵ
		if (pNode->right == nullptr || pNode->right == pLastVisited)
		{
			res.push_back(pNode->val);
			treeNodeStack.pop();
			pLastVisited = pNode;
			pNode = nullptr;
		}
		//���򣬼�������������
		else
			pNode = pNode->right;
	}
	return res;
}