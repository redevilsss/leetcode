#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//101 �Գƶ�����

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//����1���ݹ鷽��
bool isSymmetric(TreeNode* left, TreeNode* right)
{
	if (left == nullptr&&right == nullptr)
		return true;
	if (left == nullptr || right == nullptr)
		return false;
	if (left->val != right->val)
		return false;
	//�Ƚ����������ҽڵ������������ڵ�  ����������ڵ�����������ҽڵ�
	return isSymmetric(left->right, right->left) && isSymmetric(left->left, right->right);
}

bool isSymmetric(TreeNode* root) {
	return isSymmetric(root, root);
}

/*
* ������ �ǵݹ�
* ʹ��ջ�Խڵ���д���
* ���Ƚ����ڵ������������ջ����ջ��Ϊ��ʱ�����²�����
* 1.�Ƚ�ջ���������ڵ㱣�棬Ȼ�󵯳�
* 2.�ж��������ڵ��Ƿ�ͬʱΪ�գ�ͬʱΪ���������������Ĵ��������ص�1��������Ԫ��
*   2��Ϊ�յ����һ������ڱ��������зǿսڵ㶼��ջʱ
* 3.����Ԫ��ͬʱ�ǿգ��Ƚ���ֵ�Ƿ���ȣ������򷵻�false��
*   ������������ڵ�1�����ӽڵ� �ڵ�2�����ӽڵ� �ڵ�1�����ӽڵ� �ڵ�2�����ӽڵ�
*  �ظ���������ֱ��ջΪ�գ����ؽ����ע��ջ��Ԫ������ʲôʱ����2�ı�����ÿ�ζ��Ƕ�ĳ�ڵ�����ҽڵ㹲ͬ����
*  �ص������Ҫ�������ڵ�������ӽڵ㽻����ջ
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