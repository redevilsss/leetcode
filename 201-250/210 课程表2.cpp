#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
//210 课程表2
/*
思路基本上和课程表1一样
多了一个用来保存课程号的数组而已
最终输出要进行判断，如果数组长度就等于numCourse，返回翻转后的数组
为什么要翻转数组？因为题目里的[a,b]表示的是想学习a得先学b，所以顺序应该是b a
如果不反转，最终数组顺序是和学习的顺序相反的
否则返回空，因为此时不能完成所有课程
*/

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<int> inDegree(numCourses, 0);//保存每个节点的入度
	list<int> *pList = new list<int>[numCourses];//邻接表
	queue<int> q;//用于进行拓扑排序的队列

	for (pair<int, int> i : prerequisites)
	{
		//更新顶点i.first的邻接矩阵，为有向边，即只更新first->second
		pList[i.first].push_back(i.second);
		inDegree[i.second]++;//给有向边的终点入度加1
	}
	//进行拓扑排序
	for (int i = 0; i<numCourses; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);//把所有入度为0的点的下标入队列
	}
	vector<int> res;//记录遍历到当前为止完成的课程
	int count = 0;//记录当前为止完成的课程数
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		res.push_back(v);//节点入数组
		count++;//完成课程数加1
		//给v节点的邻接表每一个元素入度减1，即相当于去掉了v节点
		for (auto it = pList[v].begin(); it != pList[v].end(); it++)
		{
			inDegree[*it]--;//入度减1
							//如果此时节点i入度为0，可以作为起点，将其加入队列
			if (inDegree[*it] == 0)
				q.push(*it);
		}
	}
	if (count != numCourses)
		return {};
	else
	{
		reverse(res.begin(), res.end());
		return res;
	}
}