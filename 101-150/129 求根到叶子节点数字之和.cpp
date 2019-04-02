#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//129 �����Ҷ�ӽڵ�����֮��
/*
����һ��������������ÿ����㶼���һ�� 0-9 �����֣�ÿ���Ӹ���Ҷ�ӽڵ��·��������һ�����֡�
���磬�Ӹ���Ҷ�ӽڵ�·�� 1->2->3 �������� 123��
����Ӹ���Ҷ�ӽڵ����ɵ���������֮�͡�
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
*/

//������112 113�⣬ûʲô�������������޸�����ֱ����
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//˼·��������ÿ��·���Ľڵ����ֺͣ���Ҷ�ӽڵ�ʱ���ӵ����ս����
//sum��ʾ��ǰ·���ͣ�res��ʾ��ǰ·���ܺ�
int sumNumbers(TreeNode* root) {
	if (root == nullptr)
		return 0;
	int res = 0;
	sumNumbers(root, 0, res);
	return res;
}
void sumNumbers(TreeNode* root, int sum, int& res)
{
	if (root == nullptr)
		return;
	//root�ǿգ����ӵ�ǰ�ڵ�ֵ��ͨ�� *10+ ʵ��·�������ֵ�ת��
	sum = sum * 10 + root->val;
	//Ҷ�ӽڵ㣬���ӵ�res�ϣ�����
	if (root->left == nullptr&&root->right == nullptr)
	{
		res += sum;
		return;
	}
	//������������
	if (root->left)
		sumNumbers(root->left, sum, res);
	if (root->right)
		sumNumbers(root->right, sum, res);
}