#include<iostream>
#include<vector>
#include<string>
using namespace std;
//228 ��������
/*
����һ�����ظ�Ԫ�ص������������飬�����������䷶Χ�Ļ��ܡ�
ʾ�� 1:
����: [0,1,2,4,5,7]
���: ["0->2","4->5","7"]
����: 0,1,2 �����һ������������; 4,5 �����һ�����������䡣
*/

/*
����һ�θ㶨
��Ҫ����ľ��ǶԲ�ͬ״̬�Ĵ���
�ӵ�һ��Ԫ�ؿ�ʼ����������ֵ��ַ�����ʽ
���������ǰԪ�ر���һ��Ԫ�ض�1������������¼��ǰ����Ԫ�صĸ���
��������¼���̣�
�������Ԫ�ظ�������1��˵��������Ԫ���鹹�ɵ��ַ���Ϊa->b��ʽ�����ַ���+��->��+��ʱ��Ԫ�أ�ѹ��res��
����ֻҪ�ѵ�ǰ��ʱ�ַ�����ֻ��һ��������ѹ�뼴��
���������ʱҪ����һ��ѹ������Ĵ���
*/

vector<string> summaryRanges(vector<int>& nums) {
	if (nums.size() == 0)
		return {};
	vector<string> res;
	//ֻ��һ��Ԫ��ʱֱ��ת������res������
	if (nums.size() == 1)
	{
		res.push_back(to_string(nums[0]));
		return res;
	}
	//��ʼ���ѵ�һ��Ԫ�ط���temp��
	string temp = to_string(nums[0]);
	//�������浱ǰ����Ԫ�صĸ���
	int num = 1;
	for (int i = 1; i<nums.size(); i++)
	{
		//��ʱԪ����������������Ԫ�ظ���
		if (nums[i] == nums[i - 1] + 1)
		{
			num++;
		}
		//��ʱ�����������������Ԫ������ѹ��res
		else
		{
			//����Ԫ�ش���1ʱΪa->b��ʽ
			if (num>1)
				temp += "->" + to_string(nums[i - 1]);
			//����ֻ��һ��Ԫ�أ�����nums[i-1]
			res.push_back(temp);
			//��ʼ��temp��num
			temp = to_string(nums[i]);
			num = 1;
		}
	}
	if (num>1)
		temp += "->" + to_string(nums[nums.size() - 1]);
	res.push_back(temp);
	return res;
}