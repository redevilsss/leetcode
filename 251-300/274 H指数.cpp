#include<iostream>
#include<vector>
using namespace std;

//274 Hָ��
/*
����һλ�о������ı����ô��������飨�����ô����ǷǸ�����������дһ��������������о��ߵ� h ָ����
h ָ���Ķ���: ��h ���������ô�������high citations����һ��������Ա�� h ָ����ָ���������� ��N ƪ�����У������� h ƪ���ķֱ����������� h �Ρ�������� N - h ƪ����ÿƪ�����ô��������� h �Ρ�����
ʾ��:
����: citations = [3,0,6,1,5]
���: 3
����: ���������ʾ�о����ܹ��� 5 ƪ���ģ�ÿƪ������Ӧ�ı������� 3, 0, 6, 1, 5 �Ρ�
�����о����� 3 ƪ����ÿƪ���ٱ������� 3 �Σ�������ƪ����ÿƪ�����ò����� 3 �Σ��������� h ָ���� 3��
*/

//�ù�ϣ��ʵ��һ�����Ӷ�ΪO(n)���㷨
/*
��ϣ��ΪhashTable,����Ϊ���鳤��+1���������飬���Ԫ��ֵ�������鳤�ȣ���hashTable[size+1]++
������ڵ�hashTable[citations[i]]++
�����չ�ϣ���iλ����ľ���������Ϊi�����ĵĸ���������size+1λ����������������ڵ���size����������
�ӹ�ϣ��β��ǰ�������жϵ�ǰ��ֵ�Ƿ�����±꣬��i=size��ʼ����������������i-1��ֵΪhashTable[i-1]+hashTable[i]����ʾ���������ڵ���i-1�����ĵ��ܺ�
ֱ��ĳʱ��hashTable[i] >= i,˵��������Ϊ������i������������iƪ
*/
int hIndex(vector<int>& citations) {
	int size = citations.size();
	vector<int> hashTable(size + 1, 0);
	//����ͳ�Ʊ�
	for (int i = 0; i<size; i++)
	{
		if (citations[i] >= size)
			hashTable[size]++;
		else
			hashTable[citations[i]]++;
	}
	//��������������
	for (int i = size; i>0; i--)
	{
		if (hashTable[i] >= i)
			return i;
		hashTable[i - 1] += hashTable[i];
	}
	return 0;
}