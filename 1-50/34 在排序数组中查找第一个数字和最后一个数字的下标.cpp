#include<iostream>
#include<vector>
using namespace std;

//34 �����������в���Ԫ�صĵ�һ�������һ��λ��
//������ֲ���

/*
����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
����㷨ʱ�临�Ӷȱ����� O(log n) ����
��������в�����Ŀ��ֵ������ [-1, -1]��
ʾ�� 1:
����: nums = [5,7,7,8,8,10], target = 8
���: [3,4]

ʾ�� 2:
����: nums = [5,7,7,8,8,10], target = 6
���: [-1,-1]
*/

//������Ҫ���ǿ�����ֲ��ң��������Ӻ���ʵ�ֶ����������߽��Ѱ��
//���ҵ�ֵΪtarget�ĵ����ж����Ƿ�������/�ҵ�һ��
int getLeftBoundIndex(vector<int>& nums, int left, int right, int target)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
		{
			//midΪ0����mid���ֵ��Ϊtarget��˵��mid��������߽�
			if (mid == 0||nums[mid - 1] != target)
				return mid;
			right = mid - 1;
		}

		else if (nums[mid]>target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

int getRightBoundIndex(vector<int>& nums, int left, int right, int target)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
		{
			//midΪ���һ���mid�ұ�ֵ��Ϊtarget��˵��mid�������ұ߽�
			if (mid == nums.size() - 1||nums[mid + 1] != target)
				return mid;
			left = mid + 1;
		}

		else if (nums[mid]>target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}


vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> res(2);
	//�ȴ����������
	if (nums.size() == 0 || (nums.size() == 1 && nums[0] != target))
		return { -1,-1 };
	if (nums.size() == 1 && nums[0] == target)
		return { 0,0 };
	res[0] = getLeftBoundIndex(nums, 0, nums.size() - 1, target);
	res[1] = getRightBoundIndex(nums, 0, nums.size() - 1, target);
	return res;
}



int main()
{
	vector<int> vec = { 2,2};
	vector<int> res = searchRange(vec, 2);
	return 0;
}