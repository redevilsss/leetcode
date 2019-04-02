#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
//297 二叉树的序列化与反序列化

/*
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，
同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
请设计一个算法来实现二叉树的序列化与反序列化。
这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//分别考虑用递归方法和非递归方法实现
//方法一：递归方法，无法通过所有案例
class Codec {
public:

	// Encodes a tree to a single string.
	void serialize(TreeNode* root, string& s)
	{
		if (root == nullptr)
			s += "# ";
		else
		{
			s += to_string(root->val) + " ";
			serialize(root->left, s);
			serialize(root->right, s);
		}
		
	}

	string serialize(TreeNode* root) {
		string s = "";
		serialize(root, s);
		s.pop_back();
		return s;
	}

	// Decodes your encoded data to tree.
	void deserialize(vector<string> strs, TreeNode* &root, int& n)
	{
		if (n == strs.size())
			return;
		if (strs[n] == "#")
		{
			root = nullptr;
			return;
		}
		int val = stoi(strs[n]);
		root = new TreeNode(val);
		n++;
		deserialize(strs, root->left, n);
		n++;
		deserialize(strs, root->right, n);
	}
	TreeNode* deserialize(string data) {
		if (data == "#" || data == "")
			return nullptr;
		//分割序列，将节点值保存在strs数组中
		vector<string> strs;
		string s = "";
		for (char d : data)
		{
			if (d == ' ')
			{
				strs.push_back(s);
				s = "";
			}
			else
				s.push_back(d);
		}
		strs.push_back(s);

		TreeNode* root = nullptr;
		int n = 0;
		deserialize(strs, root, n);
		return root;
	}
};

//方法二，层序遍历用queue来实现
class Codec1 {
public:
	//层序遍历，节点为空就追加null，否则追加root的数值
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string s = "";
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* node = q.front();
			q.pop();
			if (node == nullptr)
				s += "null,";
			else
			{
				s += to_string(node->val) + ",";
				q.push(node->left);
				q.push(node->right);
			}
		}
		return s;
	}
	//对于完全二叉树来说，其层序遍历节点有如下规律：
	//节点i的左右子节点下标分别为2i+1和2i+2
	//但是这里并不是一个完全二叉树，但是只要知道当前null节点的个数num
	//同样可以根据下标来恢复二叉树
	//节点i的左右子节点下标分别为2（i-num)+1和2(i-num)+2
	// Decodes your encoded data to tree.
	void deserialize(vector<string> strs, TreeNode* &root, int& n)
	{
		if (n == strs.size())
			return;
		if (strs[n] == "#")
		{
			root = nullptr;
			return;
		}
		int val = stoi(strs[n]);
		root = new TreeNode(val);
		n++;
		deserialize(strs, root->left, n);
		n++;
		deserialize(strs, root->right, n);
	}
	TreeNode* deserialize(string data) {
		if (data == "#" || data == "")
			return nullptr;
		//分割序列，将节点值保存在strs数组中
		vector<string> strs;
		string s = "";
		for (char d : data)
		{
			if (d == ',')
			{
				strs.push_back(s);
				s = "";
			}
			else
				s.push_back(d);
		}
		vector<int> nums(strs.size());
		vector<TreeNode*> nodes;
		for (int i = 0; i < strs.size(); i++)
		{
			//更新当前节点之前的空节点个数
			if (i > 0)
				nums[i] = nums[i - 1];
			if (strs[i] == "null")
			{
				nodes.push_back(nullptr);
				nums[i]++;
			}
			else
				nodes.push_back(new TreeNode(stoi(strs[i])));
		}

		for (int i = 0; i < strs.size(); i++) {
			if (nodes[i] == nullptr) {
				continue;
			}
			nodes[i]->left = nodes[2 * (i - nums[i]) + 1];
			nodes[i]->right = nodes[2 * (i - nums[i]) + 2];
		}
		return nodes[0];
	}
};

int main()
{
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	t1->left = t2;
	t1->right = t3;
	t3->left = t4;
	t3->right = t5;
	Codec1 c;
	string s=c.serialize(t1);
	TreeNode* t = c.deserialize(s);
	return 0;
}