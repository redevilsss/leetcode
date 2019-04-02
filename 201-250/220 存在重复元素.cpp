#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//219 存在重复元素2

/*
给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。
示例 1:
输入: nums = [1,2,3,1], k = 3, t = 0
输出: true
*/

/*
类似上题，但是这里有两个限制条件
即i-j<k和nums[i]-nums[k]<t，如何同时满足这两个条件？
前面说到滑窗可以保证第一个条件，那第二个条件就要在滑窗内部进行复杂度O(n*n)的查找判断，因为滑窗内是无序的
索性直接用set好了，自动对滑窗进行排序（复杂度为O(n*logn)），然后找第一个比nums[i]-t大的数，如果这个数在小于 nums[i]+t
那么这个数就满足|nums[i]-nums[j]|<t
就说明存在满足条件的元素
*/
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	set<long> s;
	long lt = t;
	for (int i = 0; i<nums.size(); i++)
	{
		//滑窗左边沿右移一位
		if (i>k)
			s.erase(nums[i - k - 1]);
		//在滑窗中找满足|nums[i]-nums[j]|<t的元素
		auto it = s.lower_bound(nums[i] - lt);
		if (it != s.end() && (*it) - nums[i] <= lt)
			//滑窗右边右移一位，实现滑窗移动
			return true;
		s.insert(nums[i]);
	}
	return false;
}