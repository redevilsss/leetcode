#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//96 不同的二叉搜索树
//给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？


//用动态规划来解决问题 创建一个n+1数组dp
/*当结点数分别为0 1 2时，不同的二叉搜索树个数为dp[0] dp[1] dp[2],值分别为1 1 2
//当结点数为3时，除了根节点，左右子树节点个数可以为0 2，1 1，2 0   dp[3]=3
//以此类推 节点数为n时，左右子树节点和为n-1，左子树个数取0~n-1，个数分别为dp[0]~dp[i-1],分别乘当前不同的右子树个数，也就是说dp[i]=: j从0到i-1 dp[j]*dp[i-1-j]的和
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

