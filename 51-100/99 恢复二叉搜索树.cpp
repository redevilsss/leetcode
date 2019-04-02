#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//99 �ָ�����������
/*
�����������е������ڵ㱻����ؽ�����
���ڲ��ı���ṹ������£��ָ��������
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* mistakeNode1;
TreeNode* mistakeNode2;
TreeNode* pre = nullptr;
//������¼�����ڵ��ǰһ���ڵ�
//����������������Ϊ�������У����ֽ������м�Ϊ������Ҫ������������ڵ�
//�������ν���ʱ�򽻻���һ�ν���valֵ�ϴ�Ĵ���ڵ�͵ڶ��ν���valֵ��С�Ĵ���ڵ�
//����һ�ν������������ڸ��ڵ���ĳ���ӽڵ㽻��ʱ
//���� 4 2 7 1 3 5 nullptr����ʱ2��3λ�ô��󣬽��佻��
//�������ν���ʱ���������Ľڵ�û��ֱ�ӵĸ��ӹ�ϵ
//���� 4 5 7 1 2 3 nullptr����ʱ�������Ϊ1 5 2 4 3 7 ���Կ�����5 2��4 3������������
//��ʱ������һ�ν���ֵ�ϴ�Ľڵ� Ҳ����5 �͵ڶ��ν���ֵ��С�Ľڵ� Ҳ����3
void dfsTree(TreeNode* root) {
	if (root == nullptr)
		return;
	if (root->left != nullptr)//������������
		dfsTree(root->left);
	if (pre != nullptr&&pre->val>root->val)//preΪ���������ǰroot��ǰһ���ڵ㣬����ֵ���ڵ�ǰ�ڵ�ֵ˵�����ִ�λ
	{
		//��һ�η��ֽ��򣬷ֱ��¼��ǰ��pre�ڵ��root�ڵ�
		if (mistakeNode1 == nullptr)
		{
			mistakeNode1 = pre;
			mistakeNode2 = root;
		}
		//�ڶ��η��ֽ���ʱ�����´���ڵ�2Ϊ��ǰ�ڵ�
		else
			mistakeNode2 = root;
	}
	pre = root;
	if (root->right != nullptr)//������������
		dfsTree(root->right);
}

void recoverTree(TreeNode* root)
{
	dfsTree(root);//���������������ҵ���������ڵ�
	//�����ڵ�ֵ
	int temp = mistakeNode1->val;
	mistakeNode1->val = mistakeNode2->val;
	mistakeNode2->val = temp;
}