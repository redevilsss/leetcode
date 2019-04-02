#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/*
109 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例：
给定的有序链表： [-10, -3, 0, 5, 9],
一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//这道题要解决的问题主要在于如何取链表中点，第108题是有序数组转BST，和这道差不多
//有两种思路可供选择，一是遍历一次保存总长度，二是采用长短步长的方法（判断链表是否有环会用到这个）

//方法一：先求总长度，在递归中也是先求需要走多少步到中点
TreeNode* sortedListToBST(ListNode* head) {
	if (head == nullptr)
		return nullptr;
	int length = 1;
	ListNode* node = head;
	//计算总长度
	while (node != nullptr)
	{
		node = node->next;
		length++;
	}
	return sortedListToBST(head, 0, length - 1);
}
//三个参数分别表示当前子链表头结点，子链表头节点和最后一个非空节点在整个链表中的下标
TreeNode* sortedListToBST(ListNode* node,int start,int end)
{
	if (start > end)
		return nullptr;
	if (start == end)//此时子链表只有一个节点，创建树的节点并返回
		return new TreeNode(node->val);
	//找子链表中间节点
	int mid = (end + start) / 2;
	int i = mid;
	ListNode* step = node;
	//fast一次走两步，slow一次走一步，fast走到距离end小于等于一步时，slow的位置就是start到end的正中间
	while (i--)
		step = step->next;
	TreeNode* root = new TreeNode(step->val);
	//遍历找生成的树节点的左右子树
	root->left = sortedListToBST(node,start,mid-1);
	root->right = sortedListToBST(step->next,mid+1, end);
	return root;
}



























/*
//方法二：长短步长求中点
TreeNode* sortedListToBST(ListNode* head) {
	return sortedListToBST(head, nullptr);//这里的nullptr相当于数组的最后一个元素
}
TreeNode* sortedListToBST(ListNode* start, ListNode* end)
{
	if (start == nullptr || start == end)
		return nullptr;
	ListNode* slow = start;
	ListNode* fast = start;
	//fast一次走两步，slow一次走一步，fast走到距离end小于等于一步时，slow的位置就是start到end的正中间
	while (fast != end&&fast->next != end)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	TreeNode* root = new TreeNode(slow->val);
	root->left = sortedListToBST(start, slow);
	root->right = sortedListToBST(slow->next, end);
	return root;
}
*/
