#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//90 �Ӽ�2

/*
����һ�����ܰ����ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����
˵�����⼯���ܰ����ظ����Ӽ���
ʾ��:
����: [1,2,2]
���:
[[2],[1],[1,2,2],[2,2],[1,2],[]]
*/


/*����һ��������˵ķ�����˼·����֮ǰ�Ѿ����ɵ����еĻ��������μ�����Ԫ�أ�����������
* ����˼·���ظ����еĳ�������Ϊ������Ԫ�ع�����û�ж���������ͬԪ�ؽ��д���
* ���� 1 2 2
* ��һ��������ʱ�Ӽ��� [] [1]
* �ڶ���������ʱ�Ӽ��� [] [1] [2] [1,2]�������������������ǰ�������Ļ����ϼ�2
* ������������ʱ�Ӽ��� [] [1] [2] [1,2] [2] [1,2] [2,2] [1 2 2]
* �ظ��ͳ����������һ��2������ʱ�Ӽ��Ѿ������� [2] [1 2]
* �ڶ���2����ʱ�Ͳ�Ӧ������2����֮ǰ���Ӽ�[] [1]�У���Ϊ֮ǰ�ڶ����Ѿ��������Ƶ�������
* �ж���Ԫ�ر������ٴΣ�����ܺ�ȷ��������������ζ���ÿ�α����Ĵ�����
* ������left right��Ϊÿ�α������½磬��length��������ǰһ�α����Ĵ���
* �������ظ�Ԫ��ʱ�����õ�ǰ�Ӽ�����ȥlength��Ϊ���α�������㣬����ʹ��±�0��ʼ
*/
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	vector<int> temp;
	res.push_back(temp);
	int right = 1, left = 0, length = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		if (i != 0 && nums[i] == nums[i - 1])
			left = res.size() - length;
		else
			left = 0;
		right = res.size();
		length = right - left;
		for (int j = left; j<right; j++)
		{
			temp = res[j];
			temp.push_back(nums[i]);
			res.push_back(temp);
		}
	}
	return res;
}

/* ����������֮ǰ�Ӽ�1�õ�λ���㣬�����Ľ������ȥ��
*/
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	int n = nums.size();
	for (int i = 0; i < (1 << n); i++)//1<<n����2��n�η�,���յĽ���Ӽ�����2��n�η���������ÿ��ѭ���õ�һ���Ӽ�������i�Ķ�����ÿһλ��ʾ�Ƿ�ȡ������ĳһλ��Ԫ��
	{
		vector<int> temp;
		//��һ���̲���һ���Ӽ����ٸ����ӣ����nums={1��2��3},��000��Ӧ�ռ���001 010 100�ֱ��Ӧ[1] [2] [3]��011 101 110�ֱ��ʾ[2,3] [1,3] [1,2] 111��ʾ[1,2,3]
		//��i��ÿһλ�����жϾ��ܵõ��Ӽ�
		for (int j = 0; j < n; j++)
			if (i >> j & 1)
				temp.push_back(nums[j]);
		res.push_back(temp);
	}
	//ɾ���ظ�Ԫ�أ�unique����������ͬԪ�س��أ��ظ����ַŵ���βȥ������ԭ���Ľ�β
	//��ԭ��β���½�β֮���Ԫ�����ظ���
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	return res;
}

/* ��������ʹ��ԭ78���Ӽ��еĻ����㷨������ȥ�غ�����
*/

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	vector<vector<int>> res;
	if (nums.size() == 0)
		return res;
	vector<int> temp;
	sort(nums.begin(), nums.end());
	func(res, temp, nums, 0);
	return res;
}
void func(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int index)
{
	res.push_back(temp);//ÿ�α����Ƚ���һ���õ���temp����
	for (int i = index; i < nums.size(); i++)
	{
		if (i > index && nums[i] == nums[i - 1])
			continue;//�����ظ�Ԫ��ʱֱ������
		temp.push_back(nums[i]);
		func(res, temp, nums, i + 1);
		temp.pop_back();
	}
}



