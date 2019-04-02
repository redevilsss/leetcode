#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//106 ����һ��������������������������������

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* buildTreeCore(int startPostorder, int endPostorder, int startInorder, int endInorder);
//����һ�����������˼·�ĵģ�sbϵͳͨ�����˲�֪��զ����
vector<int> Postorder;
vector<int> Inorder;
TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
	if (postorder.size() == 0 || inorder.size() == 0)
		return nullptr;
	Postorder = postorder;
	Inorder = inorder;
	return buildTreeCore(0, Postorder.size() - 1, 0, Inorder.size() - 1);
}
TreeNode* buildTreeCore(int startPostorder, int endPostorder, int startInorder, int endInorder)
{
	int rootValue = Postorder[endPostorder];//��������һ��ֵ���Ǹ��ڵ��ֵ
	TreeNode* root = new TreeNode(rootValue);//������ǰ�����������Ӧ�����ĸ��ڵ�
											 //�ݹ��˳�����
	if (Postorder[startPostorder] == Postorder[endPostorder] && Inorder[startInorder] == Inorder[endInorder])
		return root;
	//������������ҵ����ڵ�ֵ
	int rootInorder = startInorder;
	while (rootInorder <= endInorder&&Inorder[rootInorder] != rootValue)
		rootInorder++;
	//ͨ������������ڵ�λ�������������С
	int leftLength = rootInorder - startInorder;
	//��������������λ�ã�������Ҳ�У�Ϊ�˴���ɶ��Ժ�һЩ��
	int leftPostorderEnd = startPostorder + leftLength;
	if (leftLength>0)//��ʱ��������Ϊ��
		root->left = buildTreeCore(startPostorder, leftPostorderEnd-1, startInorder, rootInorder - 1);
	if (startPostorder + leftLength<endPostorder)//��ʱ��������Ϊ��
		root->right = buildTreeCore(leftPostorderEnd, endPostorder - 1, rootInorder + 1, endInorder);
	return root;
}

//���������ο�105��ķ����������ù�ϣ��,��֪��Ϊʲô���������޷�ͨ�����������105��106��������Ĵ���д�Ľӽ�Щ...����ǿ��֢......
TreeNode* buildTreeCore(int start, int end);
vector<int> Postorder;
vector<int> Inorder;
unordered_map<int, int> inorder_table;
int index;//�������������±꣬������±꿪ʼ
TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
	if (postorder.size() == 0 || inorder.size() == 0)
		return nullptr;
	Postorder = postorder;
	index = postorder.size() - 1;
	for (int i = 0; i<inorder.size(); i++)
		inorder_table.insert({ inorder[i],i });//��������ֵ��key���±�Ϊvalue����Ҫע��һ��
	return buildTreeCore(0, Postorder.size() - 1);
}
//��������������������Ҳ����˵������һ�α���֮ǰ���ȴ����ڵ㣬��һ�εı������Ҹý��������ӽڵ�
TreeNode* buildTreeCore(int start, int end)
{
	//�ݹ��˳�����
	if (start>end)
		return nullptr;
	int rootValue = Postorder[index--];//ǰ���һ��ֵ���Ǹ��ڵ��ֵ
									  //���ɸ�����˳��ʱ ˳�����±�index����
	TreeNode* root = new TreeNode(rootValue);//������ǰǰ���������Ӧ�����ĸ��ڵ�
											 //�������ݹ�
	root->right = buildTreeCore(inorder_table[rootValue] + 1, end);
											 //�������ݹ�
	root->left = buildTreeCore(start, inorder_table[rootValue] - 1);
	
	return root;
}

//�����������Բ��ң��Ӻ�������������һ������ʼ������ÿ������������������ҵ�������λ�ã�Ȼ�����ɽ�㣬������������Ƶݹ��������
//Ϊʲôֻ��ǰ��ͺ���������ϲ����ؽ���������
//��Ϊֻ������ĸ��ڵ����ָܷ����������ģ���Ҫ����Ψһ�Ķ���������������������������Ҫ������
//�ٸ����� ǰ��2 1 ����1 2  ���ڵ���2 1��������������Ҳ����������������Ϊǰ�������û��ͨ�����ڵ������������������Ը������ܵ�֪��������������ָ�
vector<int> Postorder;
vector<int> Inorder;
int index = 0;
TreeNode* buildTreeNode(int start, int end)
{
	if (start>end)
		return NULL;
	//������������ҵ����ڵ�ֵ
	int rootInorder;
	for (int i = 0; i<Inorder.size(); i++)
		if (Postorder[index] == Inorder[i])
			rootInorder = i;
	TreeNode* node = new TreeNode(Inorder[rootInorder]);
	index--;
	//���������ӽڵ�
	node->right = buildTreeNode(rootInorder + 1, end);
	node->left = buildTreeNode(start, rootInorder - 1);
	return node;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	if (inorder.size() == 0)
		return NULL;
	Postorder = postorder;
	Inorder = inorder;
	index = postorder.size() - 1;
	return buildTreeNode(0, inorder.size() - 1);
}
int main()
{
	vector<int> a = { 9,15,7,20,3 };
	vector<int> b = { 9,3,15,20,7 };
	TreeNode* root = buildTree(a, b);
	return 0;
}