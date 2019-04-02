#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/*
109 ����һ�����������е�Ԫ�ذ��������򣬽���ת��Ϊ�߶�ƽ��Ķ�����������
�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1��
ʾ����
�������������� [-10, -3, 0, 5, 9],
һ�����ܵĴ��ǣ�[0, -3, 9, -10, null, 5], �����Ա�ʾ��������߶�ƽ�������������
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

//�����Ҫ�����������Ҫ�������ȡ�����е㣬��108������������תBST����������
//������˼·�ɹ�ѡ��һ�Ǳ���һ�α����ܳ��ȣ����ǲ��ó��̲����ķ������ж������Ƿ��л����õ������

//����һ�������ܳ��ȣ��ڵݹ���Ҳ��������Ҫ�߶��ٲ����е�
TreeNode* sortedListToBST(ListNode* head) {
	if (head == nullptr)
		return nullptr;
	int length = 1;
	ListNode* node = head;
	//�����ܳ���
	while (node != nullptr)
	{
		node = node->next;
		length++;
	}
	return sortedListToBST(head, 0, length - 1);
}
//���������ֱ��ʾ��ǰ������ͷ��㣬������ͷ�ڵ�����һ���ǿսڵ������������е��±�
TreeNode* sortedListToBST(ListNode* node,int start,int end)
{
	if (start > end)
		return nullptr;
	if (start == end)//��ʱ������ֻ��һ���ڵ㣬�������Ľڵ㲢����
		return new TreeNode(node->val);
	//���������м�ڵ�
	int mid = (end + start) / 2;
	int i = mid;
	ListNode* step = node;
	//fastһ����������slowһ����һ����fast�ߵ�����endС�ڵ���һ��ʱ��slow��λ�þ���start��end�����м�
	while (i--)
		step = step->next;
	TreeNode* root = new TreeNode(step->val);
	//���������ɵ����ڵ����������
	root->left = sortedListToBST(node,start,mid-1);
	root->right = sortedListToBST(step->next,mid+1, end);
	return root;
}



























/*
//�����������̲������е�
TreeNode* sortedListToBST(ListNode* head) {
	return sortedListToBST(head, nullptr);//�����nullptr�൱����������һ��Ԫ��
}
TreeNode* sortedListToBST(ListNode* start, ListNode* end)
{
	if (start == nullptr || start == end)
		return nullptr;
	ListNode* slow = start;
	ListNode* fast = start;
	//fastһ����������slowһ����һ����fast�ߵ�����endС�ڵ���һ��ʱ��slow��λ�þ���start��end�����м�
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
