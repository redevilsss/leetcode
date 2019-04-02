#include<iostream>
#define MAX 0X7FFFFFFF
#define MIN 0X80000000

//29 �������

/*
�������������������� dividend �ͳ��� divisor�������������Ҫ��ʹ�ó˷��������� mod �������
���ر����� dividend ���Գ��� divisor �õ����̡�
ʾ�� 1:
����: dividend = 10, divisor = 3
���: 3

ʾ�� 2:
����: dividend = 7, divisor = -3
���: -2
*/

//����⻹�Ǻ��ѵģ����õ���û���뷨�����ձ��˵��뷨д��
//��Ҫ�ǿ���λ���㣬����������Ķ�����˵���һ������ǲ���ʵ
int divide(int dividend, int divisor) {
	//���dividend���ڸ����ֵ����������-1��ֱ�ӷ���max
	if (dividend == MIN && divisor == -1)
		return MAX;
	//�������ͱ�������ȡ����ֵ
	unsigned long temp1 = abs(dividend);
	unsigned long temp2 = abs(divisor);
	if (temp1 < temp2)
		return 0;
	//flag��ǽ���������Ǹ�����Ϊ�����ڼ������Ҫȡ��
	int flag = 1;
	if ((dividend & divisor & MIN) == 0 && (dividend < 0 || divisor < 0))
		flag = -1;
	//i��Ϊ���գ���������temp1��temp2�Ĳ��
	int i = 1;
	unsigned long d = temp2;


	if (d == 1)
		i = temp1;
	else {
		//�������i������temp1��temp2�Ĳ��
		while (temp1 > d) {
			d <<= 1;
			i <<= 1;
		}
		//��temp1С��d��˵���߹��ˡ�i��d���˻�һ�����������г���
		//��������ھ�ֱ��return i�Ϳ�����
		if (temp1 < d)
			i = (i >> 1) + divide(temp1 - (d >> 1), temp2);
	}

	if (flag < 0)
		i = -i;

	return i;
}

int main()
{
	int res = divide(-2147483648, 2);
	return 0;
}