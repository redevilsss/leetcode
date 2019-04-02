#include<iostream>
#include<stack>
using namespace std;
//230 ������������kС��Ԫ��
/*
����һ����������������дһ������ kthSmallest ���������е� k ����С��Ԫ�ء�
˵����
����Լ��� k ������Ч�ģ�1 �� k �� ����������Ԫ�ظ�����
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//���Եݹ���Ҳ������ջ��ʵ���������

//�ݹ鷽��1
//getNum�������ڼ��㵱ǰ�ڵ���ӽڵ����
int getNum(TreeNode* node)
{
	if (node == nullptr)
		return 0;
	int left = getNum(node->left);
	int right = getNum(node->right);
	return 1 + left + right;
}

int kthSmallest(TreeNode* root, int k) {
	//�����ǰ�ڵ�����ӽڵ��kС��˵����kС��Ԫ������������
	if (getNum(root->left)<k-1)
		return kthSmallest(root->right, k - getNum(root->left)-1);
	//�����ǰ�ڵ�����ӽڵ��k��˵����kС��Ԫ������������
	else if (getNum(root->left)>k-1)
		return kthSmallest(root->left, k );
	//���򣬵�ǰ�ڵ���ǵ�kС��Ԫ��
	else
		return root->val;
}

//�ݹ鷽��2

//�ǵݹ鷽�� ������� �����ң����϶������������ص�
int kthSmallest(TreeNode* root, int k) {
	stack<TreeNode*> s;
	int res;
	while ((root != nullptr || !s.empty()) && k)
	{
		if (root != nullptr)
		{
			s.push(root);
			root = root->left;
		}
		else
		{
			root = s.top();
			s.pop();
			--k;
			res = root->val;
			root = root->right;
		}
	}
	return res;
}


int main()
{
	TreeNode* t1 = new TreeNode(3);
	TreeNode* t2 = new TreeNode(1);
	TreeNode* t3 = new TreeNode(4);
	TreeNode* t4 = new TreeNode(2);
	t1->left = t2;
	t1->right = t3;
	t2->right = t3;
	int res = kthSmallest(t1,1);
	return 0;
}
