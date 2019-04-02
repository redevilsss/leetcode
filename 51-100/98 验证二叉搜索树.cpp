#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//98 ��֤����������

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//�����������˼�룬��������������������ϸ���������ÿ�α����걣�浱ǰ��������ֵ�������һ��ֵ�������ֵ���������ֵ��������
//����ֹͣ��������false

//���ñ�������ֵ
long last = LONG_MIN;//���ǵ����ڵ������INT_MIN����ʼ��last��������long���͵���Сֵ
bool isValidBST(TreeNode* root) {
	if (root == nullptr)
		return true;
	if (isValidBST(root->left))//���ýڵ��������Ϊ�������������жϸýڵ㣬���ýڵ�ֵ���ڵ�ǰ����ֵ������±���ֵ������������������������ֱ�ӷ���false
	{
		if (last<root->val)
		{
			last = root->val;
			return isValidBST(root->right);
		}
	}
	return false;
}
