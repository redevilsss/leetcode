#include<iostream>
#include<vector>
using namespace std;

//162 寻找峰值

/*
峰值元素是指其值大于左右相邻值的元素。
给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
你可以假设 nums[-1] = nums[n] = -∞。
示例 1:
输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。
*/

/*这道题考的就是二分查找
首先确定的一点是峰值一定存在，把数组元素的起伏看成函数
只有单调增和单调减的时候没有峰值
但题目设定nums[-1]和nums[n]都是负无穷，
也就是说，无论如何，峰值肯定是存在的，除非所有的元素都是负无穷
可以想想高数里面的罗尔定理
只要首个元素大于第二个元素，就可以返回下标0
只要最后一个元素大于倒数第二个元素，就可以返回下标n-1
否则，再进行二分查找，如果找到某个节点大于两侧值就返回
不然就继续在子数组中找
规律如下：
如果nums[i] > nums[i-1]，则在i之后一定存在峰值元素
如果nums[i] < nums[i-1]，则在i之前（准确说是i-1之前）一定存在峰值元素
这个规律画个图就能理解，但让我证明我还真不会证，因为是离散的...
*/
int findPeakElement(vector<int>& nums) {
	if (nums.size() == 1)
		return 0;
	if (nums[0]>nums[1])
		return 0;
	if (nums[nums.size() - 1]>nums[nums.size() - 2])
		return nums.size() - 1;
	int begin = 0;
	int end = nums.size() - 1;
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		if (nums[mid]>nums[mid - 1] && nums[mid]>nums[mid + 1])
			return mid;
		if (nums[mid]>nums[mid - 1])
			begin = mid + 1;
		else
			end = mid;
	}
	return -1;
}