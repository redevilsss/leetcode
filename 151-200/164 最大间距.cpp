#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//164 �����
/*
����һ����������飬�ҳ�����������֮������Ԫ��֮�����Ĳ�ֵ��
�������Ԫ�ظ���С�� 2���򷵻� 0��
ʾ�� 1:
����: [3,6,9,1]
���: 3
����: ������������ [1,3,6,9], ��������Ԫ�� (3,6) �� (6,9) ֮�䶼��������ֵ 3��*/






/*�����÷�Ͱ����һ��������СֵΪlow�����ֵΪhigh�����������low��high֮����ȷֲ����õ�������ֵ����С�ģ�
��������[1,3,5,7,9]����ֵΪ2��������[1,3,4,5,9]������ֵ��4����Ȼ����������Сֵ�����ֵ�Լ�Ԫ����Ŀ����ͬ��
���Ƿ�Ͱ��Ͱ������Ϊ(high-low)/n������nΪԪ�ص����飬������ֵһ�����ڵ���Ͱ��������
Ͱ�ĸ���Ϊ(high-low)/Ͱ������+1,Ҳ����n+1��Ȼ���ҳ�ÿ��Ͱ�����ֵ����Сֵ����ô����ֵһ����Ͱ֮��������
Ϊʲô˵���ֵһ�������ڷǿ�Ͱ֮�䣿
���ڵ��������ǰ����˵������Ԫ�ؾ��ȷֲ�����������ֵ��һ���������������ڵķǿյ�Ͱ֮�䣬
��Ϊ����һ��Ͱ���ڲ���ֵ���ΪͰ��������ֻҪ���ݲ�����ȫ���ȷֲ�������ֵ��һ������Ͱ���������Ǿ�һ�������ڵķǿ�Ͱ֮��
��*/
int maximumGap(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	//�ֱ�������Ԫ�ص����ֵ����Сֵ
	int low = INT_MAX;
	int high = INT_MIN;
	int len = nums.size();
	for (int i = 0; i<len; i++)
	{
		low = min(low, nums[i]);
		high = max(high, nums[i]);
	}
	//ÿ��Ͱ�е�Ԫ�ظ�����Ͱ����
	if (low == high)
		return 0;
	//���ֵ ��Сֵ���ж��Ƿ���ֵ�����飬���Ⱦ�Ϊlen+1��(high-low)/((high - low)/len)+1
	vector<bool> hasNum(len + 1, 0);
	vector<int> mins(len + 1, 0);
	vector<int> maxs(len + 1, 0);
	int index = 0;

	for (int i = 0; i<len; i++)
	{
		//�жϵ�ǰ�������ĸ�Ͱ�У�(nums[i] - low)/ ((high - low)/len),����(high - low)/len�ͱ�ʾͰ�������õ�ǰֵ����Сֵ��ֵ����Ͱ���������ǵ�ǰֵ������Ͱ�е�λ��;
		index = (int)((long)nums[i] - low)*(long)len / (high - low);
		//����Ͱ�ڱ�������ֵ����Сֵ
		if (mins[index])
		{
			mins[index] = min(mins[index], nums[i]);
			maxs[index] = max(maxs[index], nums[i]);
		}
		else
		{
			mins[index] = nums[i];
			maxs[index] = nums[i];
			hasNum[index] = true;
		}

	}
	int res = 0;
	int lastMax = maxs[0];
	int i = 1;
	for (; i <= len; i++)
	{
		if (hasNum[i])
		{
			res = max(res, mins[i] - lastMax);
			lastMax = maxs[i];
		}
	}
	return res;
}