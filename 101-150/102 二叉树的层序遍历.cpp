#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//102 �������Ĳ������
/*
����һ���������������䰴��α����Ľڵ�ֵ��
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//˼·�ܼ򵥣�����ͨ������ʵ��
//���ȷ�����ڵ㣬Ȼ�󵱶��в�Ϊ��ʱѭ�����м����������
//count���ڼ�¼��ǰ��Ľڵ����������temp����洢�ò�Ԫ��
//����ÿһ���ڵ㣬����ڵ㣬��¼�ڵ�ֵ�������У�Ȼ�󽫸ýڵ�������ӽڵ������
//ÿ��ڵ������ɺ󣬽�����temp���з���res����
vector<vector<int>> res;
vector<vector<int>> levelOrder(TreeNode* root) {
	if (root == nullptr)
		return res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int count = q.size();
		vector<int> temp;
		while (count--)
		{
			TreeNode* node = q.front();
			q.pop();
			temp.push_back(node->val);
			if (node->left != nullptr)
				q.push(node->left);
			if (node->right != nullptr)
				q.push(node->right);
		}
		res.push_back(temp);
	}
	return res;

}