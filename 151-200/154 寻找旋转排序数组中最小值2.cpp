#include<iostream>
#include<vector>
using namespace std;


//154 Ѱ����ת���������е���Сֵ2

/*
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��
( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��
���ҳ�������С��Ԫ�ء�
ע�������п��ܴ����ظ���Ԫ�ء�
*/
//�ο���һ�⣬��ͬ�ĵط����������������ܻ�����ظ�Ԫ��
//�ظ�Ԫ�س���ʱ�����д�С�ж�������Ҫ���ϵȺţ���Ϊ���п��ܻ�����е�ֵ�������˵�ֵ�����
//����һ���������Ǿ��ǻ�����е�ֵ�����Ҷ˵�ֵȫ��һ���ļ������������������޷��ж�Ҫ��ô�ߣ�ֱ�ӱ�������������Сֵ
int findMin(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	int start = 0;
	int end = nums.size() - 1;
	int mid = start;
	while (nums[start] >= nums[end])
	{
		//��end��start���ڵ�ʱ��endָ��ľ�����Сֵ
		//��ʱstartָ���һ����������һ�����֣�endָ��ڶ�������ĵ�һ�����֣�Ҳ������������
		if (end - start == 1)
		{
			mid = end;
			break;
		}
		//�������е�
		mid = (start + end) / 2;

		//��ʱֱ�ӱ���
		if (nums[mid] == nums[start] && nums[mid] == nums[end])
		{
			int res = nums[start];
			for (int i = start + 1; i < end; i++)
			{
				if (res > nums[i])
					res = nums[i];
			}
			return res;
		}
		//����е�ֵ������˵㣬˵��mid�ڵ�һ�������У�Ҫ�����Сֵ��mid�ұ�
		if (nums[mid]>=nums[start])
			start = mid;
		//����е�ֵС����˵���С���Ҷ˵㣬˵��mid�ڵڶ��������У�Ҫ�����Сֵ��mid���
		else if (nums[mid]<=nums[end])
			end = mid;
	}
	return nums[mid];
}