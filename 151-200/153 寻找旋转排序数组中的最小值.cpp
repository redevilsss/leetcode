#include<iostream>
#include<vector>
using namespace std;


//153 Ѱ����ת���������е���Сֵ

/*
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��
( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��
���ҳ�������С��Ԫ�ء�
����Լ��������в������ظ�Ԫ�ء�
*/

//�����͵�33�����˼����һ���ģ��ǽ�ָoffer�ĵ�11�⣬˼�붼�Ƕ��ֲ���
/*
�������ٵ���˼�붼�Ƕ��ֲ���
��ת����������ص㣺��ʵ��������������ǰһ��������������ֶ����ں�һ����������������飬Ҫ�ҵ���С��ֵ���ǵڶ���������׸�Ԫ��
��ָoffer�е�˼·��
˫ָ��start��end���ֱ�ָ���һ�������ͷ�͵ڶ��������β������������start����ֵС��end����ֵ
��Ϊ��ʱ��ָ���Ѿ���һ���������ˣ�Ҫ�ҵĵڶ�������ĵ�һ������
*/


int findMin(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	int start = 0;
	int end = nums.size() - 1;
	int mid = start;
 	while (nums[start] > nums[end])
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
		//����е�ֵ������˵㣬˵��mid�ڵ�һ�������У�Ҫ�����Сֵ��mid�ұ�
		if (nums[mid]>nums[start])
			start = mid ;
		//����е�ֵС����˵���С���Ҷ˵㣬˵��mid�ڵڶ��������У�Ҫ�����Сֵ��mid���
		else if (nums[mid]<nums[end])
			end = mid;
	}
	return nums[mid];
}

int main()
{
	vector<int> vec = { 3,4,5,1,2, };
	int res = findMin(vec);
	return 0;
}