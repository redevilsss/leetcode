#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;

//4 Ѱ�����������������λ��
/*
����������СΪ m �� n ���������� nums1 �� nums2��
�����ҳ������������������λ��������Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(log(m + n))��
����Լ��� nums1 �� nums2 ����ͬʱΪ�ա�
ʾ�� 1:
nums1 = [1, 3]
nums2 = [2]
����λ���� 2.0

ʾ�� 2:
nums1 = [1, 2]
nums2 = [3, 4]
����λ���� (2 + 3)/2 = 2.5

*/


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	//��¼������ĳ���
	int len1 = nums1.size();
	int len2 = nums2.size();
	int len = len1 + len2;
	//�����������������������Ϊ�������飬����һ�ι鲢�����������
	int *nums = new int[len];
	int i = 0, j = 0;
	for (int k = 0; k < len; ++k) {
		//������2������ߵ�����1δ����������1Ŀǰ��ֵС������2Ŀǰ��ֵʱ����������1��Ԫ��
		if (j == len2 || (i < len1 && nums1[i] < nums2[j])) {
			nums[k] = nums1[i++];
		}
		else {
			nums[k] = nums2[j++];
		}
	}
	//���ݳ���Ϊ���ż��ȡ��λ��
	if (len % 2 != 0)
		return nums[len / 2];
	else
		return (nums[len / 2 - 1] + nums[len / 2]) / 2.0;

}