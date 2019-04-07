#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//�ö�̬�滮���������
/*
�����ά����dp��dp[i][j]��ʾ��i��j�Ŀ��Ի�õ����Ӳ��
����ʽ��dp[i][j] = max(dp[i][j], nums[k] * right*left + before + after);
����right��left�ֱ���nums[i-1]��nums[j-1]��k��ʾi��j֮�����һ�����Ƶ������λ��
before��ʾdp[i][k-1],after��ʾdp[k+1][j]
����ѭ������һ��ȷ�����䳤�ȣ��ڶ���ȷ������յ㣬��������dp[i][j]�����ֵ��ͨ������ĺϲ���ʵ��
*/
int maxCoins(vector<int>& nums) {
	int len = nums.size();
	if (len == 0)
		return 0;
	vector<vector<int>> dp(len, vector<int>(len, 0));
	//l��ʾ��ǰ����
	for (int l = 1; l <= len; l++)
	{
		//i��0~len-l+1(��iΪlen-lʱ��jָ�����һ������)����ʾ��ǰ������Χ����߽�
		for (int i = 0; i + l - 1<len; i++)
		{
			//j��ʾ����Ϊlʱ������Χ���ұ߽�
			int j = i + l - 1;
			//��������Ҫ�����i��jΪ�߽�������ܻ�õ����Ӳ��
			//left��right�ֱ��ʾ��ǰ��Χ����������Ԫ��ֵ
			int left = i == 0 ? 1 : nums[i - 1];
			int right = j == len - 1 ? 1 : nums[j + 1];
			//k��ʾi��j�м����һ�����Ƶ�λ��
			for (int k = i; k <= j; k++)
			{
				//before��after��ʾ��i��k-1��k+1��j�����Ӳ��ֵ,����kȡֵΪ��i��j
				int before = k == i ? 0 : dp[i][k - 1];
				int after = k == j ? 0 : dp[k + 1][j];
				dp[i][j] = max(dp[i][j], nums[k] * right*left + before + after);
			}
		}
	}
	return dp[0][len - 1];
}
/*
int main()
{
	vector<int> v = { 3,1,5,8 };
	int res = maxCoins(v);
	return 0;
}
*/