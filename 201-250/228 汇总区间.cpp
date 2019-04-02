#include<iostream>
#include<vector>
#include<string>
using namespace std;
//228 汇总区间
/*
给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。
示例 1:
输入: [0,1,2,4,5,7]
输出: ["0->2","4->5","7"]
解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
*/

/*
遍历一次搞定
主要考察的就是对不同状态的处理
从第一个元素开始，保存该数字的字符串形式
遍历如果当前元素比上一个元素多1，即连续，记录当前连续元素的个数
否则进入记录过程：
如果连续元素个数大于1，说明此连续元素组构成的字符串为a->b形式，将字符串+“->”+此时的元素，压入res种
否则只要把当前临时字符串（只有一个数），压入即可
最后遍历完成时要再做一次压入数组的处理
*/

vector<string> summaryRanges(vector<int>& nums) {
	if (nums.size() == 0)
		return {};
	vector<string> res;
	//只有一个元素时直接转化后入res并返回
	if (nums.size() == 1)
	{
		res.push_back(to_string(nums[0]));
		return res;
	}
	//初始化把第一个元素放入temp中
	string temp = to_string(nums[0]);
	//用来保存当前连续元素的个数
	int num = 1;
	for (int i = 1; i<nums.size(); i++)
	{
		//此时元素连续，更新连续元素个数
		if (nums[i] == nums[i - 1] + 1)
		{
			num++;
		}
		//此时不连续，将这个连续元素区间压入res
		else
		{
			//连续元素大于1时为a->b形式
			if (num>1)
				temp += "->" + to_string(nums[i - 1]);
			//否则只有一个元素，就是nums[i-1]
			res.push_back(temp);
			//初始化temp和num
			temp = to_string(nums[i]);
			num = 1;
		}
	}
	if (num>1)
		temp += "->" + to_string(nums[nums.size() - 1]);
	res.push_back(temp);
	return res;
}