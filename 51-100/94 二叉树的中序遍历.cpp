#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//94 ��������ǰ����� �ݹ�͵���


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//�ݹ鷽�������Լ�
vector<int> res;
vector<int> inorderTraversal(TreeNode* root) {
	if (root == nullptr)
		return res;
	inorderTraversalCore(root);
	return res;
}
void inorderTraversalCore(TreeNode* root)
{
	if (root->left)
		inorderTraversalCore(root->left);
	res.push_back(root->val);
	if (root->right)
		inorderTraversalCore(root->right);

}


//�ǵݹ�ʵ��
//��ջ��ʵ�֣���Ϊǰ������ĵ�һ���ڵ�������Ҷ�ӽڵ㣬�������ʱ��Ҫ��·���ϵĽڵ㶼���������������ȡ�ڵ����ӽڵ��ֵ
//�ͷǵݹ�����������ƣ�Ψһ�����ǿ��鵽��ǰ�ڵ�ʱ������ֱ������ýڵ�
//���ǵ�����ڵ�Ϊ��ʱ����ջ�е�����ʱ���ٽ������(��Զ�ȿ�����������ֱ��������Ϊ�ղŷ��ʸ��ڵ�)��
vector<int> res;
vector<int> inorderTraversal(TreeNode* root) {
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
			// �ɿ���˳���֪����Ҫһֱ������
			// Ϊ��֮�����ҵ��ýڵ�����������ݴ�ýڵ�
			treeNodeStack.push(pNode);
			pNode = pNode->left;
		}
		if (!treeNodeStack.empty())
		{
			// һֱ��������Ϊ�գ���ʼ����������
			// ���ջ�ѿգ��Ͳ���Ҫ�ٿ���
			// ����ջ��Ԫ�أ���ջ��Ԫ��ֵ�������飬���α���ڸýڵ��������
			pNode = treeNodeStack.top();
			treeNodeStack.pop();
			res.push_back(pNode->val);
			pNode = pNode->right;
		}
	}
	return res;
}
