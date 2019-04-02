#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//113 ·���ܺ�2
/*
����һ����������һ��Ŀ��ͣ��ҵ����дӸ��ڵ㵽Ҷ�ӽڵ�·���ܺ͵��ڸ���Ŀ��͵�·����
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//��112����ȶ��˶���·���ڵ�ֵ�Ĵ洢
//pathsΪ���յĽ����pathΪһ��·��
//����ݹ�����ȸ���sumʣ��ֵ������ǰ�ڵ��ֵ������
//�����ǰ�ڵ�ΪҶ�ӽڵ��Ҵ�ʱsumʣ��ֵΪ0���ͽ���ʱ��path��������paths��
//���򣬷ֱ������������

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> paths;
	vector<int> path;
	if (root == nullptr)
		return paths;
	pathSum(root, paths, path, sum);
	return paths;
}
void pathSum(TreeNode* root, vector<vector<int>>& paths, vector<int>& path, int sum)
{
	sum -= root->val;
	path.push_back(root->val);

	if (root->right == nullptr&&root->left == nullptr&&sum == 0)
		paths.push_back(path);
	if (root->left != nullptr)
		pathSum(root->left, paths, path, sum);
	if (root->right != nullptr)
		pathSum(root->right, paths, path, sum);
	path.pop_back();
}