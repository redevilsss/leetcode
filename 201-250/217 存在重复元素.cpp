#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//217 �����ظ�Ԫ��
/*
����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
����κ�ֵ�������г����������Σ��������� true�����������ÿ��Ԫ�ض�����ͬ���򷵻� false��
ʾ�� 1:
����: [1,2,3,1]
���: true
*/

//�����û�¿��ģ�һ��ʼ�һ���Ϊ��λ����֮��ķ��������û��
//sort��������õ�...ֱ�ӵ����ˡ�����
bool containsDuplicate(vector<int>& nums) {
	if (nums.size()<2)
		return false;
	sort(nums.begin(), nums.end());
	for (int i = 1; i<nums.size(); i++)
	{
		if (nums[i] == nums[i - 1])
			return true;
	}
	return false;

}