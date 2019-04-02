#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//56 合并区间

/*
给出一个区间的集合，请合并所有重叠的区间。
示例 1:
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:
输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};

//思路：要合并区间我先进行排序，排序按照区间的左值来进行
//那么只要前一个区间的右值大于后一个区间的左值，就能把区间合并
//如果前一个区间的右值比后一个区间的右值都大，还得继续遍历
//直到找到那个右值比刚才那个区间右值大的区间，本次合并完成，将合并后的区间放入新数组
//如果前一个区间和后一个区间没有交集，则直接将前一个区间放入新数组
vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> res;
	if (intervals.size() <= 1)
		return intervals;
	//排序后的区间，只要满足前面的end大于等于后面的start，两个区间就可以合并
	//区间[a,b] [c,d]可以合并的条件是a<c<=b<d或c<a<=d<b
	//排序后a<c b<d，只要c<=b可可以合并，并且如果不能和前面的合并，即c>b,则再往后也不能合并，因为后面区间的start比c还大，满足start>b
	sort(intervals.begin(), intervals.end(), [](Interval x, Interval y) {return x.start<y.start; });
	int i = 0;
	Interval temp = intervals[0];
	while (i<intervals.size())
	{

		if (i + 1<intervals.size() && temp.end >= intervals[i + 1].start)
		{
			if (temp.end<intervals[i + 1].end)//如果走到这一步，则下一步在i+1后进入循环时if是不成立的，因为此时end小于下一个的end，
											  //更小于下下一个的start，会进入else直接将修改后结果保存
				temp.end = intervals[i + 1].end;
		}
		else
		{
			res.push_back(temp);
			if (i + 1<intervals.size())
				temp = intervals[i + 1];
		}
		++i;
	}
	return res;
}