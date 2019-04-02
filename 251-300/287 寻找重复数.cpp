#include<iostream>
#include<vector>
using namespace std;

//287 寻找重复数

/*
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
示例 1:
输入: [1,3,4,2,2]
输出: 2
*/

//这是一个另类的二分查找的问题
/*
为什么要说另类呢？因为之前见到的二分查找都是以位置的中点为基准来进行查找
这道题数字是无序的，但是取值在1-n之间
可以对取值进行二分查找，定义两个指针分别指向1和n
每次以中间值mid为参考，用count记录整个数组中不大于中间值的数字的多少、
如果这个count不大于mid，就说明不大于mid的数中肯定是没有重复的，而重复的数肯定比mid大
如果count大于mid，则重复数组肯定比mid小，因为如果不重复不大于mid1的数最多有mid个(从1到mid)

*/
int findDuplicate(vector<int>& nums) {
	int len = nums.size();
	if (len == 0)
		return 0;
	int begin = 1;
	int end = len - 1;
	while (begin < end)
	{
		int mid = (begin + end) / 2;
		int count = 0;
		for (int i = 0; i < len; i++)
		{
			if (nums[i] <= mid)
				count++;
		}
		if (count <= mid)
			begin = mid + 1;
		else
			end = mid;
	}
	return end;
}

int main()
{
	vector<int> vec = { 2,2,2,2,2 };
	int res = findDuplicate(vec);
	return 0;
}