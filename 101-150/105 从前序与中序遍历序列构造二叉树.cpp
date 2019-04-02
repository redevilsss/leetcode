#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTreeCore(int startPreorder, int endPreorder, int startInorder, int endInorder);//����

//����1���ݹ����
//ֱ�ӱ�����⣬����⿼�ľ���ǰ������Ķ�Ӧ��ÿ��ȡǰ���������еĵ�һ��Ϊ���ڵ㣬Ȼ���ڶ�Ӧ���������������ҵ���ֵ����Ϊ�ڵ�ֵ���ظ���
//Ȼ��ͻ�������������
//�˳��������ǵ�ǰǰ��������Ŀ�ʼ�ڵ�ͽ����ڵ���ͬ������������Ŀ�ʼ�ڵ�ͽ����ڵ���ͬ����ʵ����������������һ�����ؽ�������ʱ���������ǵȼ۵ģ���һ�������͹��ˣ�
vector<int> Preorder;
vector<int> Inorder;
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0 || inorder.size() == 0)
		return nullptr;
	Preorder = preorder;
	Inorder = inorder;
	return buildTreeCore(0, Preorder.size() - 1, 0, Inorder.size() - 1);
}
TreeNode* buildTreeCore(int startPreorder, int endPreorder, int startInorder, int endInorder)
{
	int rootValue = Preorder[startPreorder];//ǰ���һ��ֵ���Ǹ��ڵ��ֵ
	TreeNode* root = new TreeNode(rootValue);//������ǰǰ���������Ӧ�����ĸ��ڵ�
											 //�ݹ��˳�����
	if (Preorder[startPreorder] == Preorder[endPreorder] && Inorder[startInorder] == Inorder[endInorder])
		return root;
	//������������ҵ����ڵ�ֵ
	int rootInorder = startInorder;
	while (rootInorder <= endInorder&&Inorder[rootInorder] != rootValue)
		rootInorder++;
	//ͨ������������ڵ�λ�������������С
	int leftLength = rootInorder - startInorder;
	//��������������λ�ã�������Ҳ�У�Ϊ�˴���ɶ��Ժ�һЩ��
	int leftPreorderEnd = startPreorder + leftLength;
	if (leftLength>0)//��ʱ��������Ϊ��
		root->left = buildTreeCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	if (startPreorder + leftLength<endPreorder)//��ʱ��������Ϊ��
		root->right = buildTreeCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	return root;
}

//ʹ��unordered_map��ʵ�֣���Ϊ��ϣ���в��ҵĹ��ܣ��Ұ������������װ����ϣ����ô�ؽ�������ֻ��Ҫ����ǰ��������У����ݹ���Ĺ�ϣ�����ҵ����ڵ�����������е�λ��
//����������и��ڵ��λ��
//��ʵ˼·��ǰ��һ����ֻ����������������������ҵ�ǰ�����ĸ��ڵ�λ�á���ԭ�����ֶ����ұ����ʹ�������Ĳ��ҹ���
//��Ϊ�ڵ�ֵ�ǲ��ظ��ģ������ҽ���������Ԫ������һ��hashmap������ȡ����ǰǰ���������еĵ�һ��Ԫ�أ��������ڵ�
//Ȼ����ݵ�ǰ���ڵ��ֵȥ�����ϣ�����Ѷ�Ӧ��ֵ���±꣬����±�Ͷ��ڷ���1�е�rootInorder
vector<int> Preorder;
vector<int> Inorder;
unordered_map<int, int> inorder_table;
int index = 0;//ǰ�����������±꣬��0��ʼ
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0 || inorder.size() == 0)
		return nullptr;
	Preorder = preorder;
	for (int i = 0; i<inorder.size(); i++)
		inorder_table.insert({ inorder[i],i });//��������ֵ��key���±�Ϊvalue����Ҫע��һ��
	return buildTreeCore(0, Preorder.size() - 1);
}
//��������������������Ҳ����˵������һ�α���֮ǰ���ȴ����ڵ㣬��һ�εı������Ҹý��������ӽڵ�
TreeNode* buildTreeCore(int start, int end)
{
	//�ݹ��˳�����
	if (start>end)
		return nullptr;
	int rootValue = Preorder[index++];//ǰ���һ��ֵ���Ǹ��ڵ��ֵ
									  //���ɸ�����˳��ʱ ˳�����±�index����
	TreeNode* root = new TreeNode(rootValue);//������ǰǰ���������Ӧ�����ĸ��ڵ�
											 //�������ݹ�
	root->left = buildTreeCore(start, inorder_table[rootValue] - 1);
	//�������ݹ�
	root->right = buildTreeCore(inorder_table[rootValue] + 1, end);
	return root;
}



int main()
{
	vector<int> a = { 1,2,4,7,3,5,6,8 };
	vector<int> b = { 4,7,2,1,5,3,8,6 };
	TreeNode* root=buildTree(a, b);
	return 0;
}