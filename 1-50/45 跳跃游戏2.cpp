#include<iostream>
#include<vector>
using namespace std;

// 45 ��Ծ��Ϸ2

/*
����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�
�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�

ʾ��:
����: [2,3,1,1,4]
���: 2
����: �������һ��λ�õ���С��Ծ���� 2��
���±�Ϊ 0 �����±�Ϊ 1 ��λ�ã��� 1 ����Ȼ���� 3 ��������������һ��λ�á�
*/


//����ĺ������ڡ������ǰհ����ÿ�β���Ҫ������һ���Ľ������Ҫ���ǵ�����һ��
//ѡȡʹ������һ��������Զ�ĵ�
int jump(vector<int>& nums) {
	int steps = 0;
	int nextIndex = 0;
	int curIndex = 0;
	//˼�룺��¼�Ӹ�λ�����������ܵ������Զ���룬Ȼ����curIndex����λ�õ�ʹ�����������λ�ã�
	//���Ӳ������ٴ����ڵ�curIndex��¼��������Զ�ܵ����ѭ��
	//ֱ�����ִ�ĳcurIndex�����һ���ߵ��յ㣬�ټӲ�����ѭ���˳���
	while (curIndex<nums.size() - 1)
	{
		int far = 0;//��¼��ǰ�����ߵ���Զλ��
		for (int i = curIndex + 1; i <= curIndex + nums[curIndex] && i<nums.size(); i++)
		{
			if (i == nums.size() - 1)
			{
				nextIndex = i;
				break;
			}
			int temp = i + nums[i];//����һ���ߵ�i��������һ������������Զλ��
			if (temp>far)
			{
				nextIndex = i;
				far = temp;
			}
		}
		//���µ�ǰ�±�
		curIndex = nextIndex;
		steps++;//��������
	}
	return steps;
}