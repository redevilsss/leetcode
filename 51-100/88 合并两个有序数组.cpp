#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//88 合并两个有序数组

/*
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
说明:
初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
输出: [1,2,2,3,5,6]
*/

//我的方法，从头到尾归并，一开始没想好，其实可以直接逆序归并的。。。
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (nums1.size()<n+m||n == 0)
		return;
	int x = max(m, n);//选取m和n中较大的数，对nums1中元素进行移动
	//若数组空间不够大，扩容直到大小等于m+x
	while (nums1.size() < m + x)
		nums1.push_back(0);
	int i = m-1;
	while (i>=0)
	{
		nums1[x + i] = nums1[i];
		nums1[i] = 0;
		i--;
	}
	//nums1[x]和nums2[0]开始做归并排序
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
	//刚刚才补的0拿掉
	for (int i = m + n; i < m + x; i++)
		nums1.pop_back();
}

//方法二，从尾到头归并
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