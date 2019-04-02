#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//173 ����������������
/*
ʵ��һ���������������������㽫ʹ�ö����������ĸ��ڵ��ʼ����������
���� next() �����ض����������е���һ����С������
*/

//ʵ����������������ݽṹ��ջ
/*
��˼�����£�
1.��ʼ����������Ҳ���ǰѵ�ǰ���ڵ������·���洢
2.��ջ�а������ӽڵ㵽���ڵ����ε�������ѹ��ÿ�ε����ڵ�������������·������ʵ������ջʵ���������
3.�Ƿ���nextֻ��Ҫ��ջ�ǲ��ǿ�

��ʵ���Ƿǵݹ�����������ο���93��
*/
class BSTIterator {
public:
	stack<TreeNode*> s;
	BSTIterator(TreeNode* root) {
		while (root)
		{
			s.push(root);
			root = root->left;
		}
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* res = s.top();
		s.pop();
		TreeNode* right = res->right;
		while (right)
		{
			s.push(right);
			right = right->left;
		}
		return res->val;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}

};
