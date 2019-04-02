#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//42 ����ˮ

/*
���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
ʾ��:
����: [0,1,0,2,1,0,1,3,2,1,2,1]
���: 6
*/



//����⵱ʱ���ĺ���������Ϊ����ֱ�ӿ������ֵ������������û���ȱ�������Ϣ��ȡ
//������һ�α��������кܶ���Ϣû����ǰֱ�������º����������˺ܾû��ǲ���ͨ��ȫ������
//����˴𰸷���ԭ���ܼ򵥣���Ҫ��˼·����

//�ջ��ڴ���һЩ��������ʱ�ȿ��Ǳ������齫һЩ������Ϣ����


int trap(vector<int>& height) {
	int n = height.size();
	vector<int> left(n), right(n);
	//left�����right����ֱ��¼�����±��������ֵ���Ҳ�����ֵ
	for (int i = 1; i<n; i++)//left[i]��ʾi������������
		//����ͨ��left[i-1]���i�����߹�ͬ�ó�
		left[i] = max(left[i - 1], height[i - 1]);
	for (int i = n - 2; i >= 0; i--)//right����ͬ��
		right[i] = max(right[i + 1], height[i + 1]);
	//������Щ��Ϣ�����ֱ�����
	int res = 0;
	for (int i = 0; i<n; i++)
	{
		//ȡleft[i]��right[i]�Ľ�Сֵ��ľͰԭ���ɵ͵�һ�˾����ݻ�
		int level = min(left[i], right[i]);
		//���levelֵС�ڵ�ǰ�߶ȣ�˵��left[i]����height[i]����ʱi�����ܴ�ˮ
		//��������0
		res += max(0, level - height[i]);
	}
	return res;
}

//���Լ��ķ������������Ӧ�����޷�ʵ�ֵ�
int trap(vector<int>& height) {
	if (height.size()<3)
		return 0;
	vector<int> index;
	int res = 0;
	if (height[0]>=height[1])
		index.push_back(0);
	for (int i = 1; i<height.size() - 1; i++)
	{
		if (height[i]>=height[i - 1] && height[i]>=height[i + 1])
			index.push_back(i);
	}
	if (height[height.size() - 2]<=height[height.size() - 1])
		index.push_back(height.size() - 1);
	//ɾ������
	vector<int> index2;
	if (index.size() >= 3)
	{
		index2.push_back(index[0]);
		int compIndex = 0;
		for (int i = 1; i < index.size(); i++)
		{
			if (height[index[i]] >= height[index[compIndex]])
			{
				index2.push_back(index[i]);
				compIndex = i;
			}
		}
		if (height[index[compIndex]] > height[index[index.size() - 1]])
			for (int i = compIndex + 1; i < index.size(); i++)
				index2.push_back(index[i]);
	}
	else
		index2 = index;
	for (int i = 1; i < index2.size(); i++)
	{
		int min = height[index2[i - 1]] < height[index2[i]] ? height[index2[i - 1]] : height[index2[i]];
		for (int j = index2[i - 1]+1; j < index2[i]; j++)
			if(height[j]<min)
				res += min - height[j];
	}
	return res;
}



int main()
{
	vector<int> vec = {9, 2, 9, 3, 2, 2, 1, 4, 8};
	int res = trap(vec);
	return 0;
}