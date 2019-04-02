#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//128 ���������

/*
����һ��δ������������飬�ҳ���������еĳ��ȡ�
Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(n)��
ʾ��:
����: [100, 4, 200, 1, 3, 2]
���: 4
����: ����������� [1, 2, 3, 4]�����ĳ���Ϊ 4��
*/







//��ȻҪ�����㷨���Ӷȣ���Ҫ�ÿռ�����ʱ����
//��ΪҪ���������Զ�ÿ��Ԫ�صĲ��������ǳ���ʱ�䣬ֻ�й�ϣ��unordered_map�Ĳ����ǳ���ʱ���
//���ǽ�����ϣ��洢��ǰÿ��ֵ��Ӧ����������г��ȣ�Ϊ�����������hashmap����ʾ��ϣ��
//ʹ�� hashmap �������������Ѿ���������Ԫ�أ�key��ӦԪ�ص�ֵ��value��ʾ��Ԫ�����ڵ�����������ĳ��ȡ��������������һ��Ԫ��ʱ��������������� 
//1.���hashmap �д��ڴ�Ԫ�أ��������һ��Ԫ�ء� 
//2.���hashmap�в�����Ԫ�أ��� hashmap���Ƿ���ڴ�Ԫ�ص�ǰһ��Ԫ�أ�����˵���������5ʱ������hashmap���Ƿ���� 4�����������ȡ������������ĵ�һ��Ԫ�أ�����valueֵ+1��������Ԫ�طŵ�hashmap�У�valueֵ���һ��Ԫ��ֵ��ͬ������ʾ������������ĳ��ȡ� 
//3.���hashmap�д��ڸ�Ԫ�صĺ�һ��Ԫ�أ�������5ʱ��hashmap���Ƿ���� 6������Ԫ�ؼ��뵽��һ���������������У����Һ�2��һ�����ҵ�������ĵ�һ��Ԫ�غ����һ��Ԫ�أ������ǵ�valueֵ����Ϊ������ĳ��ȡ�
//Ҳ��������������ĵ�һ��Ԫ�غ����һ��Ԫ�ر�������ĳ���ֵ������һ���µ�Ԫ�ص�hashmap��ʱ����������Ĳ�ͬ���ʱ�����ò�ͬ�ķ�������valueֵ��
unordered_map<int, int> hashMap;
int merge(int low, int high);
int longestConsecutive(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	int maxLength = 1;//���û�����������У�����1������϶����ڵ���1��ȡ��ʼֵΪ1
	for (int i = 0; i<nums.size(); i++)
	{
		if (!hashMap.count(nums[i]))//�жϵ�ǰ��ϣ�����Ƿ���ڴ�Ԫ�أ�����������򽫸�Ԫ�ط���
		{
			hashMap[nums[i]] = 1;//keyֵ�ǵ�ǰ��Ԫ��ֵ����ֵ��ʾ��ǰԪ�����ڵ�������ĳ���
			if (hashMap.count(nums[i] - 1))//�����ǰ��ϣ���д��ڱȸ�Ԫ��С1������Ҫ�������Ԫ�����ڵ������г���
				maxLength = max(maxLength, merge(nums[i] - 1, nums[i]));
			if (hashMap.count(nums[i] + 1))//�����ǰ��ϣ���д��ڱȸ�Ԫ�ش�1������Ҫ�������Ԫ�����ڵ������г���
				maxLength = max(maxLength, merge(nums[i], nums[i] + 1));
		}
	}
	return maxLength;
}
//����Ԫ�����������еĳ���
//���µ�ǰ������ĵ�һ��Ԫ�غ����һ��Ԫ�ص�valueֵΪ�ϲ��������ĳ��ȣ�Ϊʲôֻ�ø���ͷ��β����Ϊÿ�θ��¶�Ҫ�������˵�
//����ֻҪ���¶˵㴦��ֵ��ok
int merge(int low, int high)
{
	int left = low - hashMap[low] + 1;//hashMap[low]��¼��low���ڵ������еĳ���,�����µ������е���߽����low-low���ڳ���+1
	int right = high + hashMap[high] - 1;//hashMap[high]��¼��high���ڵ������еĳ���,�����µ������е��ұ߽����high+high���ڳ���-1
	int length = right - left + 1;
	//�������µı��������е������˵��ֵ����Ϊ�µ������г���
	hashMap[left] = length;
	hashMap[right] = length;
	return length;
}

int main()
{
	vector<int> vec = { 0 };
	int res = longestConsecutive(vec);
	return 0;
}