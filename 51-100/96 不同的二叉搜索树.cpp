#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//96 ��ͬ�Ķ���������
//����һ������ n������ 1 ... n Ϊ�ڵ���ɵĶ����������ж����֣�


//�ö�̬�滮��������� ����һ��n+1����dp
/*��������ֱ�Ϊ0 1 2ʱ����ͬ�Ķ�������������Ϊdp[0] dp[1] dp[2],ֵ�ֱ�Ϊ1 1 2
//�������Ϊ3ʱ�����˸��ڵ㣬���������ڵ��������Ϊ0 2��1 1��2 0   dp[3]=3
//�Դ����� �ڵ���Ϊnʱ�����������ڵ��Ϊn-1������������ȡ0~n-1�������ֱ�Ϊdp[0]~dp[i-1],�ֱ�˵�ǰ��ͬ��������������Ҳ����˵dp[i]=: j��0��i-1 dp[j]*dp[i-1-j]�ĺ�
*/
int numTrees(int n) {
	if (n <= 1)
		return 1;
	int *dp = new int[n + 1];
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = 0;
		for (int j = 0; j <= i - 1; j++)
			dp[i] += dp[j] * dp[i - 1 - j];
	}
	return dp[n];
}
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

