#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 18 四数之和

/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：
答案中不可以包含重复的四元组。
示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
满足要求的四元组集合为：
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/
//和15题思想一致，相比与15题多了一层循环，仅此而已
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	if (nums.size()<4)
		return {};
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i<nums.size() - 3; i++)
	{
		if (i>0 && nums[i] == nums[i - 1])
			continue;
		for (int j = i + 1; j<nums.size() - 2; j++)
		{
			if (j>i + 1 && nums[j] == nums[j - 1])
				continue;
			int left = j + 1;
			int right = nums.size() - 1;
			while (left<right)
			{
				int s = nums[i] + nums[j] + nums[left] + nums[right];
				if (s == target)
				{
					res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
					while (left<right&&nums[left] == nums[left + 1])
						left++;
					while (left<right&&nums[right] == nums[right - 1])
						right--;
					left++;
					right--;
				}
				else if (s>target)
					right--;
				else
					left++;
			}
		}
	}
	return res;
}