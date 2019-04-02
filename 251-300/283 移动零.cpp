#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//283 �ƶ���
/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
ʾ��:
����: [0,1,0,3,12]
���: [1,3,12,0,0]
*/


//����һ��˫ָ�룬�ҵ�0�ͷŵ�����ĩβ
void moveZeroes(vector<int>& nums) {
	int len = nums.size();
	int start = 0;
	int end = len - 1;
	while (start <= end)
	{
		while (start <= end&&nums[end] == 0)
			end--;
		while (start <= end && nums[start] != 0)
			start++;
		if (start>end)
			break;
		for (int i = start; i<end; i++)
			nums[i] = nums[i + 1];
		nums[end] = 0;
	}
}

//��������һ�ָ���ķ���������һ����ָ�룬������������з���Ԫ������������飬���ĩβȫ������
void moveZeroes(vector<int>& nums) {
	int index = 0;
	for (int i = 0; i<nums.size(); i++)
		if (nums[i] != 0)
			nums[index++] = nums[i];
	for (int i = index; i<nums.size(); i++)
		nums[i] = 0;
}

int main()
{
	vector<int> vec = { 0,1,0,3,12 };
	moveZeroes(vec);
	return 0;
}