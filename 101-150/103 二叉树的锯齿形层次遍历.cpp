#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//102 二叉树的锯齿层序遍历
/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。
*/


//要实现锯齿层次遍历，就要翻转，这里翻转的实现1是靠数据结构栈，2是靠遍历时先左后右还是先右后左
//需要两个栈来实现代码，奇数层元素进s1栈，偶数层元素进s2栈
//举例理解翻转的实现：1 2 3 4 5 6 7
//第一层为根节点1，1入s1，1出s1，第一层为[1] 1的子节点先左后右入s2，2 3
//s2中元素出栈，第二层为[3 2]，第二层元素的子节点先右后左入s1 5 null null 4
//s1中元素出栈，第三层为[4 null null 5] 第四层都为null，循环结束
//实现下一层元素的倒序靠的是栈的性质和子节点遍历顺序，由栈的性质将当前层翻转，由节点遍历顺序将该层节点的左右子树翻转

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