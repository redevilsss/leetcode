#include<iostream>
#include<vector>
using namespace std;

//31 ��һ������

/*
ʵ�ֻ�ȡ��һ�����еĺ������㷨��Ҫ���������������������г��ֵ�������һ����������С�
�����������һ����������У��������������г���С�����У����������У���
����ԭ���޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣

������һЩ���ӣ�����λ������У�����Ӧ���λ���Ҳ��С�
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1
*/

//���������һ���Ѷȣ���Ҫ�Ƕ��ڸ�������
//ժȡ�����������˼·����ʵ���Ǵ����鵹�Ų��ң��ҵ�nums[i] ��nums[i+1]С��ʱ��
//�ͽ�nums[i]��nums[i+1]��nums[nums.length - 1]�����ҵ�һ����С�ı�nums[i]���Ԫ�ؽ�����
//�������ٰ�nums[i+1]��nums[nums.length-1]���򣬾�ok��
void nextPermutation(vector<int>& nums)
{
	if (nums.size() <= 1)
		return;
	if (nums.size() == 2)
	{
		int temp = nums[0];
		nums[0] = nums[1];
		nums[1] = temp;
		return;
	}
	//��flag��ʾ�Ƿ�����˽���
	int flag = 0;
	for (int i = nums.size() - 1; i>0; i--)
	{
		//�ҵ�һ�������λ��
		if (nums[i]>nums[i - 1])
		{
			//����������һ�����򣬽�����ֱ���˳�
			if (i == nums.size() - 1)
			{
				int temp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = temp;
				flag = 1;
				break;
			}
			
			//����С�ı�nums[i-1]�����
			int min_index =i+1;
			int flag2 = 0;//�ܲ����ҵ��ı��
			for (int j = i+1; j<nums.size(); j++)
			{
				if (nums[j] > nums[i - 1] && nums[min_index] >= nums[j])
				{
					min_index = j;
					flag2 = 1;
				}	
			}
			if (flag2 == 0)//�Ҳ�����˵��nums[i-1]���������±곬��i1����
				//��ʱֱ��������������nums[i-1]��nums[i]
			{
				int temp = nums[i];
				nums[i] = nums[i-1];
				nums[i-1] = temp;
				reverse(nums.begin() + i, nums.end());
				flag = 1;
				break;
			}
			//���򣬽���nums[i - 1]���ҵ�����С�Ĵ���nums[i-1]����
			else
			{
				int temp = nums[i - 1];
				nums[i - 1] = nums[min_index];
				nums[min_index] = temp;
				reverse(nums.begin() + i, nums.end());
				flag = 1;
				break;
			}
			
		}
	}
	//���ȫ������ֱ�ӷ�ת
	if (flag == 0)
		reverse(nums.begin(), nums.end());
}

int main()
{
	vector<int> vec = {1,5,1};
	nextPermutation(vec);
	return 0;
}
