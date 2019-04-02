#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//123 ������Ʊ�����ʱ��3
/*
����һ�����飬���ĵ� i ��Ԫ����һ֧�����Ĺ�Ʊ�ڵ� i ��ļ۸�
���һ���㷨�����������ܻ�ȡ�������������������� ���� ���ס�
*/

//����һ�������ڶ�̬�滮���������飬���±���
//���Ȿ�����ҷ�ֵ����ģ������˴��еĴ𰸣��ܼ��
/*
��������ĳһ�쿼���ĸ�������
firstBuy:�ڸ����һ�������Ʊ���Ի�õ��������
firstSell:�ڸ����һ��������Ʊ���Ի�õ��������
secondBuy: �ڸ���ڶ��������Ʊ�ɻ�õ��������
secondSell: �ڸ���ڶ���������Ʊ�ɻ�õ��������
*/

int maxProfit(vector<int>& prices) {
	//��ʼ������
	int firstBuy = INT_MIN;
	int secondBuy = INT_MIN;
	int firstSell = 0;
	int secondSell = 0;
	//�������飬���±���
	for (int p : prices)
	{
		firstBuy = max(firstBuy, -p);//����firstBuy,�Ⱥ��ұߵ�firstBuy��֮ǰ����ĵ�һ������ɻ�õ�������棬����ǽ������룬�������0-p������firstBuy
		firstSell = max(firstSell, firstBuy + p);//firstSell,�Ⱥ��ұߵ�firstBuy�Ǹ��º��һ������ɻ�õ�������棬����ǽ����һ����������������Ǹ���firstBuy+p������firstSell
		secondBuy = max(secondBuy, firstSell - p);//�Ⱥ��ұߵ�firstSell�Ǹ��º��һ�������ɻ�õ�������棬�������ڶ������룬�������ΪfirstSell-p,����secondBuy
		secondSell = max(secondSell, secondBuy + p);//�Ⱥ��ұߵ�secondBuy�Ǹ��º�ڶ�������ɻ�õ�������棬�������ڶ���������������ΪsecondBuy+p,����secondSell
	}
	return secondSell;

}


//˼·����ǰ�������һ�Σ��õ��ӵ�1�쵽��i��֮��ֻ����һ�λ�õ�������󣬱��������1
//�Ӻ���ǰ����һ�Σ��õ��ӵ���i�쵽���һ��֮��ֻ����һ�λ�õ�������󣬱��������2
//��ô�ҽ�����1������2��������ͬ�±괦����ֵ�����±�iΪ������ӣ��ͱ�ʾ�ӵ�1�쵽���һ��(�Ե�i��Ϊ���)�������������õ����������
//����ȡ���ֵ����������
//��������
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	if (n<2)
		return 0;
	vector<int> dp1(n, 0);
	vector<int> dp2(n, 0);
	int minval = prices[0];//��ǰ�����������ǰ��Ʊ�۸�����ֵ������ֵ��
	int maxval = prices[n - 1];//�Ӻ�ǰ��������ǰ��Ʊ�۸�����ֵ������ֵ��
	for (int i = 1; i<n; i++)
	{
		dp1[i] = max(dp1[i - 1], prices[i] - minval);//��¼��i��������Ʊ���Ի�õ��������
		minval = min(minval, prices[i]);//���µ�ǰ��Ʊ��ͼ�
	}
	for (int i = n - 2; i >= 0; i--)
	{
		dp2[i] = max(dp2[i + 1], maxval - prices[i]);//��¼��i��������Ʊ���Ի�õ��������
		maxval = max(maxval, prices[i]);//���µ�ǰ��Ʊ��ͼ�
	}
	//���������ֵ
	int maxPro = dp1[0] + dp2[0];
	for (int i = 1; i<n; i++)
		maxPro = max(maxPro, dp1[i] + dp2[i]);
	return maxPro;

}

int main()
{
	vector<int> vec = {6,1,3,2,4,7 };
	int res = maxProfit(vec);
	return 0;
}