#include<iostream>
#include<vector>
using namespace std;


// 26 ɾ�����������е��ظ���

/*
����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�

ʾ�� 1:
�������� nums = [1,1,2],
����Ӧ�÷����µĳ��� 2, ����ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2��
�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

ʾ�� 2:
���� nums = [0,0,1,1,1,2,2,3,3,4],
����Ӧ�÷����µĳ��� 5, ����ԭ���� nums ��ǰ���Ԫ�ر��޸�Ϊ 0, 1, 2, 3, 4��
�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
*/
//�Ƚϼ򵥵�һ����
int removeDuplicates(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	int newLength = 0;
	nums[newLength++] = nums[0];
	for (int index = 1; index<nums.size(); index++)
	{
		while (index<nums.size() && nums[index] == nums[index - 1])
			index++;
		if (index<nums.size())
			nums[newLength++] = nums[index];
	}
	return newLength;
}
