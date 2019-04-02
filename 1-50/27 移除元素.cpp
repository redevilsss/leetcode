#include<iostream>
#include<vector>
using namespace std;

//27 �Ƴ�Ԫ��
/*
����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

ʾ�� 1:
���� nums = [3,2,2,3], val = 3,
����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2��
�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

ʾ�� 2:
���� nums = [0,1,2,2,3,0,4,2], val = 2,
����Ӧ�÷����µĳ��� 5, ���� nums �е�ǰ���Ԫ��Ϊ 0, 1, 3, 0, 4��
*/
//����һ�����ƣ��������飬�������ֵ������val�ͽ������·���
int removeElement(vector<int>& nums, int val) {
	if (nums.size() == 0)
		return 0;
	int newLength = 0;
	for (int index = 0; index<nums.size(); index++)
	{
		if (nums[index] != val)
			nums[newLength++] = nums[index];
	}
	return newLength;

}