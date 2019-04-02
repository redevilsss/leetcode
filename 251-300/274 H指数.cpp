#include<iostream>
#include<vector>
using namespace std;

//274 H指数
/*
给定一位研究者论文被引用次数的数组（被引用次数是非负整数）。编写一个方法，计算出研究者的 h 指数。
h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）至多有 h 篇论文分别被引用了至少 h 次。（其余的 N - h 篇论文每篇被引用次数不多于 h 次。）”
示例:
输入: citations = [3,0,6,1,5]
输出: 3
解释: 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
由于研究者有 3 篇论文每篇至少被引用了 3 次，其余两篇论文每篇被引用不多于 3 次，所以她的 h 指数是 3。
*/

//用哈希表实现一个复杂度为O(n)的算法
/*
哈希表为hashTable,长度为数组长度+1，遍历数组，如果元素值大于数组长度，则hashTable[size+1]++
否则对于的hashTable[citations[i]]++
则最终哈希表第i位保存的就是引用数为i的论文的个数，而第size+1位保存的是引用数大于等于size的论文总数
从哈希表尾向前遍历，判断当前的值是否大于下标，从i=size开始，如果不大于则更新i-1的值为hashTable[i-1]+hashTable[i]，表示引用数大于等于i-1的论文的总和
直到某时刻hashTable[i] >= i,说明引用数为不少于i的论文最少有i篇
*/
int hIndex(vector<int>& citations) {
	int size = citations.size();
	vector<int> hashTable(size + 1, 0);
	//构造统计表
	for (int i = 0; i<size; i++)
	{
		if (citations[i] >= size)
			hashTable[size]++;
		else
			hashTable[citations[i]]++;
	}
	//找满足条件的数
	for (int i = size; i>0; i--)
	{
		if (hashTable[i] >= i)
			return i;
		hashTable[i - 1] += hashTable[i];
	}
	return 0;
}