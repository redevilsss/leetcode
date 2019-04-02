#include<iostream>
using namespace std;

//222 ��ȫ�������Ľڵ����
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//��ʵ���������������󣬵�������̫���ˣ�Ҫ�����ȫ���������ص㣺
//1.���ĳ�ڵ��������ĸ߶Ⱥ��������ĸ߶�һ������������Ϊ����
//2.���ĳ�ڵ��������߶ȱ���������1����������Ϊ����

/*
��ȫ�������ĸ߶ȿ���ֱ��ͨ�����ϵط����������Ϳ��Ի�ȡ
�ж����������ĸ߶�:
������˵������������������, Ȼ���һ���ж��������Ľڵ���(���һ�������ֵĽڵ��Ȼ����������)
�������˵�������������С������������������, Ȼ���һ���ж��������Ľڵ���(���һ�������ֵĽڵ��Ȼ����������)
*/
int countNodes(TreeNode* root) {
	if (root == nullptr)
		return 0;
	int ld = getDepth(root->left);
	int rd = getDepth(root->right);
	if (ld == rd)//��ʱ�������������ȣ�������Ϊ�������ܽڵ�����������ӽڵ�2��(ld-1)�η�+�������ڵ���
		return (1 << ld) + countNodes(root->right);
	else//��ʱ��������ȱ���������1��˵����ʱ���������������ܽڵ���������������ڵ�2��(rd-1)�η�+�������ڵ���
		return (1 << rd) + countNodes(root->left);
}

//��ȫ������ĳ��ĸ߶Ⱦ�������·���ĳ���
int getDepth(TreeNode* node)
{
	int depth = 0;
	while (node != nullptr)
	{
		depth++;
		node = node->left;
	}
	return depth;
}