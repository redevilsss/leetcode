#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//219 存在重复元素2

/*
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。
示例 1:
输入: nums = [1,2,3,1], k = 3
输出: true
*/

//方法一：利用哈希表来实现
//既然要比较相同元素下标差，就需要构造键值对，key是值，value是下标，选择hashmap来实现
//遍历数组，每一步通过count函数检查当前hsahmap中有没有当前元素
//如果有，就判断当前下标和上一个相同元素的下标差是不是小于等于k，如果两个条件都满足，返回true
//否则将当前的(nums[i],i)键值对插入：之前如果有键nums[i]，则更新，如果没有，就插入
bool containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_map<int, int> record;//值，下标
	for (int i = 0; i<nums.size(); i++)
	{
		if (record.count(nums[i]) && (i - record[nums[i]]) <= k)
			return true;
		else
			record[nums[i]] = i;
	}
	return false;
}

//方法二：滑窗法
/*
通过滑窗来实现，先满足限制条件|i-j|<k,其实可以更新为i-j<k
可以维持一个长度为k的滑窗，每次在当前滑窗中查找滑窗右边界右侧元素
不需要构造长度为2k+1的滑窗(以当前节点为中点)，因为后面的总会遍历到的，长度为k即可
因为当前元素nums[i]的下标i和滑窗中的元素下标j满足i-j<k，也就是说我在数组中查找这个元素是否重复时，只需要查找这个滑窗中是否存在nums[i]即可
过程如下：
1.把滑窗左边界右移一位，此时滑窗长度变为k-1
2.在滑窗中查找元素nums[i]，如果找到就返回true
3.找不到就把右边界右移一位包含nums[i]
4.重复上述操作直到遍历完成
*/
bool containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_set<int> s;
	for (int i = 0; i<nums.size(); i++)
	{
		//滑窗左边沿右移一位
		if (i>k)
			s.erase(nums[i - k - 1]);
		//查找当前滑窗中有无值等于nums[i]的元素
		if (s.find(nums[i]) != s.end())
			return true;
		//滑窗右边右移一位，实现滑窗移动
		s.insert(nums[i]);
	}
	return false;
}
int main()
{
	vector<int> vec = { 1,2,3,1 };
	bool res = containsNearbyDuplicate(vec, 3);
	return 0;
}