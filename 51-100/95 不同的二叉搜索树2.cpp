#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//95 ��ͬ�Ķ���������2

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//start��end�ֱ��ʾ��ȡ�ڵ�ֵ��С��������
vector<TreeNode*> generateTrees(int start, int end)
{
	vector<TreeNode*> res;
	if (start>end)//��start>endʱ����Ϊ��
	{
		res.push_back(nullptr);
		return res;
	}
	//�ֱ���start~endΪ���ڵ�
	//ÿ�α���������������������ø��ڵ�ȥ������������
	for (int i = start; i <= end; i++)
	{
		vector<TreeNode*> subLeftTree = generateTrees(start, i - 1);
		vector<TreeNode*> subRightTree = generateTrees(i + 1, end);
		for (TreeNode* left : subLeftTree)
		{
			for (TreeNode* right : subRightTree)
			{
				//����ڵ㣬��ʹ�ýڵ�ֱ�����������������Ȼ�󽫸ýڵ���������
				//���յĽ���ǲ������
				TreeNode* node = new TreeNode(i);
				node->left = left;
				node->right = right;
				res.push_back(node);
			}
		}
	}
	return res;
}

vector<TreeNode*> generateTrees(int n) {
	vector<TreeNode*> res;
	if (n == 0)
		return res;
	return generateTrees(1, n);
}

int main()
{
	vector<TreeNode*> res = generateTrees(3);
	return 0;
}