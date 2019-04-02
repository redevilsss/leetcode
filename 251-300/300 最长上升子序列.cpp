#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//300 �����������

/*
����һ��������������飬�ҵ���������������еĳ��ȡ�
ʾ��:
����: [10,9,2,5,3,7,101,18]
���: 4
����: ��������������� [2,3,7,101]�����ĳ����� 4��
*/


//�ó���Ķ�̬�滮���������Ӷ�Ϊo(n*n)
/*
���峤��Ϊ���鳤�ȵ�����dp,����dp[n]��ʾ��0-n������������г���
Ҫ������ֵ����Ҫ��nums[0]~nums[i-1]���е�����nums[i]�Ƚϣ�
���nums[j]С��nums[i]��j<i���͸��µ�ǰdp[i]Ϊmax(dp[i],dp[j]+1)
������dp�����ֵ����
*/
int lengthOfLIS(vector<int>& nums) {
	int len = nums.size();
	if (len == 0)
		return 0;
	vector<int>dp(len, 1);
	for (int i = 0; i<len; i++)
	{
		for (int j = 0; j<i; j++)
		{
			if (nums[j]<nums[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int res = dp[0];
	for (int i = 1; i<len; i++)
		res = max(res, dp[i]);
	return res;
}

//��һ��˼·�Ķ�̬�滮����֤��dp����Ԫ�صĵ����ԣ��ڲ�ѭ�����Ը�Ϊ���ֲ���
/*
���峤��Ϊ���鳤�ȵ�����dp,����dp[i]��ʾ���г���Ϊi+1�ĵ����������У���С������β��
��dp����һ���ǵ������飬������maxLen����ʾ��ǰ����������еĳ���
��������е����������жϽ�ÿ��������dp�����е���Ӧ��λ�ã�
1. num > dp[maxLen], ��ʾnum��������֪�������е�β������, ��num�����dp����β��, ������������г���maxL��1
2. dp[i-1] < num <= dp[i], ֻ������Ӧ��dp[i]
�����������õ���maxLen���ǽ��
*/
int lengthOfLIS(vector<int>& nums) {
	int len = nums.size();
	if (len == 0)
		return 0;
	int maxLen = 0;
	vector<int>dp(len, 1);
	for (int i = 0; i<len; i++)
	{
		//���ֲ��ң����ҵ�ǰnums[i]Ӧ���ڵ�λ��
		int low = 0;
		int high = maxLen;
		while (low<high)
		{
			int mid = (high - low) / 2 + low;
			if (dp[mid]<nums[i])
				low = mid + 1;
			else
				high = mid;
		}
		dp[low] = nums[i];
		//���low==maxLen��˵��һ��ʼnums[i]���Ǵ���dp[maxLen]��
		if (low == maxLen)
			maxLen++;
	}
	return maxLen;
}