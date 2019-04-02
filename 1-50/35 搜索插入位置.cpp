#include<iostream>
#include<vector>
using namespace std;

// 35 ��������λ��
//������ֲ���
/*
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
����Լ������������ظ�Ԫ�ء�
ʾ�� 1:
����: [1, 3, 5, 6], 5
��� : 2

ʾ�� 2 :
���� : [1, 3, 5, 6], 2
��� : 1

ʾ�� 3 :
���� : [1, 3, 5, 6], 7
��� : 4

ʾ�� 4 :
���� : [1, 3, 5, 6], 0
��� : 0
*/

//����⻹�ǿ�����ֲ��ң���������׸��
int searchInsert(vector<int>& nums, int target) {
	if (nums.size() == 0 || (nums.size() == 1 && nums[0] != target))
		return -1;
	if (nums.size() == 1 && nums[0] < target)
		return 1;
	else if(nums.size() == 1 && nums[0] >= target)
		return 0;
	//ȡ����ָ��ֱ�ָ��ͷ��β
	int begin = 0;
	int end = nums.size() - 1;
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		//����м�ֵΪmid��˵�����ҵ���ֱ�ӷ���mid
		if (target == nums[mid])
			return mid;
		//���Ŀ��ֵ�����м�ֵ�����������
		else if (target>nums[mid])
		{
			if (mid == nums.size() - 1)
				return nums.size();
			//��Ŀ������м�ֵС���м�ֵ����һ��ֵʱ�������в�����Ŀ��ֵ
			//��Ŀ��ֵ�Ž������±���mid+1
			else if ( nums[mid + 1] > target)
				return mid+1;
			else//�����������
				begin = mid + 1;
				
		}
		else
		{
			if (mid == 0)
				return mid;
			//��Ŀ��С���м�ֵ�����м�ֵ����һ��ֵʱ�������в�����Ŀ��ֵ
			//��Ŀ��ֵ�Ž������±���mid
			if (nums[mid - 1]<target)
				return mid;
			else
				end = mid - 1;
		}
	}
	return begin;
}

int main()
{
	vector<int> vec = { 1,3 };
	int res = searchInsert(vec,2);
	return 0;
}