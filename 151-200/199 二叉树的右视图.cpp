#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ���������õݹ�Ҳ�����÷ǵݹ�
//�ǵݹ鷽ʽʹ�����ݽṹqueue���ݹ鷽ʽ������ǰ�����

/*
����һ���������
������֮ǰ�İ����ӡ������Ԫ�أ�ֻ����Ҫ��ÿһ������һ��Ԫ��ֵ����res��
���Ԫ�ؾ��ǵ�ǰ����ұ߿�����Ԫ��
*/
vector<int> rightSideView(TreeNode* root) {
	if (root == nullptr)
		return {};
	vector<int> res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		//��ǰ��ڵ����
		int size = q.size();
		//���ڼ���
		int count = 0;
		while (count<size)
		{
			TreeNode* node = q.front();
			q.pop();
			//������ӡΨһ�Ĳ�ͬ������ÿһ������һ��Ԫ����res����
			if (count == size - 1)
				res.push_back(node->val);
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
			count++;
		}

	}
	return res;
}

/*
��������ǰ�����
��ǰ�������ʵ�֣���������res��ʾ����ͼ������˳��Ϊ��������ΪҪ���������ͼ
��res��Ԫ����С�ڵ�ǰ�ڵ����ʱ���Ž��ڵ�ֵ����res
���仰���ǣ�ֻ�б�������һ�����Ϊi+1�Ľڵ�ʱ�����ڵ����res�У�resԪ�ظ���Ҳ��i���i+1
���ԣ�ֻҪ�����±�����ʱ�������Һ��󣬾��ܱ�֤ÿ�μ���res��Ԫ��ֵ�ǵ�ǰ�����ҽڵ��Ԫ��ֵ
*/
vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	if (root == nullptr)
		return res;
	dfs(root, res, 1);
	return res;
}
void dfs(TreeNode* node, vector<int>& res, int depth)
{
	if (depth>res.size())
		res.push_back(node->val);
	if (node->right)
		dfs(node->right, res, depth + 1);
	if (node->left)
		dfs(node->left, res, depth + 1);
}

int main()
{
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	t1->left = t2;
	t1->right = t3;
	t2->right = t5;
	t3->right = t4;
	vector<int> res=rightSideView(t1);
	return 0;
}