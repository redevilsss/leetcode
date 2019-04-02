#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//15 三数之和
/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
[-1, 0, 1],
[-1, -1, 2]
]
*/

//这道题当时我算了好长时间，思想就是取固定一数再找另外两数之和等于这个固定数的相反数
//正解应该是遍历取第一个数，然后取第二个和最后一个，移动指向第二个和最后一个数的执政
//找出正解
//而我是取了第一个数和最后一个数，取中间的数，想着这样能加快速度
//但是这样的话有一种案例是无法通过的
//-2 -1 -1 1 1 2
//如果拿到-2 1 1，就拿不到1 1 -2，因为每次都要移动下标，这种方法会漏掉一些结果

//收获：对多个数进行遍历时一定要有层次
//首先根据要求看需不需要先排序，再一层一层有序的剥开，而不是一股脑就为了快自己瞎搞
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.size() < 3)
		return res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 2; i++)
	{
		//因为数组种可能会有重复数字，排序后重复数字都相邻
		//重复的数字要跳过，因为再重复会出现重复答案
		if (i == 0 || nums[i] > nums[i - 1])
		{
			//取i的右边和数组末尾两个指针
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				int s = nums[i] + nums[left] + nums[right];
				if (s == 0)
				{
					res.push_back(vector<int>{nums[i], nums[left], nums[right]});
					left++;
					right--;
					//跳过重复元素，这里的跳过和前面的跳过不是相同的意思
					//前面的跳过是为了避免相同的第一个数，这里是为了避免相同的第二三个数
					while (left < right&&nums[left] == nums[left - 1])
						left++;
					while (left < right&&nums[right] == nums[right + 1])
						right--;
				}
				//如果和大于0，则要往小了取，把right左移
				else if (s > 0)
					right--;
				else//否则需要往大了取，left右移
					left++;
			}
		}
	}

	return res;
}

int main()
{
	vector<int> nums = { -1,0,1,2,-1,-4 };
	vector<vector<int>> res = threeSum(nums);
	return 0;
}