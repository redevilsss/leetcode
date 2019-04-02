#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//152 �˻����������
/*
����һ���������� nums ���ҳ�һ�������г˻��������������У����������ٰ���һ��������
ʾ�� 1:
����: [2,3,-2,4]
���: 6
����: ������ [2,3] �����˻� 6��
*/


/*
�������Ҫ��������������͸��������ڣ��ڼ������ֵ�Ĺ����У���Ҫ����������imax��ҲҪ������С����imin
�������ֵΪmax����ÿһ��Ҫ���жϵ�ǰ�����Сֵ���ٸ���max
��Ϊ�����ǰ���Ǹ�������ô֮ǰ��С�����ͻ���һ���о������������������ڴ�ʱ����imax��imin
����һ�㣬��ο��ƿ�ʼ�˵ĵط���-��Ҫÿһ�ζ�imax*nums[i]��nums[i]���бȽϣ����С��nums[i]����ôimax�ͻ���nums[i]
��ʼ�˵�λ�ø���Ϊ��i��ʼ��ͬ��iminҲ�����
�����������max������������������
�������ص����ڵ�ǰ���ֵ����Сֵ��Ҫ����
*/
int maxProduct(vector<int>& nums) {
	int Max = INT_MIN;
	int imax = 1;//��ǰλ��Ϊֹ�����ֵ
	int imin = 1;//��ǰλ��Ϊֹ����Сֵ
	for (int i = 0; i<nums.size(); i++)
	{
		//��ʱnums[i]Ϊ��������ô��һ�����ܳ��ֵĽϴ�ֵӦ����imin*nums[i]�����Խ���imin��imax
		if (nums[i]<0)
		{
			int temp = imax;
			imax = imin;
			imin = temp;
		}
		//�Ƚ�imax*nums[i]�� nums[i]�����µ�ǰ���ֵ
		imax = max(imax*nums[i], nums[i]);
		//�Ƚ�imin*nums[i]�� nums[i]�����µ�ǰ��Сֵ
		imin = min(imin*nums[i], nums[i]);
		//����Max
		Max = max(Max, imax);

	}
	return Max;
}