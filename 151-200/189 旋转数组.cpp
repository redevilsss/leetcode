#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//189 ��ת����

/*
����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����
ʾ�� 1:
����: [1,2,3,4,5,6,7] �� k = 3
���: [5,6,7,1,2,3,4]
����:
������ת 1 ��: [7,1,2,3,4,5,6]
������ת 2 ��: [6,7,1,2,3,4,5]
������ת 3 ��: [5,6,7,1,2,3,4]
*/


//��תӦ�������ķ�ʽ
//�ȷ�ת�������飬�ٷֱ�תǰk%len��Ԫ�غͺ����Ԫ��
void rotate(vector<int>& nums, int k) {
	int len = nums.size();
	if (len == 0)
		return;
	int step = k%len;
	if (step == 0)
		return;
	for (int i = 0; i<len/2; i++)
	{
		int temp = nums[i];
		nums[i] = nums[len - 1 - i];
		nums[len - 1 - i] = temp;
	}
	for (int i = 0; i<step/2; i++)
	{
		int temp = nums[i];
		nums[i] = nums[step - 1 - i];
		nums[step - 1 - i] = temp;
	}
	for (int i = step; i<(step+len)/2; i++)
	{
		int temp = nums[i];
		nums[i] = nums[len+step-1  - i];
		nums[len + step - 1 - i] = temp;
	}
}


int main()
{
	vector<int> vec = { 1,2,3,4,5,6,7 };
	rotate(vec, 3);
	return 0;
}