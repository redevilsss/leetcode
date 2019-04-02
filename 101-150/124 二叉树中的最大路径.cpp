#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

/*
������ǿ��Ŵ��е�˼·���ģ�����ͨ����30%����ͷ��𣬵���ʵҲ����
���������������Ҷ�ӽڵ㵽���ڵ����ͳ�ƣ������������Ҫ����
1.�Ե�ǰ�ڵ�Ϊ�������Թ��ɵ����Ϳ�����4�֣�
 (1)�ڵ�ֵ�����������ͣ����������·����С��0��
 (2)�ڵ�ֵ�����������ͣ����������·����С��0��
 (3)�ڵ�ֵ�������������·���Ͷ�С��0��
 (4)�ڵ�ֵ��������������
 ����������ж��������������ǲ��Ǵ���0�����С��0���������㣬
 ��Ϊĳ�����������·����С��0ʱ���Ե�ǰ�ڵ�Ϊ���ڵ������������·���������������
2.�Ե�ǰ�ڵ�Ϊ���·���͵��м�ĳһ��ʱ���Ǹ��ڵ㣩��ֻ��ѡȡ����һ�������(Ҫ��ϵ�ǰ�ĸ��ڵ㹹��·��)
 ����������������ֱ�Ϊ1���ᵽ��(1)(2)(3)
 �Ե�ǰ�ڵ�Ϊ���ڵ�õ������·���Ϳ���ֱ�������������·����maxValue
 �Ե�ǰ�ڵ�Ϊ�Ǹ��ڵ�õ������·������Ҫreturn����һ�������ظ�getMax(node->left)��getMax(node->right)
 ��������꼴�ɵõ����·����
*/
int maxValue =INT_MIN;//��¼��ǰ����

int getMax(TreeNode* node)
{
	if (node == nullptr)
		return 0;
	//��ǰ�ڵ��������������·����
	int left = max(0, getMax(node->left));
	int right = max(0, getMax(node->right));
	//�Ե�ǰ�ڵ�Ϊ���ڵ�����·����node->val + left + right������maxValue
	maxValue = max(maxValue, node->val + left + right);
	//�Ե�ǰ�ڵ�Ϊ�Ǹ��ڵ�����·���ͣ���Ҫreturn����һ��
	return max(left, right) + node->val;
}

int maxPathSum(TreeNode* root) {
	getMax(root);
	return maxValue;
}
int main()
{
	TreeNode* n1 = new TreeNode(-1);
	TreeNode* n2 = new TreeNode(-2);
	TreeNode* n3 = new TreeNode(-3);
	n1->left = n2;
	n1->right = n3;
	int res = maxPathSum(n1);
	return 0;
}