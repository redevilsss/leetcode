#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<unordered_set>
#include<algorithm>
using namespace std;

//127 ���ʽ���
/*
�����������ʣ�beginWord �� endWord����һ���ֵ䣬�ҵ��� beginWord �� endWord �����ת�����еĳ��ȡ�ת������ѭ���¹���
ÿ��ת��ֻ�ܸı�һ����ĸ��
ת�������е��м䵥�ʱ������ֵ��еĵ��ʡ�
˵��:
���������������ת�����У����� 0��
���е��ʾ�����ͬ�ĳ��ȡ�
���е���ֻ��Сд��ĸ��ɡ�
�ֵ��в������ظ��ĵ��ʡ�
����Լ��� beginWord �� endWord �Ƿǿյģ��Ҷ��߲���ͬ��
ʾ�� 1:
����:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
���: 5
����: һ�����ת�������� "hit" -> "hot" -> "dot" -> "dog" -> "cog",
�������ĳ��� 5��
*/

//����һ��
//�þ�û�ù�ͼ�ˣ���ͼ��˼������,����ǿ�������Ѷ���.....
//��ͼ����ȻҪ4000ms...������
//������������е�ĳ��������ֻ��һ�����ʲ�һ����������������֮���б�
//��������ͼ���ڽӾ���֮��Ҫ���ľ����Ҵ���ʼ���ʵ���ֹ���ʵ���С·��

//�ڽӾ���
map<string,vector<string>> adj;
//�Ƚ����������Ƿ�֮��һλ
bool compare(string a, string b)
{
	int length = a.length();
	int dif = 0;//��ͬ�ַ���λ��
	for (int i = 0; i < length; i++)
		if (a[i] != b[i])
			dif++;
	return dif == 1;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	int length = wordList.size();
	//�ж��Ƿ���Ҫ�������У����endWord�����ֵ��У�˵���϶��Ҳ�����ֱ�ӷ���
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
	//�ж�beginWord�Ƿ����ֵ��У�������ھͼ���
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
	//�����ڽӾ���
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
	//������̾��룬��bfs
	queue<string> q;//����
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

//����������������һ��ɣ��ο����еĴ���
/*
* �ֱ��beginWord��endWord���������仯�������ܷ����м���ͷ
* �������һЩ���ٸ����ӣ���beginWordֻ��һλ��һ���ĵ�����100��������endWordֻ��һλ��һ���ĵ���ֻ��1��
* ��Ȼ�Ǵ�endWord������죬������100���������ĵ����й��жϵ�
* ����begin���ϣ�end���Ϻ�һ��temp����
* begin���ϼ�¼��ǰ�����ҵĹ�����ĳһ��ʱ��ǰ�ĵ��ʣ�end���ϼ�¼�Ӻ���ǰ�ҵĹ�����ĳһ��ʱ��ǰ�ĵ���
* temp��������¼����һ��ʱ�뵱ǰ���ʲ�һλ�ĵ��ʵļ���
* ÿһ������Ҫ�������������ϣ�begin��end�����ĸ����浥���پʹ��ĸ���
*/
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> wordDict(wordList.begin(), wordList.end());
	if (wordDict.find(endWord) == wordDict.end())
		return 0;//�ֵ���û��endWord���϶��Ҳ���
	unordered_set<string> beginSet{ beginWord };
	unordered_set<string> endSet{ endWord };
	int step = 1;
	while (!beginSet.empty())
	{
		unordered_set<string> tempSet;
		step++;
		//���ֵ��аѵ�ǰbeginSet�����е��ַ���ɾ������Ϊ��ʱ��Щ�ַ����Ѿ�û���ˣ����ǻ�Ӱ�����Ч��
		for (string s : beginSet)
			wordDict.erase(s);
		//�Ե�ǰbegin�����е�ÿһ�����ʵ�ÿһλ��ν����޸�
		//���統ǰbegin��������hot���Ƿֱ�����ֵ�����û��aot bot ... zot hat hbt hzt...hoa hob...hoz
		//������ǾͰѵ��ʷŽ�ȥ
		//���ַ����þͺ��ڲ��ù˼��ֵ��������������һλ���ж��٣��Ҿ�һ��һ���ԣ�Ч�ʷ�������
		//��Ϊ���õ��Ķ��ǽ�Ϊ�򵥵����ݽṹ���õ�����Ҳ���Ǽ򵥵ķ���
		for (string s : beginSet)
		{
			//��ÿ�����ʵ�ÿһλ�������޸ĳ���
			for (int i = 0; i < s.size(); i++)
			{
				string str = s;
				for (char c = 'a'; c <= 'z'; c++)
				{
					str[i] = c;
					//����Ҳ����ͼ�����һ��
					if (wordDict.find(str) == wordDict.end())
						continue;
					//�����end�������ҵ���˵����ʱstep�������貽��
					//step���ȼ����жϵģ���ʼ����Ϊ1�ˣ�����������Ľ������step
					if (endSet.find(str) != endSet.end())
						return step;
					tempSet.insert(str);
				}
			}
		}
		//����������һ�����ܱ�ɵĵ��ʺ��жϵ�ǰtemp���Ϻ�end�����ĸ������temp����С
		//����begin����ȡtemp���ϼ�������
		if (tempSet.size() < endSet.size())
			beginSet = tempSet;
		//���temp����Ԫ�ض࣬�Ǿ���endSet��Ϊ�µ�begin����ȥ�����������޸����Ƶ�����Ҳ�������õ�����Ϊ���Լ��ٴ��븴д
		//����endSet����Ϊtemp���ϣ���һ������µ�temp���ϱ�end����(�����begin����)�࣬�Ǿ��ٻ�����

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

