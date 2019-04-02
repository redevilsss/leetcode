#include<iostream>
#include<vector>
using namespace std;

//275 H指数2

/*
给定一位研究者论文被引用次数的数组（被引用次数是非负整数），数组已经按照升序排列。编写一个方法，计算出研究者的 h 指数。
h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）至多有 h 篇论文分别被引用了至少 h 次。（其余的 N - h 篇论文每篇被引用次数不多于 h 次。）"
示例:
输入: citations = [0,1,3,5,6]
输出: 3
解释: 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
由于研究者有 3 篇论文每篇至少被引用了 3 次，其余两篇论文每篇被引用不多于 3 次，所以她的 h 指数是 3。
*/


//用二分查找来实现，主要是对不同情况的判断，题读起来有点绕口，要理解这个至多和至少的意思
int hIndex(vector<int>& citations) {
	int len = citations.size();
	int begin = 0;
	int end = len - 1;
	int res = 0;
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		int count = len - mid;
		//不小于当前citations[mid]的元素个数，即至少引用citations[mid]次的文章数为count
		//至少引用citations[mid]次的文章数不多于citations[mid]，此时满足条件，但要查看是否还有更大的count值，此时往mid+1方向走，count变小，citations[mid]变大，没意义
		//应该往count变大而citations[mid]变小的方向走，查看还有没有更大的count
		if (count <= citations[mid])
		{
			res = count;
			end = mid - 1;
		}
		//此时至少引用citations[mid]次的文章数多于citations[mid]，不符合条件，向count减小而citations[mid]增大的方向
		else
			begin = mid + 1;
	}
	return res;
}