#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
���� n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ���� (i, ai) ��
�������ڻ� n ����ֱ�ߣ���ֱ�� i �������˵�ֱ�Ϊ (i, ai) �� (i, 0)���ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
˵�����㲻����б�������� n ��ֵ����Ϊ 2��
ͼ�д�ֱ�ߴ����������� [1,8,6,2,5,4,8,3,7]���ڴ�����£������ܹ�����ˮ����ʾΪ��ɫ���֣������ֵΪ 49��
ʾ��:
����: [1,8,6,2,5,4,8,3,7]
���: 49
*/

//����ĺ�����������ܼ����ظ����㣬���͸��Ӷȣ�����Ľ����жϺ���������Ҫ
int maxArea(vector<int>& height) 
{
	//���ó�ʼʱ������λ��
	int end = height.size() - 1;
	int begin = 0;
	int res = 0;
	//ѭ�������ֵ
	while (begin<end)
	{
		int high = min(height[begin], height[end]);
		res = max(res, high*(end - begin));
		//�����ߵ�һ�ߣ���Ϊ��ʱ��res���������Եͱ�Ϊһ�߶�������֮������һ��Ϊ��һ����ɵ�ˮͰ���ݻ�
		//ľͰЧӦ�����ݻ��ɵͱߺͿ��������������Сʱ��ȥ���߱�ֻ��ʹ�ݻ���С
		if (height[begin]>height[end])				  
			end--;
		else
			begin++;
	}
	return res;
}