#include<iostream>
#include<vector>
using namespace std;
/*
1.����֮��
����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�
ʾ��:
���� nums = [2, 7, 11, 15], target = 9
��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]
*/
using namespace std;
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> result;
	int l = nums.size();
	for (int i = 0; i<l; ++i)
		for (int j = i + 1; j<l; ++j)
		{
			if (nums[j] == target - nums[i])
			{
				result.push_back(i);
				result.push_back(j);
				break;
			}
		}
	return result;
}