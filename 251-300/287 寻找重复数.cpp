#include<iostream>
#include<vector>
using namespace std;

//287 Ѱ���ظ���

/*
����һ������ n + 1 ������������ nums�������ֶ��� 1 �� n ֮�䣨���� 1 �� n������֪���ٴ���һ���ظ�������������ֻ��һ���ظ����������ҳ�����ظ�������
ʾ�� 1:
����: [1,3,4,2,2]
���: 2
*/

//����һ������Ķ��ֲ��ҵ�����
/*
ΪʲôҪ˵�����أ���Ϊ֮ǰ�����Ķ��ֲ��Ҷ�����λ�õ��е�Ϊ��׼�����в���
���������������ģ�����ȡֵ��1-n֮��
���Զ�ȡֵ���ж��ֲ��ң���������ָ��ֱ�ָ��1��n
ÿ�����м�ֵmidΪ�ο�����count��¼���������в������м�ֵ�����ֵĶ��١�
������count������mid����˵��������mid�����п϶���û���ظ��ģ����ظ������϶���mid��
���count����mid�����ظ�����϶���midС����Ϊ������ظ�������mid1���������mid��(��1��mid)

*/
int findDuplicate(vector<int>& nums) {
	int len = nums.size();
	if (len == 0)
		return 0;
	int begin = 1;
	int end = len - 1;
	while (begin < end)
	{
		int mid = (begin + end) / 2;
		int count = 0;
		for (int i = 0; i < len; i++)
		{
			if (nums[i] <= mid)
				count++;
		}
		if (count <= mid)
			begin = mid + 1;
		else
			end = mid;
	}
	return end;
}

int main()
{
	vector<int> vec = { 2,2,2,2,2 };
	int res = findDuplicate(vec);
	return 0;
}