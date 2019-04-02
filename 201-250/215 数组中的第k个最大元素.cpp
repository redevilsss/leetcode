#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//���ƽ�ָoffer��40��
/*
�����������򣬶���ÿ���ÿ��ţ���Ϊ������һ���ص����ÿ�ο��԰�һ�����ֳɴ�����ŦԪ��С����ŦԪ��
��ʱ����ŦԪ��λ�ã��������k�����ٸ�ǰһ����ţ������ȣ�����͸���һ����ż�����
�����ǰ��ŦԪ��λ��������k-1���ͷ������ֵ
�������ܱ�����������������
*/
//���������е�����Ԫ��
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//partition�������Ե�ǰ����������򣬲����زο�Ԫ�ص��±�
int partition(vector<int>& nums, int left, int right)
{
	//ѡȡ�ο�Ԫ�ز���rightλ�ý���
	int index = (left + right) / 2;
	swap(&nums[index], &nums[right]);

	int flag = left - 1;
	for (index = left; index<right; index++)
	{
		//�����ǰ�ڵ�ֵ���ڲο�ֵ
		if (nums[index]>nums[right])
		{
			++flag;
			//�����ʱ֤��index֮ǰ��flag�����бȲο�ֵС������Ҫ�������������
			//��֤����ڲο�ֵǰ���Ǵ��ڲο�ֵ����
			if (flag != index)
				swap(&nums[index], &nums[flag]);
		}
	}
	//����һ��flag����ʱflagָ�����С�ڲο�ֵ�������Ѳο�ֵ������
	++flag;
	swap(&nums[flag], &nums[right]);
	return flag;
}

int findKthLargest(vector<int>& nums, int k) {
	if (nums.size()<k)
		return -1;
	int left = 0;
	int right = nums.size() - 1;
	//ȡ��һ���ο�Ԫ�ص��±�
	int index = partition(nums, left, right);
	//���±겻Ϊk-1��˵����û�ҵ���������
	while (index != k - 1)
	{
		//index>k-1,������k���Ԫ����index֮ǰ
		if (index>k - 1 && left<right)
		{
			right = index - 1;
			index = partition(nums, left, right);
		}
		//������k���Ԫ����index֮��
		else if (left<right)
		{
			left = index + 1;
			index = partition(nums, left, right);
		}
		else
			break;
	}
	return nums[index];
}

int main()
{
	vector<int> vec = { 3,2,1,5,6,4 };
	int res = findKthLargest(vec, 2);
	return 0;
}