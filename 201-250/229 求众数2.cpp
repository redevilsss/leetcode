#include<iostream>
#include<vector>
using namespace std;

//���ֳ���n/3��Ԫ�����������������������num1��num2����ʾ
/*
������֮ǰ�󳬹�һ���Ԫ�أ��õ�������ʵ�֣�ֻ��������������������������¼ֵcount1��count2
*/
vector<int> majorityElement(vector<int>& nums) {
	vector<int> res;
	//��������ͱ������ֵĴ������õ���������
	int count1 = 0;
	int count2 = 0;
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		//��ǰֵ����num1��count1�ӣ�����count�������count1Ϊ0������num1
		//num2ͬ��
		if (count1 != 0 && nums[i] == num1)
			count1++;
		else if (count2 != 0 && nums[i] == num2)
			count2++;
		else if (count1 == 0)
		{
			num1 = nums[i];
			count1 = 1;
		}
		else if (count2 == 0)
		{
			num2 = nums[i];
			count2 = 1;
		}
		else
		{
			count1--;
			count2--;
		}
	}
	//ͳ��num1��num2���ֵĴ���
	count1 = 0;
	count2 = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		if (nums[i] == num1)
			count1++;
		else if (nums[i] == num2)
			count2++;
	}
	//�������1/3��������
	if (count1>nums.size() / 3)
		res.push_back(num1);
	if (count2>nums.size() / 3)
		res.push_back(num2);
	return res;
}