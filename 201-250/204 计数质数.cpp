#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

//204 ��������
/*
ͳ������С�ڷǸ����� n ��������������
ʾ��:
����: 10
���: 4
����: С�� 10 ������һ���� 4 ��, ������ 2, 3, 5, 7 ��
*/


/*
�õ�����ɸ����
˼����Ƕ���һ���뵱ǰ��ͬ��������flag����ǰ����λ��ȫ��Ϊ1
Ȼ��ӵ�����λ�ã�Ҳ����2��ʼ����
���flag[i]Ϊ1�����±��i*i��ʼ������λ�õ���ֵ������,Ϊʲô���Ǵ�i*2��i*3�أ�
��Ϊ��ǰ��Щλ���Ѿ�������ˣ������ñʻ�����֤һ��
Ȼ�������ˣ�ֱ������������
��ʱ���������µ�����ֵΪ1��λ�ö�Ӧ���±���ǵ�ǰ1~n֮�������
*/
int countPrimes(int n) {
	if (n<3)
		return 0;
	vector<int> flag(n, 1);//��ʾ0~n-1
	flag[0] = 0;
	flag[1] = 0;
	for (long long i = 2; i<n; i++)
	{
		if (flag[i] == 1)
		{
			for (long long j = i*i; j<n; j += i)
				flag[j] = 0;
		}
	}
	int res = accumulate(flag.begin(), flag.end(), 0);
	return res;
}


int main()
{
	int res = countPrimes(10);
	return 0;
}