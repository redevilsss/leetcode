#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//128 最长连续序列

/*
给定一个未排序的整数数组，找出最长连续序列的长度。
要求算法的时间复杂度为 O(n)。
示例:
输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/







//既然要求了算法复杂度，就要用空间来换时间了
//因为要遍历，所以对每个元素的操作必须是常数时间，只有哈希表unordered_map的查找是常数时间的
//考虑建立哈希表存储当前每个值对应的最大子序列长度（为便理解下面用hashmap来表示哈希表）
//使用 hashmap 来保存数组中已经遍历过的元素，key对应元素的值，value表示该元素所在的连续子数组的长度。当遍历到数组的一个元素时有以下四种情况： 
//1.如果hashmap 中存在此元素，则遍历下一个元素。 
//2.如果hashmap中不存在元素，则看 hashmap中是否存在此元素的前一个元素，比如说如果遍历到5时，看看hashmap中是否存在 4，如果存在则取该连续子数组的第一个元素，将它value值+1，并将该元素放到hashmap中，value值与第一个元素值相同，都表示该连续子数组的长度。 
//3.如果hashmap中存在该元素的后一个元素，遍历到5时，hashmap中是否存在 6，将此元素加入到后一个连续的子数组中，并且和2中一样，找到子数组的第一个元素和最后一个元素，将它们的value值更新为子数组的长度。
//也就是用连续数组的第一个元素和最后一个元素保存数组的长度值，插入一个新的元素到hashmap中时当遇到上面的不同情况时，采用不同的方法更新value值。
unordered_map<int, int> hashMap;
int merge(int low, int high);
int longestConsecutive(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	int maxLength = 1;//如果没有连续子序列，返回1，结果肯定大于等于1，取初始值为1
	for (int i = 0; i<nums.size(); i++)
	{
		if (!hashMap.count(nums[i]))//判断当前哈希表中是否存在此元素，如果不存在则将该元素放入
		{
			hashMap[nums[i]] = 1;//key值是当前的元素值，键值表示当前元素所在的子数组的长度
			if (hashMap.count(nums[i] - 1))//如果当前哈希表中存在比该元素小1的数，要更新这个元素所在的子序列长度
				maxLength = max(maxLength, merge(nums[i] - 1, nums[i]));
			if (hashMap.count(nums[i] + 1))//如果当前哈希表中存在比该元素大1的数，要更新这个元素所在的子序列长度
				maxLength = max(maxLength, merge(nums[i], nums[i] + 1));
		}
	}
	return maxLength;
}
//更新元素所在子序列的长度
//更新当前子数组的第一个元素和最后一个元素的value值为合并后的数组的长度，为什么只用更新头和尾？因为每次更新都要找两个端点
//所以只要更新端点处的值就ok
int merge(int low, int high)
{
	int left = low - hashMap[low] + 1;//hashMap[low]记录了low所在的子序列的长度,所以新的子序列的左边界就是low-low所在长度+1
	int right = high + hashMap[high] - 1;//hashMap[high]记录了high所在的子序列的长度,所以新的子序列的右边界就是high+high所在长度-1
	int length = right - left + 1;
	//将现在新的变大的子序列的两个端点的值更新为新的子序列长度
	hashMap[left] = length;
	hashMap[right] = length;
	return length;
}

int main()
{
	vector<int> vec = { 0 };
	int res = longestConsecutive(vec);
	return 0;
}