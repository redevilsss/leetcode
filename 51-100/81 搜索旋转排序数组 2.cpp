#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//82 ������ת��������2
/*
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��
�� ���磬���� [0,0,1,2,2,5,6] ���ܱ�Ϊ [2,5,6,0,0,1,2] )��
��дһ���������жϸ�����Ŀ��ֵ�Ƿ�����������С������ڷ��� true�����򷵻� false��
ʾ��:
����: nums = [2,5,6,0,0,1,2], target = 0
���: true
*/

//����һ�������ָoffer�еĵ�11�⣬�Գ��������������±�ֵ��ͬ������������⴦�������33�Ᵽ��һ��
int serachCore(vector<int>& nums, int left, int right, int target)
{
	if (left>right)
		return false;
	int mid = (left + right) / 2;
	if (target == nums[mid])
		return true;

	if (nums[mid] == nums[left] && nums[mid] == nums[right])
	{
		for (int i = left; i < right; i++);
		{
			if (nums[i] == target)
				return true;
		}
		return false;
	}
	if (nums[mid]>nums[right])
	{
		if (nums[mid] > target&&target >= nums[left])
			return serachCore(nums, left, mid - 1, target);
		else
			return serachCore(nums, mid + 1, right, target);
	}
	else
	{
		if (nums[mid]<target&&target <= nums[right])
			return serachCore(nums, mid + 1, right, target);
		else
			return serachCore(nums, left, mid - 1, target);
	}
}

bool search(vector<int>& nums, int target)
{
	return serachCore(nums, 0, nums.size() - 1, target);
}


//����2�����ñ���ֱ��ѭ������˼·һ��
bool search(vector<int>& nums, int target) {
	int l = 0, r = nums.size() - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] == target || nums[l] == target || nums[r] == target) //˵����ʱ�����д���Ŀ��ֵ
			return true;
		if (nums[mid] == nums[r]) //���м�ֵ������ֵʱ���޷��жϵ�ǰ�ĸ��ִ����򣬽����±�����ֱ���м�ֵ������ֵ
			while (nums[mid] == nums[r]) 
				--r;
		else if (nums[mid] > nums[r]) //mid���ڵ�һ�����������ϣ�l��mid����
		{
			if (nums[r] > target || nums[mid] < target) //nums[r] > target˵��target��mid��r֮�䣬nums[mid] < target˵��target��mid�������֮�䣬����߽������mid+1
				l = mid + 1;
			else 
				r = mid - 1;//����ȥ��һ����
		}
		else //mid���ڵڶ������������� nums[mid] < nums[r],mid��r����
		{
			if (nums[mid] > target || nums[r] < target) //nums[mid] > target˵��������target������С����mid֮�䣬nums[r] < target˵��������target����l��mid-1֮��
				r = mid - 1;
			else 
				l = mid + 1;//����ȥ��һ����
		}
	}
	return false;
}
int main()
{
	vector<int> vec = { 2,5,6,0,0,1,2 };
	bool res = search(vec, 3);
}
