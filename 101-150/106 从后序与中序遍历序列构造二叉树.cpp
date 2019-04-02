#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//106 根据一棵树的中序遍历与后序遍历构造二叉树。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* buildTreeCore(int startPostorder, int endPostorder, int startInorder, int endInorder);
//方法一：按照上题的思路改的，sb系统通过不了不知道咋回事
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
	int rootValue = Postorder[endPostorder];//后序的最后一个值就是根节点的值
	TreeNode* root = new TreeNode(rootValue);//创建当前后序子数组对应子树的根节点
											 //递归退出条件
	if (Postorder[startPostorder] == Postorder[endPostorder] && Inorder[startInorder] == Inorder[endInorder])
		return root;
	//在中序遍历中找到根节点值
	int rootInorder = startInorder;
	while (rootInorder <= endInorder&&Inorder[rootInorder] != rootValue)
		rootInorder++;
	//通过中序遍历根节点位置算出左子树大小
	int leftLength = rootInorder - startInorder;
	//设置左子树结束位置（不设置也行，为了代码可读性好一些）
	int leftPostorderEnd = startPostorder + leftLength;
	if (leftLength>0)//此时左子树不为空
		root->left = buildTreeCore(startPostorder, leftPostorderEnd-1, startInorder, rootInorder - 1);
	if (startPostorder + leftLength<endPostorder)//此时右子树不为空
		root->right = buildTreeCore(leftPostorderEnd, endPostorder - 1, rootInorder + 1, endInorder);
	return root;
}

//方法二：参考105题的方法二，采用哈希表,不知道为什么，在线上无法通过，还是想把105、106这两个题的代码写的接近些...逼死强迫症......
TreeNode* buildTreeCore(int start, int end);
vector<int> Postorder;
vector<int> Inorder;
unordered_map<int, int> inorder_table;
int index;//后序遍历数组的下标，从最大下标开始
TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
	if (postorder.size() == 0 || inorder.size() == 0)
		return nullptr;
	Postorder = postorder;
	index = postorder.size() - 1;
	for (int i = 0; i<inorder.size(); i++)
		inorder_table.insert({ inorder[i],i });//这里是让值作key，下标为value，需要注意一下
	return buildTreeCore(0, Postorder.size() - 1);
}
//这个遍历属于先序遍历，也就是说进入下一次便利之前会先创建节点，下一次的遍历是找该结点的左右子节点
TreeNode* buildTreeCore(int start, int end)
{
	//递归退出条件
	if (start>end)
		return nullptr;
	int rootValue = Postorder[index--];//前序第一个值就是根节点的值
									  //生成根结点的顺序时 顺序，由下标index控制
	TreeNode* root = new TreeNode(rootValue);//创建当前前序子数组对应子树的根节点
											 //右子树递归
	root->right = buildTreeCore(inorder_table[rootValue] + 1, end);
											 //左子树递归
	root->left = buildTreeCore(start, inorder_table[rootValue] - 1);
	
	return root;
}

//方法三：无脑查找，从后序遍历数组最后一个数开始遍历，每次在中序遍历数组中找到这个结点位置，然后生成结点，用中序遍历控制递归继续进行
//为什么只有前序和后序两个组合不能重建二叉树？
//因为只有中序的根节点是能分隔左右子树的，而要构成唯一的二叉树，二叉树的左右子树划分要很清晰
//举个反例 前序2 1 后序1 2  根节点是2 1可能是右子树，也可能是左子树，因为前序和中序都没法通过根节点区分左右子树，所以根本不能得知左右子树从哪里分隔
vector<int> Postorder;
vector<int> Inorder;
int index = 0;
TreeNode* buildTreeNode(int start, int end)
{
	if (start>end)
		return NULL;
	//在中序遍历中找到根节点值
	int rootInorder;
	for (int i = 0; i<Inorder.size(); i++)
		if (Postorder[index] == Inorder[i])
			rootInorder = i;
	TreeNode* node = new TreeNode(Inorder[rootInorder]);
	index--;
	//遍历左右子节点
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