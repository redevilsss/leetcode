#include<iostream>
#include<deque>
#include<vector>
using namespace std;

/*
用双端队列来实现优先队列，保存元素的下标而不是值，因为通过下标可以保证滑窗大小为k，值不行
遍历数组做如下操作：
1.如果当前队列非空，且当前元素nums[i]比以队列中的尾元素为下标的数大，则弹出队列中的尾元素，因为这个数不可能会是某个滑窗的最大值
2.添加当前值对应的下标
3.如果当前下标i减去滑窗大小k大于等于当前最大值的下标，说明此时最大值因为滑窗限制将被清除
4.如果当前下标大于等于k-1，可以取滑窗最大值，总共有len-k+1个最大值
*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	if (nums.size()<k || nums.size() == 0)
		return {};
	//定义队列，让队列实现优先队列的功能
	deque<int> q;
	vector<int> res(nums.size() - k + 1, 0);
	for (int i = 0; i<nums.size(); i++)
	{
		//保证队列中的元素为降序，即q.front()为当前最大数的下标
		//如果下一个数比目前保存下标最后一个下标对应的数大，说明这个数不可能会是滑窗最大值，把这个下标删掉
		//举个例子：假设数组为2 3 4 2 6 2 5 1，目前index中有2和3（对应的数字是4和2）下一个下标对应的是6
		//因为6比2大，所以3出index，因为6比4大，所以4出index，因为此时滑窗为4 2 6，4和2是不可能再成为最大值的，直接删掉
		while (!q.empty() && nums[q.back()]<nums[i])
			q.pop_back();
		//添加当前值对应的下标到队列尾
		q.push_back(i);
		//如果此时index的头元素仍对应最大数，但是滑窗已经走过，此时已经不包括这个数在滑窗中了，所以要删除掉
		//这种情况出现时，最左元素比接下来两个元素都大的情况
		//举个例子：假设数组为2 3 4 2 6 2 5 1，目前index中有4和6（对应的数字是6和5）下一个index为7对应的是元素为1
		//但此时index为7，滑窗最右端为7-3+1=5
		if (!q.empty() && q.front() <= (int)(i - k))
			q.pop_front();

		//i从0-k-2时，窗口长度未到达k，不处理，当i>=k-1后,滑窗长度保持在k，此时每个滑窗都有一个最大值，置入res数组中
		if (i - k + 1 >= 0)
			res[i - k + 1] = nums[q.front()];
	}
	return res;
}