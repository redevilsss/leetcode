#include<iostream>
#include<vector>
using namespace std;

//238 ��������������ĳ˻�

/*
��������Ϊ n ���������� nums������ n > 1������������� output ������ output[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻���
ʾ��:
����: [1,2,3,4]
���: [24,12,8,6]
*/

/*
�����������output
��Ȼ�����ó������Ϳ��Ǳ���ǰ׺��
Ҳ����˵�����ȱ������飬��ǰ�ڵ����Ԫ�صĳ˻���ͨ������ÿ�γ��µ�Ԫ�ؽ�������ʵ��
��ɺ��ٶ������t��ʾ��ǰ�Ҳ�Ԫ�صĳ˻�
����������飬ÿ�θ���t������t*ԭoutput[i]������output����õ����ս��
*/
vector<int> productExceptSelf(vector<int>& nums) {
	int len = nums.size();
	vector<int> output(len, 1);
	for (int i = 1; i<len; i++)
		output[i] = output[i - 1] * nums[i - 1];
	int t = 1;
	for (int i = len - 2; i >= 0; i--)
	{
		t = t*nums[i + 1];
		output[i] = output[i] * t;
	}
	return output;
}