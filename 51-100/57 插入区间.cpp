#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//57 插入区间

/*
给出一个无重叠的 ，按照区间起始端点排序的区间列表。
在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
示例 1:
输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
输出: [[1,5],[6,9]]
*/

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};

//这道题难度不大，但是考虑问题一定要全面，首先对原区间按照左值大小排序
//新区间有这几种特殊情况出现
//1.新区间的右值小于最左原区间的左值，此时直接将新区间加到原区间最前面即可
//2.新区间的左指大于最右原区间的右值，此时直接将新区间加到原区间最后面
//3.新区间在原区间中间某个位置，但是没有重合部分，直接插入在该位置
//4.新区间在原区间中间某个位置且有重合部分，找到最后生成的大区间，最后的大区间的左值就是新区间左值和第一个与新区间有重合的原区间左值两者的较小值
//最后的大区间的右值就是新区间右值和第一个与新区间有重合的原区间右值两者的较小值
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval> res;
	if (intervals.size() == 0)
	{
		res.push_back(newInterval);
		return res;
	}
	//根据区间头大小排序
	sort(intervals.begin(), intervals.end(), [](Interval x, Interval y) {return x.start<y.start; });
	//此时新区间在第一个的前面，直接放进去，把原区间数组复制
	if (intervals[0].start>newInterval.end)
	{
		res.push_back(newInterval);
		for (int i = 0; i<intervals.size(); i++)
			res.push_back(intervals[i]);
		return res;
	}
	//说明在第一个的后面，先根据限制条件找到与区间合并无关的前面的区间并保存
	int i = 0;
	while (i<intervals.size() && intervals[i].end<newInterval.start)
	{
		res.push_back(intervals[i]);
		i++;
	}
	//如果所有区间都与合并无关，则说明新区间的start大于原区间包含的最大值，直接放到数组尾部即可
	if (i == intervals.size())//说明新的区间单独在最后
		res.push_back(newInterval);
	else
	{
		Interval temp = intervals[i];
		//此时新区间在原区间组的第i个区间和第i+1个区间之间，没有重合部分
		if (temp.start>newInterval.end)
		{
			res.push_back(newInterval);
			res.push_back(temp);
		}
		else
		{
			//取新区间覆盖的起点值
			temp.start = min(intervals[i].start, newInterval.start);
			//找新区间覆盖的终点，也就是与新区间存在区域重合的最后一个数组并修改新的大区间的上限值
			while (i + 1<intervals.size() && intervals[i].end<newInterval.end&&intervals[i + 1].start <= newInterval.end)
				i++;
			temp.end = max(intervals[i].end, newInterval.end);
			res.push_back(temp);
		}
		//对剩余区间进行处理
		for (int j = i + 1; j<intervals.size(); j++)
			res.push_back(intervals[j]);
	}

	return res;
}

int main()
{
	vector<Interval> vec;
	vec.push_back(Interval(3, 5));
	vec.push_back(Interval(12, 15));
	//vec.push_back(Interval(6, 11));
	//vec.push_back(Interval(8, 10));
	//vec.push_back(Interval(12, 16));
	Interval newInterval(6, 6);
	vector<Interval> res = insert(vec, newInterval);
	return 0;
}