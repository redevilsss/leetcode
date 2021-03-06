#include<iostream>
#include<vector>
using namespace std;

//135 分发糖果
/*
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
你需要按照以下要求，帮助老师给这些孩子分发糖果：
每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？
示例 1:
输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
*/
//思路：
/*
* 模拟一下发糖果的过程，我现在不是算好每个人多少个然后依次性发，而是边发边算
* 如何保证每个孩子至少分配1颗糖果？ 先给每个人各一个
* 如何保证相邻孩子评分高的孩子获得糖果多？
* 可以拆分成：相邻孩子评分高的孩子比他左边的孩子获得糖果多和相邻孩子评分高的孩子比他右边的孩子获得糖果多
* 怎么实现？ 两次遍历，缺的给人补呗
* 保证比左边孩子获得糖果多好说，从左到右遍历，只要某个孩子比左边孩子得分高，就给他再发比左边孩子多一个
* 好了，这下只要再满足评分高的孩子比右边孩子获得糖果多就ok了
* 从右向左遍历，如果比右边孩子得分高，首先判断一下这个小孩手里的糖果是不是比右边孩子多，如果是的话就不用再给了，如果不是，给这个小孩的糖果数要比右边孩子多一个
* 其实就是用最少的糖果来满足这两个规则
* 转化为数学问题就是对应于一个数组创建新数组，要求新数组的值大于等于1，且完全符合原数组的起伏状态，也就是说，如果原数组中这个数比他左右两边都小，那新数组中它还是要比左右两个数都小
* 求总和最小的新数组
*/
int candy(vector<int>& ratings) {
	int res = 0;
	int n = ratings.size();
	res += n;//每人先发一个
	vector<int> temp(n, 0);//创建新数组，表示给每个人额外的糖果数（之前已经给了每人一个糖果）
	for (int i = 1; i<n; i++)
		if (ratings[i]>ratings[i - 1])//比左边大
			temp[i] = temp[i - 1] + 1;
	for (int i = n - 2; i >= 0; i--)
		if (ratings[i]>ratings[i + 1] && temp[i]<temp[i + 1] + 1)//比右边大
			temp[i] = temp[i + 1] + 1;
	for (int i = 0; i<n; i++)
		res += temp[i];
	return res;
}