#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//165 �Ƚϰ汾��
/*
�Ƚ������汾�� version1 �� version2��
��� version1 > version2 ���� 1����� version1 < version2 ���� -1�� ����֮�ⷵ�� 0��
����Լ���汾�ַ����ǿգ�����ֻ�������ֺ� . �ַ���
. �ַ�������С���㣬�������ڷָ��������С�
���磬2.5 ���ǡ������롱��Ҳ���ǡ���һ�뵽���������ǵڶ����еĵ����С�汾��
����Լ���汾�ŵ�ÿһ����Ĭ���޶����Ϊ 0�����磬�汾�� 3.4 �ĵ�һ������汾���͵ڶ�����С�汾���޶��ŷֱ�Ϊ 3 �� 4����������͵��ļ��޶��ž�Ϊ 0��
ʾ�� 1:
����: version1 = "0.1", version2 = "1.1"
���: -1
*/

/*
��������һ���򵥵ıȽ�
ͬʱ���������ַ�������.Ϊ�ָ��������ҵ�ǰ���ڵ�����.֮��Ĳ��֣���ǰָ���С�汾�ţ��������ⲿ��ת��Ϊʮ����ȥ�Ƚ�
����ȳ���С�ͷ��أ�������ձ������ֵ�����������Ƚ���һ��С�汾��
�����ȫһ�����ͷ���0

*/

int compareVersion(string version1, string version2) {
	int v1 = 0;
	int v2 = 0;
	for (int i = 0, j = 0; i<version1.length() || j<version2.length();)
	{
		int v1 = 0, v2 = 0;
		while (i<version1.length() && version1[i] != '.')
		{
			v1 = v1 * 10 + (version1[i] - '0');
			i++;
		}
		i++;
		while (j<version2.length() && version2[j] != '.')
		{
			v2 = v2 * 10 + (version2[j] - '0');
			j++;
		}
		j++;
		if (v1>v2)
			return 1;
		if (v1<v2)
			return -1;
	}
	return 0;
}

