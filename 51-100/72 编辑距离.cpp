#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//72 �༭����
/*
������������ word1 �� word2��������� word1 ת���� word2 ��ʹ�õ����ٲ����� ��
����Զ�һ�����ʽ����������ֲ�����
����һ���ַ���ɾ��һ���ַ����滻һ���ַ�
ʾ�� 1:
����: word1 = "horse", word2 = "ros"
���: 3
����:
horse -> rorse (�� 'h' �滻Ϊ 'r')
rorse -> rose (ɾ�� 'r')
rose -> ros (ɾ�� 'e')
*/

//����⻹�����Ѷȣ�һ��ʼû���뵽�ö�̬�滮ȥ����������ƥ��
//���Ǵ�ƥ��ĽǶ�����̫����ȥ�����ʹ�ö�̬�滮����һ����ά����
//һ���������з������Ʊ�֤ÿһ��ת���Ĳ�������С�����ջ�ý��
int minDistance(string word1, string word2) {
	int m = word1.length();
	int n = word2.length();
	/**
	dp[i][j] ��ʾ ʹword1 �ĵ� [1~i] λ�� word2 �� [1~j] λ��ͬ
	��������ٲ�����. �����ʽΪ:
	if(word1[i] == word2[j])
	dp[i][j] = dp[i-1][j-1]
	else
	dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
	**/
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	// �߽����, ��һ���ַ���ת���ɿ��ַ����Ĳ���
	for (int i = 1; i <= m; i++) dp[i][0] = i;
	for (int i = 1; i <= n; i++) dp[0][i] = i;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (word1[i - 1] == word2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;

		}
	}
		
	return dp[m][n];

}