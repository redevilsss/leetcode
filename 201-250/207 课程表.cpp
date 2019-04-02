#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

//207 课程表

/*
现在你总共有 n 门课需要选，记为 0 到 n-1。
在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？
示例 1:
输入: 2, [[1,0]]
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
*/


//方法：kahn算法
/*
这道题主要用到图的拓扑排序的kahn算法，其思想为bfs
用专业术语来形容就是：判断有向图中是否存在环，放到题里大概表示这种情况：
要学a先学b，要学b先学a，那么这个图就是有环的
为什么和图联系到一起呢？因为先学课程到后学课程可以用图的有向边来模拟
首先构建新的邻接表，表明每个元素可以到达的节点，这里的边都是有向边，即a->b不一定就有b->a
再用一个数组记录每个节点的入度，然后正式开始拓扑排序
我现在要做的就是找满足题目所说的先学后学条件的课程，如果找到的总课程数就是numCourses，说明可以完成所有课程，否则不行
排序的过程如下：
1.先把所有入度为0的节点入队，因为如果某个节点某时刻入度为0，那这个节点就是一个先学课程
2.每次取队列头节点，更新当前可完成课程数，把该节点的所有邻接点入度减1，也就是说把这个点删掉，此时如果有邻接点入度变成0，就把该节点也入队
3.重复2，直到队列为空
*/


bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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
	int count = 0;//记录遍历到当前为止完成的课程
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
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
	return count == numCourses;
}


/*
如果知道图是无环有向图，那么可以直接用dfs来实现
基于DFS的拓扑排序算法（前提：图是DAG）：
L ← 用于存放排序结果的数组
S ← 出度为0的顶点的集合
for (S中的每个顶点)
	dfs(n)

void dfs(node n)
{
	if (!vis[n])//vis为visit数组，标记节点有无被访问过
	{
		vis[n] = true;
		对每个以n为终点的边的起点进行遍历
		for (每一个顶点m，满足m->n)
			dfs(m);
	}
	L.push(n);//终点的加入总在起点之后，因为这里前提是无环有向图
}
可以看到，我们只是在dfs函数快退出时将结点加入到L中而已。
（注意，for中的顶点m，满足的是m->n而不是n->m）
下面简单证明一下它的正确性：
对任意的边m->n，当调用dfs(n)的时候，有如下两种情况：
1) dfs(m)还没有被调用，此时会调用dfs(m)，只有dfs(m)返回之后，dfs(n)才会返回
2) dfs(m)已经被调用过并返回了
（由于本图是DAG，所以不存在dfs(m)已经被调用，但是在dfs(n)被调用时还未返回的情况）
无论是以上哪一种情况，m都会先于n被添加到L中。所以对于任意边m->n，在L中，m总会在n前面。
本算法的复杂度为O(v + e)，需要注意的一些点是，本算法是建立在图为DAG的基础上的，当然，可以进行一些修改来做环路检测，另外， 本算法的起点是对每个出度为0的顶点进行dfs，而Kahn算法则是从每个入度为0的顶点出发。为何本算法需要从出度为0的顶点出发呢？因为出度为0的顶点必然排在最后面，而最先调用dfs的顶点最后才加入L中。
*/

