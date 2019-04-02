#include<iostream>
using namespace std;
//235 �����������������������
/*
����һ������������, �ҵ�����������ָ���ڵ������������ȡ�
�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x��
���� x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����
���磬�������¶���������:  root = [6,2,8,0,4,7,9,null,null,3,5]
ʾ�� 1:
����: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
���: 6
����: �ڵ� 2 �ͽڵ� 8 ��������������� 6��
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//�ݹ�ⷨ
/*
������ö������������ص㣬���root��ֵ��pֵ��qֵ�м䣬˵����ǰroot�ڵ���������������
�������root��ֵ��qֵ��pֵ����˵��p��q����root����������
���root��ֵ��qֵ��pֵ��С��˵��p��q����root����������
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == nullptr || root == p || root == q)
		return root;
	if (root->val>p->val&&root->val>q->val)
		return lowestCommonAncestor(root->left, p, q);
	else if (root->val<p->val&&root->val<q->val)
		return lowestCommonAncestor(root->right, p, q);
	return root;
}
//�ǵݹ�ⷨ
/*
˼·���ƣ�
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	int max = p->val>q->val ? p->val : q->val;
	int min = p->val + q->val - max;
	TreeNode* temp = root;
	//�����ǰ�����ڵ���temp��ͬ�࣬����ѭ��
	while (temp != nullptr && (temp->val>max || temp->val<min))
	{
		//��������ڵ��ֵ����tempС��tempȡ�����ӽڵ�
		if (temp->val>min)
			temp = temp->left;
		//��������ڵ��ֵ����temp��tempȡ�����ӽڵ�
		else if (temp->val<min)
			temp = temp->right;
	}
	return temp;
}