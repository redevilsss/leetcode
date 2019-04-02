#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
//297 �����������л��뷴���л�

/*
���л��ǽ�һ�����ݽṹ���߶���ת��Ϊ�����ı���λ�Ĳ������������Խ�ת��������ݴ洢��һ���ļ������ڴ��У�
ͬʱҲ����ͨ�����紫�䵽��һ���������������ȡ�෴��ʽ�ع��õ�ԭ���ݡ�
�����һ���㷨��ʵ�ֶ����������л��뷴���л���
���ﲻ�޶�������� / �����л��㷨ִ���߼�����ֻ��Ҫ��֤һ�����������Ա����л�Ϊһ���ַ������ҽ�����ַ��������л�Ϊԭʼ�����ṹ��
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//�ֱ����õݹ鷽���ͷǵݹ鷽��ʵ��
//����һ���ݹ鷽�����޷�ͨ�����а���
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
		//�ָ����У����ڵ�ֵ������strs������
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

//�����������������queue��ʵ��
class Codec1 {
public:
	//����������ڵ�Ϊ�վ�׷��null������׷��root����ֵ
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
	//������ȫ��������˵�����������ڵ������¹��ɣ�
	//�ڵ�i�������ӽڵ��±�ֱ�Ϊ2i+1��2i+2
	//�������ﲢ����һ����ȫ������������ֻҪ֪����ǰnull�ڵ�ĸ���num
	//ͬ�����Ը����±����ָ�������
	//�ڵ�i�������ӽڵ��±�ֱ�Ϊ2��i-num)+1��2(i-num)+2
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
		//�ָ����У����ڵ�ֵ������strs������
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
			//���µ�ǰ�ڵ�֮ǰ�Ŀսڵ����
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