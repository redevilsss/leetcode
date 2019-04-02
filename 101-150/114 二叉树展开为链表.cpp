#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/*
114 ����һ����������ԭ�ؽ���չ��Ϊ����
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//1 �������
//˼·���������Ҷ�ӽڵ㿪ʼ���������ֵܽڵ㣬��ȡ�����ֵܽڵ��λ�ã���Ϊ�丸�ڵ��µ����ӽڵ�
//�����ڵ�����ӽڵ��ÿգ�Ȼ��ԭ�������ӽڵ�����������ӽڵ�����ӽڵ㣬���չ��
//չ����ĳһ��ʱ�Ĳ��裺
//���ȿ���node�ڵ���û�����ӽڵ㣬û�оͼ�������丸�ڵ�����ӽڵ㣬�����ӽڵ㲻Ϊ��
//1 ���Ҹýڵ����ӽڵ�������ӽڵ�
//2 ���������ӽڵ�����ӽڵ㣨ԭΪ�գ���Ϊnode�ڵ�����ӽڵ�
//  Ҳ����˵��һ����node�����ӽڵ��������ӽڵ�����
//3 ����һ�����Ӻ��node���������node�ڵ�����ӽڵ�
//4 node���ӽڵ����
//�ݹ�汾��
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
//2 ǰ�����,˼·�����
TreeNode* last = new TreeNode(0);
void flatten(TreeNode* root) {
	if (root == nullptr)
		return;
	//��root��Ϊ��һ���ڵ���ҽڵ�
	last->right = root;
	//��һ���ڵ����ڵ�Ϊ��
	last->left = nullptr;
	//last����Ϊroot
	last = last->right;
	//����root�ڵ��������,��Ϊ��һ�εݹ�ʱ�Ὣroot��right���µ�������Ҫ����������
	TreeNode* temp = root->right;
	//������ڵ�
	flatten(root->left);
	//�����ҽڵ㣬�����ᵽ�ˣ�����Ҫ��temp������root->right����Ϊ���ű���������root->right�Ǳ仯��
	//������Ϊÿһ�α��������޸�last��rightֵ
	flatten(temp);
}

//3 �ǵݹ鷽�����ͷ���1���ƣ�
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