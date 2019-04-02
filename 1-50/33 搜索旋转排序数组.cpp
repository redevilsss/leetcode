#include<iostream>
#include<vector>
using namespace std;

// 33 ������ת��������
/*
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��
( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��
����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� -1 ��
����Լ��������в������ظ���Ԫ�ء�
����㷨ʱ�临�Ӷȱ����� O(log n) ����

ʾ�� 1:
����: nums = [4,5,6,7,0,1,2], target = 0
���: 4

ʾ�� 2:
����: nums = [4,5,6,7,0,1,2], target = 3
���: -1
*/


//����㷨���ص������������ת�����Ͻ��ж��ֲ���
//������ת���飬ȡ�м��±�һ��Ϊ����������һ���������������
//����������򲿷�������֣�������Զ��ֲ��һ�ý��
int serachCore(vector<int>& nums, int left, int right, int target)
{
	if (left>right)//δ�ҵ�
		return -1;
	int mid = (left + right) / 2;
	if (target == nums[mid])
		return mid;
	//���м�ֵ������ֵ��˵��ǰһ���������
	if (nums[mid]>nums[right])
	{
		//����м�ֵ����target����ֵС��target��˵������left mid-1֮��
		//��һ�����������
		if (nums[mid] > target&&target >= nums[left])
			return serachCore(nums, left, mid - 1, target);
		else
			//�����������
			return serachCore(nums, mid + 1, right, target);
	}
	else//�м�ֵС����ֵ��˵����һ���������
	{
		//������м�ֵС��target����ֵС�ڵ���target��˵������mid+1��right֮��
		//��һ�����������
		if (nums[mid]<target&&target <= nums[right])
			return serachCore(nums, mid + 1, right, target);
		else//�����������
			return serachCore(nums, left, mid - 1, target);
	}
}

int search(vector<int>& nums, int target)
{
	return serachCore(nums, 0, nums.size() - 1, target);
}

int main()
{
	vector<int> vec = { 3,1 };
	int res = search(vec, 0);
	return 0;
}