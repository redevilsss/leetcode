#include<iostream>
#include<vector>
using namespace std;
//303 ����ͼ���

/*
����һ����������  nums�������������� i �� j  (i �� j) ��Χ��Ԫ�ص��ܺͣ����� i,  j ���㡣
ʾ����
���� nums = [-2, 0, 3, -5, 2, -1]����ͺ���Ϊ sumRange()
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
˵��:
����Լ������鲻�ɱ䡣
���ε��� sumRange ������
*/




class NumArray {
	vector<int> sums;
public:
	//�ص����ڶ�ε��ã������������һ���ȳ��������洢���ֺͣ���������͵�ʱ��ֻ��Ҫ�������
	NumArray(vector<int> nums) {
		if (nums.size() == 0)
			return;
		sums.resize(nums.size());
		sums[0] = nums[0];
		for (int i = 1; i<nums.size(); i++)
			sums[i] += sums[i - 1] + nums[i];
	}

	int sumRange(int i, int j) {
		if (i == 0)
			return sums[j];
		else
			return sums[j] - sums[i - 1];
	}
};