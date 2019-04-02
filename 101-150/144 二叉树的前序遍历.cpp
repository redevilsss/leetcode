#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//144 ��������ǰ����� �ݹ�͵���


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//�ݹ�ʵ��
vector<int> res;
vector<int> preorderTraversal(TreeNode* root) {
	if (root == nullptr)
		return res;
	bfs(root);
	return res;
}
void bfs(TreeNode* root)
{
	if (root == nullptr)
		return;
	res.push_back(root->val);
	bfs(root->left);
	bfs(root->right);
}

//�ǵݹ�ʵ��
//��ջ��ʵ�֣���Ϊǰ������ĵ�һ���ڵ�������Ҷ�ӽڵ㣬�������ʱ��Ҫ��·���ϵĽڵ㶼���������������ȡ�ڵ����ӽڵ��ֵ
vector<int> res;
vector<int> preorderTraversal(TreeNode* root) {
	// �����ݴ�ڵ��ջ
	stack<TreeNode* > treeNodeStack;
	// �½�һ���α�ڵ�Ϊ���ڵ�
	TreeNode* pNode = root;
	// �����������һ���ڵ��ʱ��������������������Ϊ�գ�����ջҲΪ��
	// ���ԣ�ֻҪ��ͬʱ���������㣬����Ҫ����ѭ��
	while (pNode != nullptr || !treeNodeStack.empty())
	{
		while (pNode != nullptr)
		{
			// ����ǰ����ڵ�ǿգ�������ýڵ��ֵ
			// �ɿ���˳���֪����Ҫһֱ������
			res.push_back(pNode->val);
			// Ϊ��֮�����ҵ��ýڵ�����������ݴ�ýڵ�
			treeNodeStack.push(pNode);
			pNode = pNode->left;
		}
		if (!treeNodeStack.empty())
		{
			// һֱ��������Ϊ�գ���ʼ����������
			// ���ջ�ѿգ��Ͳ���Ҫ�ٿ���
			// ����ջ��Ԫ�أ����α���ڸýڵ��������
			pNode = treeNodeStack.top();
			treeNodeStack.pop();
			pNode = pNode->right;
		}
	}
	return res;
}