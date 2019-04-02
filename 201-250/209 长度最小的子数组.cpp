#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//209 ������С��������
/*
����һ������ n ���������������һ�������� s ���ҳ���������������� �� s �ĳ�����С�����������顣��������ڷ������������������飬���� 0��
ʾ��:
����: s = 7, nums = [2,3,1,2,4,3]
���: 2
����: ������ [4,3] �Ǹ������µĳ�����С�����������顣
*/

/*
�������˫ָ���������ʼʱ��ָ�붼ָ����ʼλ�ã���ָ�����ָ��
���ó�ʼ��С����ΪINT_MAX����ǰ��sumΪ0
��ʼ���������ӵ�ǰrightָ���ֵ������ʱsum���ڵ���sʱ����¼��ǰ�ĳ���(right-left+1)
��������С���ȣ�leftָ��ǰ�ƣ�����sumֵ��ѭ��ֱ��sumС��s
�ٻص���ѭ���У�����rightָ��
*/
int minSubArrayLen(int s, vector<int>& nums) {
	int len = nums.size();
	int left = 0;
	int right = 0;
	int sum = 0;
	int minLen = INT_MAX;
	while (right < len)
	{
		sum += nums[right];
		while (sum >= s)
		{
			int curLen = right - left + 1;
			minLen = min(minLen, curLen);
			sum -= nums[left];
			left++;
		}
		right++;
	}
	if (minLen = INT_MAX)
		return 0;
	return minLen;
}