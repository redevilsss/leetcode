#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//102 �������ľ�ݲ������
/*
����һ����������������ڵ�ֵ�ľ���β�α�����
*/


//Ҫʵ�־�ݲ�α�������Ҫ��ת�����﷭ת��ʵ��1�ǿ����ݽṹջ��2�ǿ�����ʱ������һ������Һ���
//��Ҫ����ջ��ʵ�ִ��룬������Ԫ�ؽ�s1ջ��ż����Ԫ�ؽ�s2ջ
//������ⷭת��ʵ�֣�1 2 3 4 5 6 7
//��һ��Ϊ���ڵ�1��1��s1��1��s1����һ��Ϊ[1] 1���ӽڵ����������s2��2 3
//s2��Ԫ�س�ջ���ڶ���Ϊ[3 2]���ڶ���Ԫ�ص��ӽڵ����Һ�����s1 5 null null 4
//s1��Ԫ�س�ջ��������Ϊ[4 null null 5] ���Ĳ㶼Ϊnull��ѭ������
//ʵ����һ��Ԫ�صĵ��򿿵���ջ�����ʺ��ӽڵ����˳����ջ�����ʽ���ǰ�㷭ת���ɽڵ����˳�򽫸ò�ڵ������������ת

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> res;
	if (root == nullptr)
		return res;
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	s1.push(root);
	int i = 1;
	while (!s1.empty() || !s2.empty())
	{
		vector<int> temp;
		if (i & 1 == 1)
		{
			int count = s1.size();
			while (count--)
			{
				TreeNode* node = s1.top();
				s1.pop();
				temp.push_back(node->val);
				if (node->left != nullptr)
					s2.push(node->left);
				if (node->right != nullptr)
					s2.push(node->right);

			}
		}
		else
		{
			int count = s2.size();
			while (count--)
			{
				TreeNode* node = s2.top();
				s2.pop();
				temp.push_back(node->val);
				if (node->right != nullptr)
					s1.push(node->right);
				if (node->left != nullptr)
					s1.push(node->left);
			}
		}
		res.push_back(temp);
		i++;
	}
	return res;
}

int main()
{
	TreeNode* t1 = new TreeNode(3);
	TreeNode* t2 = new TreeNode(9);
	TreeNode* t3 = new TreeNode(20);
	TreeNode* t4 = new TreeNode(15);
	TreeNode* t5 = new TreeNode(7);
	t1->left = t2;
	t1->right = t3;
	t3->left = t4;
	t3->right = t5;
	vector<vector<int>> res = zigzagLevelOrder(t1);
	return 0;
}