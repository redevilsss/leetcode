#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//313 ��������

/*
��дһ�γ��������ҵ� n ������������
����������ָ���������������ǳ���Ϊ k �������б� primes �е���������
ʾ��:
����: n = 12, primes = [2,7,13,19]
���: 32
����: ��������Ϊ 4 �������б� primes = [2,7,13,19]��ǰ 12 ��������������Ϊ��[1,2,4,7,8,13,14,16,19,26,28,32] ��
*/


/*
˼·��264�����һ�£�ֻ������������������б��������ȷ��
��ô��Ҫ��264��һ������ָ�룬�ж��ٸ����Ӿ͹�����ٸ�������������p�У���ʼֵ��Ϊ0
����p[index]��ʾ��ǰ����prime[i]��ָ�룬������264���е�mutiply2��mutiply3��mutiply5
����uglyNumber���鳤��Ϊn����һ����Ϊ1�����е�ָ��p[i]��ʼ״̬��ָ��0
��ʼ������ÿһ�����������У�
1.������һ���������������min(primes[i]*uglyNumbers[p[index]]),i��0��primes.size()
2.����uglyNumbers[nextUglyIndex]
3.����ָ���ָ�򣬵�primes[i]*uglyNumbers[p[index]������Сֵʱ����p[index]++,ʹ���ʾ���±�ǰ��1λ

�ҵ�һ����⣺������264��Ĳ�ͬ���ڣ�û����ȷ��˵����Щ�����ɳ���������ͨ������������������ն�ָ���˼·�ߣ�
����Ҫ���ľ��ǹ���ָ�룬�ж��ٸ����Ӿ��ж��ٸ�ָ�룬����ָ������p���±��ܺ�prime��Ԫ�ض�Ӧ��
������Ҫ���ľͺ�264�⼸��һ���ˣ�Ϊʲô���ַ��������ظ�Ҳ����ȱʧ֮ǰ�Ѿ�˵���ˣ���Ϊ���ϸ����������������еģ�
����uglyNumbers�����Ԫ�ض��ǳ�������ÿ�γ˵�Ҳ���ǳ�������������Ԫ��ֻ���ܻ��ǳ�����ָ��ĸ��±������ظ�����ÿ��ѡȡ��Сֵ��֤�˲���ȱʧ
*/

int nthSuperUglyNumber(int n, vector<int>& primes) {
	if (primes.size() == 0 || n<1)
		return 0;
	vector<int> uglyNumbers(n, 0);
	uglyNumbers[0] = 1;
	int nextUglyIndex = 1;
	vector<int> p(primes.size(), 0);
	while (nextUglyIndex<n)
	{
		int Min = INT_MAX;
		int index = 0;
		//�ҵ�ǰ��һ�����ܵĳ������ж��ٸ�ָ����ж��ٸ����ܵ�ȡֵ������ѡȡ������С��
		for (int i = 0; i<primes.size(); i++)
		{
			if ((primes[i] * uglyNumbers[p[index]])<Min)
				Min = primes[i] * uglyNumbers[p[index]];
			index++;
		}
		//������һ������ֵ
		uglyNumbers[nextUglyIndex] = Min;
		//��������ָ��λ�ã�ʹ�õ�ǰָ����ָλ���ٳ˶�Ӧ�����Ӷ�����Min
		index = 0;
		for (int num : primes)
		{
			if (Min == num*uglyNumbers[p[index]])
				++p[index];
			index++;
		}
		nextUglyIndex++;
	}
	return uglyNumbers[n - 1];
}
int main()
{
	vector<int> v = { 2,7,13,19 };
	int res = nthSuperUglyNumber(12,v);
	return 0;
}