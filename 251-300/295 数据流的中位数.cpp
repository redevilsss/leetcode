#include<iostream>
#include<vector>
#include<algorithm>
#include<xfunctional>
#include<queue>
using namespace std;

//295 数据流的中位数
/*
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
例如，
[2,3,4] 的中位数是 3
[2,3] 的中位数是 (2 + 3) / 2 = 2.5
设计一个支持以下两种操作的数据结构：
void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例：
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2
*/


//首先列一下没有排序的数组、排序的数组、排序的链表、二叉搜索树、AVL树、最大堆和最小堆几种不同的数据结构的时间复杂度
/*
*				数据结构			插入的时间复杂度				得到中位数的时间复杂度
*				没有排序的数组			O(1)								O(n)
*               排序的数组				O(n)								O(1)
*               排序的链表				O(n)								O(1)
*				二叉搜索树			平均O(logn)最差O(n)				平均O(logn)最差O(n)
*				AVL树					O(logn)								O(1)
*				最大堆和最小堆			O(logn)								O(1)
*/

//思路：用一个最大堆实现较小的一半数的数据容器，用一个最小堆实现较大的一半数的数据容器
//注意：
//保证数据平均分配到两个堆中，两个堆数据数目之差不能超过1
//为实现平均分配，数据总数目为偶数时把新数据插入最小堆，否则插入最大堆
//如果数据总数目为偶数而新数据要插到最小堆，但是这个数据比最大堆的一些数据小怎么办？
//先插入最大堆，然后把最大堆的最大数字拿出来插入最小堆，反之亦然


//用vector作为容器，在插入过程中每次进行堆排序保证顺序
//也可以直接用优先队列，用优先队列的话是不用排序的
class MedianFinder {
	vector<int> _min;
	vector<int> _max;
public:
	//维护一个最大堆和最小堆，最小堆中任意一个数都大于最大堆中最大的数
	//假设总数为偶数时，新数据会被插入到最小堆中，总数变为奇数，那么此时中位数就是最小堆的头
	//总数为奇数时，新数据插入到最大堆，总数变为偶数，中位数就是最大堆和最小堆的头元素的平均数
	/** initialize your data structure here. */
	MedianFinder() {

	}
	void addNum(int num) {
		if (((_min.size() + _max.size()) & 1) == 0)
		{
			//此时总数为偶，按理说应该插入到最小堆，但是如果此时该元素比最大堆的头元素小，就需要把这个元素插入到最大堆的合适位置
			//然后把最大堆头元素拿出来放到插入到最小堆去，这样才能保证最小堆的任意一个数都大于最大堆头元素，才能保证当前最小堆的头元素就是中位数
			if (_max.size()>0 && num<_max[0])
			{
				_max.push_back(num);
				//对当前数组元素进行降序堆排序
				push_heap(_max.begin(), _max.end(), less<int>());
				//保存最大堆的头元素
				num = _max[0];
				//将begin移动到第一个最大元素后面，同时将剩下的元素重新构造成一个新的heap
				pop_heap(_max.begin(), _max.end(), less<int>());
				//将最大堆中的头元素弹出
				_max.pop_back();
			}
			//num=max(_max[0],num)
			//将num插入最小堆并重新排序，此时中位数就是num
			_min.push_back(num);
			push_heap(_min.begin(), _min.end(), greater<int>());
		}
		//当当前总数为奇数时，新数据插入到最大堆，但新数据可能比最小堆里的数大，如果发生这种情况
		//最小堆的头元素拿出来，把新数据插入到最小堆的对应位置
		//再把最小堆的头元素插入最大堆，并重新堆排序
		else
		{
			if (_min.size()>0 && _min[0]<num)
			{
				_min.push_back(num);
				//对当前数组元素进行升序堆排序
				push_heap(_min.begin(), _min.end(), greater<int>());
				//保存最小堆的头元素
				num = _min[0];
				//将begin移动到第一个最大元素后面，同时将剩下的元素重新构造成一个新的heap
				pop_heap(_min.begin(), _min.end(), greater<int>());
				//将最小堆中的头元素弹出
				_min.pop_back();
			}
			//num=min(_min[0],num)
			//将num插入最大堆并重新排序，此时中位数就是(_min[0]+_max[0])/2
			_max.push_back(num);
			push_heap(_max.begin(), _max.end(), less<int>());
		}
	}

	double findMedian() {
		int size = _min.size() + _max.size();
		double mid = 0;
		if (size % 2 == 0)
			mid = (_min[0] + _max[0]) / 2;
		else
			mid = _min[0];
		return mid;
	}
};


class MedianFinder {
	priority_queue<int> big_heap;
	priority_queue<int, vector<int>, std::greater<>> small_heap;
public:
	//维护一个最大堆和最小堆，最小堆中任意一个数都大于最大堆中最大的数
	//假设总数为偶数时，新数据会被插入到最小堆中，总数变为奇数，那么此时中位数就是最小堆的头
	//总数为奇数时，新数据插入到最大堆，总数变为偶数，中位数就是最大堆和最小堆的头元素的平均数
	/** initialize your data structure here. */
	MedianFinder() {

	}
	void addNum(int num) {
		if (big_heap.size() == small_heap.size())
		{
			//此时总数为偶，按理说应该插入到最小堆，但是如果此时该元素比最大堆的头元素小，就需要把这个元素插入到最大堆的合适位置
			//然后把最大堆头元素拿出来放到插入到最小堆去，这样才能保证最小堆的任意一个数都大于最大堆头元素，才能保证当前最小堆的头元素就是中位数
			if (big_heap.size()>0 && num<big_heap.top())
			{
				big_heap.push(num);
				num = big_heap.top();
				big_heap.pop();
			}
			small_heap.push(num);
		}
		//当当前总数为奇数时，新数据插入到最大堆，但新数据可能比最小堆里的数大，如果发生这种情况
		//最小堆的头元素拿出来，把新数据插入到最小堆的对应位置
		//再把最小堆的头元素插入最大堆，并重新堆排序
		else
		{
			if (small_heap.size()>0 && small_heap.top()<num)
			{
				small_heap.push(num);
				//保存最小堆的头元素
				num = small_heap.top();
				//将最小堆中的头元素弹出
				small_heap.pop();
			}
			//num=min(_min[0],num)
			//将num插入最大堆并重新排序，此时中位数就是(_min[0]+_max[0])/2
			big_heap.push(num);
		}
	}

	double findMedian() {
		if (big_heap.size() == small_heap.size())
			return (double)(big_heap.top() + small_heap.top())*1.0 / 2;
		else
			return (double)(small_heap.top());
	}
};
int main()
{
	MedianFinder m;
	m.addNum(1);
	m.addNum(2);
	int res1 = m.findMedian();
	m.addNum(3);
	int res2 = m.findMedian();
	return 0;
}