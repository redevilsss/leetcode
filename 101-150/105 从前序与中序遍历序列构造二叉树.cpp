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
TreeNode* buildTreeCore(int startPreorder, int endPreorder, int startInorder, int endInorder);//声明

//方法1：递归求解
//直接遍历求解，这道题考的就是前序中序的对应，每次取前序子数组中的第一个为根节点，然后在对应的中序子数组中找到该值（因为节点值不重复）
//然后就会变成两个子问题
//退出条件就是当前前序子数组的开始节点和结束节点相同且中序子树组的开始节点和结束节点相同（其实当给出的两个数组一定能重建二叉树时，这两个是等价的，有一个条件就够了）
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
	int rootValue = Preorder[startPreorder];//前序第一个值就是根节点的值
	TreeNode* root = new TreeNode(rootValue);//创建当前前序子数组对应子树的根节点
											 //递归退出条件
	if (Preorder[startPreorder] == Preorder[endPreorder] && Inorder[startInorder] == Inorder[endInorder])
		return root;
	//在中序遍历中找到根节点值
	int rootInorder = startInorder;
	while (rootInorder <= endInorder&&Inorder[rootInorder] != rootValue)
		rootInorder++;
	//通过中序遍历根节点位置算出左子树大小
	int leftLength = rootInorder - startInorder;
	//设置左子树结束位置（不设置也行，为了代码可读性好一些）
	int leftPreorderEnd = startPreorder + leftLength;
	if (leftLength>0)//此时左子树不为空
		root->left = buildTreeCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	if (startPreorder + leftLength<endPreorder)//此时右子树不为空
		root->right = buildTreeCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	return root;
}

//使用unordered_map来实现，因为哈希表有查找的功能，我把中序遍历序列装进哈希表，那么重建二叉树只需要操作前序数组就行，根据构造的哈希表能找到根节点在中序遍历中的位置
//而中序遍历中根节点的位置
//其实思路和前面一样，只不过“在中序遍历数组中找当前子树的根节点位置”由原来的手动查找变成了使用容器的查找功能
//因为节点值是不重复的，所以我将中序数组元素置入一个hashmap，我先取出当前前序子数组中的第一个元素，创建根节点
//然后根据当前根节点的值去这个哈希表里搜对应数值的下标，这个下标就对于方法1中的rootInorder
vector<int> Preorder;
vector<int> Inorder;
unordered_map<int, int> inorder_table;
int index = 0;//前序遍历数组的下标，从0开始
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0 || inorder.size() == 0)
		return nullptr;
	Preorder = preorder;
	for (int i = 0; i<inorder.size(); i++)
		inorder_table.insert({ inorder[i],i });//这里是让值作key，下标为value，需要注意一下
	return buildTreeCore(0, Preorder.size() - 1);
}
//这个遍历属于先序遍历，也就是说进入下一次便利之前会先创建节点，下一次的遍历是找该结点的左右子节点
TreeNode* buildTreeCore(int start, int end)
{
	//递归退出条件
	if (start>end)
		return nullptr;
	int rootValue = Preorder[index++];//前序第一个值就是根节点的值
									  //生成根结点的顺序时 顺序，由下标index控制
	TreeNode* root = new TreeNode(rootValue);//创建当前前序子数组对应子树的根节点
											 //左子树递归
	root->left = buildTreeCore(start, inorder_table[rootValue] - 1);
	//右子树递归
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