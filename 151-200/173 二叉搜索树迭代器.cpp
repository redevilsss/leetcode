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

//173 二叉搜索树迭代器
/*
实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
调用 next() 将返回二叉搜索树中的下一个最小的数。
*/

//实现这个迭代器的数据结构是栈
/*
其思想如下：
1.初始化迭代器，也就是把当前根节点的最左路径存储
2.从栈中把最左子节点到根节点依次弹出，再压入每次弹出节点右子树的最左路径，其实就是用栈实现中序遍历
3.是否有next只需要看栈是不是空

其实就是非递归中序遍历，参考第93题
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
