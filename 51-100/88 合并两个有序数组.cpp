#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//88 �ϲ�������������

/*
�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣
˵��:
��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
ʾ��:
����:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
���: [1,2,2,3,5,6]
*/

//�ҵķ�������ͷ��β�鲢��һ��ʼû��ã���ʵ����ֱ������鲢�ġ�����
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (nums1.size()<n+m||n == 0)
		return;
	int x = max(m, n);//ѡȡm��n�нϴ��������nums1��Ԫ�ؽ����ƶ�
	//������ռ䲻��������ֱ����С����m+x
	while (nums1.size() < m + x)
		nums1.push_back(0);
	int i = m-1;
	while (i>=0)
	{
		nums1[x + i] = nums1[i];
		nums1[i] = 0;
		i--;
	}
	//nums1[x]��nums2[0]��ʼ���鲢����
	int index = 0;
	int index1 = x;
	int index2 = 0;
	while (index1 < x + m&&index2 < n)
	{
		if (nums1[index1] <= nums2[index2])
			nums1[index++] = nums1[index1++];
		else
			nums1[index++] = nums2[index2++];
	}
	while (index1 == x + m&&index2 < n)
		nums1[index++] = nums2[index2++];
	while(index2==n&&index1<x+m)
		nums1[index++] = nums1[index1++];
	//�ողŲ���0�õ�
	for (int i = m + n; i < m + x; i++)
		nums1.pop_back();
}

//����������β��ͷ�鲢
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (nums1.size()<n + m || n == 0)
		return;
	int index = m + n - 1;
	int index1 = m-1;
	int index2 = n-1;
	while (index1 >= 0 && index2 >= 0)
	{
		if (nums1[index1] <= nums2[index2])
			nums1[index--] = nums2[index2--];
		else
			nums1[index--] = nums1[index1--];
	}
	while (index1 == -1 && index2 >= 0)
		nums1[index--] = nums2[index2--];
	while (index2 == -1 && index1 >= 0)
		nums1[index--] = nums1[index1--];
}












int main()
{
	vector<int> nums1 = { 0,0,1,2,3,0,0,0};
	vector<int> nums2 = { 2,5,6 };
	merge(nums1, 5, nums2, 3);
	return 0;
}