#include<iostream>
#include<vector>
using namespace std;

//275 Hָ��2

/*
����һλ�о������ı����ô��������飨�����ô����ǷǸ��������������Ѿ������������С���дһ��������������о��ߵ� h ָ����
h ָ���Ķ���: ��h ���������ô�������high citations����һ��������Ա�� h ָ����ָ���������� ��N ƪ�����У������� h ƪ���ķֱ����������� h �Ρ�������� N - h ƪ����ÿƪ�����ô��������� h �Ρ���"
ʾ��:
����: citations = [0,1,3,5,6]
���: 3
����: ���������ʾ�о����ܹ��� 5 ƪ���ģ�ÿƪ������Ӧ�ı������� 0, 1, 3, 5, 6 �Ρ�
�����о����� 3 ƪ����ÿƪ���ٱ������� 3 �Σ�������ƪ����ÿƪ�����ò����� 3 �Σ��������� h ָ���� 3��
*/


//�ö��ֲ�����ʵ�֣���Ҫ�ǶԲ�ͬ������жϣ���������е��ƿڣ�Ҫ��������������ٵ���˼
int hIndex(vector<int>& citations) {
	int len = citations.size();
	int begin = 0;
	int end = len - 1;
	int res = 0;
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		int count = len - mid;
		//��С�ڵ�ǰcitations[mid]��Ԫ�ظ���������������citations[mid]�ε�������Ϊcount
		//��������citations[mid]�ε�������������citations[mid]����ʱ������������Ҫ�鿴�Ƿ��и����countֵ����ʱ��mid+1�����ߣ�count��С��citations[mid]���û����
		//Ӧ����count����citations[mid]��С�ķ����ߣ��鿴����û�и����count
		if (count <= citations[mid])
		{
			res = count;
			end = mid - 1;
		}
		//��ʱ��������citations[mid]�ε�����������citations[mid]����������������count��С��citations[mid]����ķ���
		else
			begin = mid + 1;
	}
	return res;
}