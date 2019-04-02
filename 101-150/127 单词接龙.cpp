#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<unordered_set>
#include<algorithm>
using namespace std;

//127 单词接龙
/*
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:
如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
输出: 5
解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
返回它的长度 5。
*/

//方法一：
//好久没用过图了，用图的思想做吧,这算强行增加难度吗.....
//用图做果然要4000ms...哈哈哈
//如果单词数组中的某两个单词只有一个单词不一样，那这两个单词之间有边
//构造出这个图的邻接矩阵之后，要做的就是找从起始单词到终止单词的最小路径

//邻接矩阵
map<string,vector<string>> adj;
//比较两个单词是否之差一位
bool compare(string a, string b)
{
	int length = a.length();
	int dif = 0;//不同字符的位数
	for (int i = 0; i < length; i++)
		if (a[i] != b[i])
			dif++;
	return dif == 1;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	int length = wordList.size();
	//判断是否需要继续进行，如果endWord不在字典中，说明肯定找不到，直接返回
	int index = 0;
	while (index < length)
	{
		if (wordList[index] != endWord)
			index++;
		else
			break;
	}
	if (length == 0 || index == length)
		return 0;
	//判断beginWord是否在字典中，如果不在就加入
	index = 0;
	while (index < length)
	{
		if (wordList[index] != beginWord)
			index++;
		else
			break;
	}
	if (index == length)
	{
		wordList.push_back(beginWord);
		length += 1;
	}
	//构造邻接矩阵
	for (int i = 0; i < length; i++)
	{
		for (int j = i+1; j < length; j++)
		{
			if (compare(wordList[i], wordList[j]))
			{
				adj[wordList[i]].push_back(wordList[j]);
				adj[wordList[j]].push_back(wordList[i]);
			}
		}
	}
	//计算最短距离，用bfs
	queue<string> q;//队列
	map<string, int> distance;
	distance[beginWord] = 1;
	q.push(beginWord);
	while (!q.empty())
	{
		string curStr = q.front();
		q.pop();
		vector<string> curAdj = adj[curStr];
		for (int i = 0; i < curAdj.size(); i++)
		{
			if (endWord == curAdj[i])
				return distance[curStr] + 1;
			if (!distance.count(curAdj[i]))
			{
				distance[curAdj[i]] = distance[curStr] + 1;
				q.push(curAdj[i]);
			}
		}
	}
	return 0;
}

//方法二：还是正常一点吧，参考大佬的代码
/*
* 分别从beginWord和endWord出发，看变化过程中能否在中间碰头
* 这样会快一些，举个例子，和beginWord只有一位不一样的单词有100个，而和endWord只有一位不一样的单词只有1个
* 当然是从endWord出发会快，否则这100个接下来的单词有够判断的
* 定义begin集合，end集合和一个temp集合
* begin集合记录从前往后找的过程中某一步时当前的单词，end集合记录从后往前找的过程中某一步时当前的单词
* temp则用来记录走下一步时与当前单词差一位的单词的集合
* 每一步都需要更新这三个集合，begin和end集合哪个里面单词少就从哪个走
*/
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> wordDict(wordList.begin(), wordList.end());
	if (wordDict.find(endWord) == wordDict.end())
		return 0;//字典里没有endWord，肯定找不到
	unordered_set<string> beginSet{ beginWord };
	unordered_set<string> endSet{ endWord };
	int step = 1;
	while (!beginSet.empty())
	{
		unordered_set<string> tempSet;
		step++;
		//在字典中把当前beginSet集合中的字符串删掉，因为此时这些字符串已经没用了，但是会影响查找效率
		for (string s : beginSet)
			wordDict.erase(s);
		//对当前begin集合中的每一个单词的每一位逐次进行修改
		//比如当前begin集合中有hot，那分别查找字典里有没有aot bot ... zot hat hbt hzt...hoa hob...hoz
		//如果有那就把单词放进去
		//这种方法好就好在不用顾及字典里和这个单词里差一位的有多少，我就一个一个试，效率反而不低
		//因为我用到的都是较为简单的数据结构，用到方法也都是简单的方法
		for (string s : beginSet)
		{
			//对每个单词的每一位都进行修改尝试
			for (int i = 0; i < s.size(); i++)
			{
				string str = s;
				for (char c = 'a'; c <= 'z'; c++)
				{
					str[i] = c;
					//如果找不到就继续下一个
					if (wordDict.find(str) == wordDict.end())
						continue;
					//如果在end集合里找到，说明此时step就是所需步数
					//step是先加再判断的（初始就设为1了），所以这里的结果就是step
					if (endSet.find(str) != endSet.end())
						return step;
					tempSet.insert(str);
				}
			}
		}
		//好了找完下一个可能变成的单词后，判断当前temp集合和end集合哪个大，如果temp集合小
		//就让begin集合取temp集合继续遍历
		if (tempSet.size() < endSet.size())
			beginSet = tempSet;
		//如果temp集合元素多，那就让endSet作为新的begin集合去遍历，这里修改名称的做法也经常能用到，因为可以减少代码复写
		//而将endSet更新为temp集合，下一步如果新的temp集合比end集合(这里的begin集合)多，那就再换回来

		else
		{
			beginSet = endSet;
			endSet = tempSet;
		}
	}
	return 0;
}



int main()
{
	vector<string> vec = { "hot", "dot", "dog", "lot", "log", "cog" };
	string begin = "hit";
	string end = "cog";
	int res = ladderLength(begin, end, vec);
	return 0;
}

