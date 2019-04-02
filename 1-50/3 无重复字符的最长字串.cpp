#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;

//3 ���ظ��ַ�����ִ�

/*
����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
ʾ�� 1:
����: "abcabcbb"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��

ʾ�� 2:
����: "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��

ʾ�� 3:
����: "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���
*/


//�ҵķ��������ս�ָoffer��48�⣬��Ҫע����Ǵ��ⰸ�����ַ���������ĸ��������������ַ�����ո��
int lengthOfLongestSubstring(const string& str)
{
	int curLength = 0;
	int maxLength = 0;
	//���峤��Ϊ128�ı���������acsi��ֵ�����±���ַ����һ�γ��ֵ�λ��
	vector<int> position(128, -1);
	for (int i = 0; i < str.length(); i++)
	{
		//PrevIndex������ȡ��һ���ַ����ֵ�λ��
		int PrevIndex = position[str[i]];
		//���û���ֹ����߳���λ��������λ�õĲ����ڵ�ǰ�ۼƳ��ȣ���Ӱ�죩
		if (PrevIndex<0 || i - PrevIndex>curLength)
			++curLength;
		else
		{
			//������󳤶�
			if (curLength > maxLength)
				maxLength = curLength;
			//��ʱ����λ��������λ�õĲ��С���ۼƳ��ȣ����ȸ���Ϊ����һ�����ַ���ʼ����
			curLength = i - PrevIndex;
		}
		//���±����ַ����ֵ�λ����Ϣ
		position[str[i]] = i;
	}
	if (curLength > maxLength)
		maxLength = curLength;
	return maxLength;
}

//�������������淽��˼��һ�£�������
int lengthOfLongestSubstring(string s)
{
	vector<int>v(128, 0);//λ����Ϣ����ֵΪ0
	int t = 0; int ans = 0;//t��ʾ�ϴγ��ֵ�λ�ã�ans��ʾ��󳤶�
	for (int i = 0; i<s.length(); i++)
	{
		t = max(t, v[s[i]]);//��maxȡ�ϴγ��ֵ�λ��
		ans = max(ans, i - t + 1);//����������
		v[s[i]] = i + 1;//����λ����Ϣ��
	}
	return ans;
}