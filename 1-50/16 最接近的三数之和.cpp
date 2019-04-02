#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//16 ��ӽ�������֮��
/*
����һ������ n ������������ nums �� һ��Ŀ��ֵ target��
�ҳ� nums �е�����������ʹ�����ǵĺ��� target ��ӽ���
�������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�
���磬�������� nums = [-1��2��1��-4], �� target = 1.
�� target ��ӽ����������ĺ�Ϊ 2. (-1 + 2 + 1 = 2).
*/

//����˼���ͬ15�⣬����׸����ֻ�Ƕ���һ���������ֵ�Ĺ���
int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int res = INT_MAX, len = nums.size();
	int left = 0, right = len - 1;
	int now, min_abs = INT_MAX;
	for (auto i = 0; i < len; ++i)
	{
		for (left = i + 1, right = len - 1; left < right;)
		{
			now = nums[i] + nums[left] + nums[right];
			if (target == now)
				return now;
			if (abs(target - now) < min_abs)
			{
				res = now;
				min_abs = abs(target - now);
			}
			if (now > target)
				right--;
			else
				left++;
		}
	}
	return res;
}
