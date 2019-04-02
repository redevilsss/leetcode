#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//264 ����2
/*
��дһ�������ҳ��� n ��������
��������ֻ���������� 2, 3, 5 ����������
ʾ��:
����: n = 10
���: 12
����: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 ��ǰ 10 ��������
*/

//˼·����������ж�ÿ�����ǲ��ǳ�������������̫��
//�ÿռ任ʱ�䣬����֮ǰ������ֵ����֮ǰ�ĳ���ȥ�����µĳ������������飬��������ֶ����ź���ĳ�����ÿ����������ǰ��ĳ�������2��3��5�õ���
//���ȷ������ĳ����Ѿ��ź���
//�����������Ѿ��������ź���ĳ����������ļ�ΪM
//���ǰ����еĳ�����2���ҵ���һ������M�ĳ���M1��ͬ���3��5���õ�M3��M5��M2��M3��M5������������Сֵ������һ������
//����ÿһ�ζ����г������г�����Ҳ�Ƚ��鷳�����Զ���ָ�룬ÿ��ֻ���������ĳ˷��ͱȽ����㣬����ָ��ָ������ʵ��Ѱ�ҳ���
int nthUglyNumber(int n) {
	if (n<1)
		return -1;
	int* uglyNumber = new int[n];
	uglyNumber[0] = 1;
	int nextUglyIndex = 1;
	int* multiply2 = uglyNumber;
	int* multiply3 = uglyNumber;
	int* multiply5 = uglyNumber;
	while (nextUglyIndex<n)
	{
		//�ٸ����ӷ������ΪʲôҪ��ô������ʼʱ��ָ��1
		//��СֵΪ2����multiply2++��ָ��2������һ����СֵΪ3����multiply3++������һ��Ϊ5��multiply2++��multiply5++
		//Ҳ����˵ÿ���µ�Ԫ�ؽ���ugly����󣬵�ǰָ����ָ�����ֳ˸��Ե�����(2��3��5)���붼��������µ�Ԫ�أ�����������ǳ�������
		//����һ����ʱ��Ƚϵ���3*2��2*3��2*5����Сֵ��6����ʱ��multiply2++ָ��5��multiply3++ָ��3
		//���Կ������ַ���û��©��һ������Ҳ�������һ���������е�����ָ��ָ���Ķ��Ǽ�������ĳ������˵�Ҳ���ǳ������ӣ����Բ������һ����
		//�е�ǰ�����Ѵ洢��Ԫ����Ϊ���գ��ϸ���λ��˳��һ�����ݽ���Ҳ�������κ�һ��
		int Min = min(*multiply2 * 2, min(*multiply3 * 3, *multiply5 * 5));
		uglyNumber[nextUglyIndex] = Min;
		while (*multiply2 * 2 <= Min)
			multiply2++;
		while (*multiply3 * 3 <= Min)
			multiply3++;
		while (*multiply5 * 5 <= Min)
			multiply5++;
		++nextUglyIndex;
	}
	int ugly = uglyNumber[n - 1];
	delete[] uglyNumber;
	return ugly;
}