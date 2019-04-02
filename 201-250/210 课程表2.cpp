#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
//210 �γ̱�2
/*
˼·�����ϺͿγ̱�1һ��
����һ����������γ̺ŵ��������
�������Ҫ�����жϣ�������鳤�Ⱦ͵���numCourse�����ط�ת�������
ΪʲôҪ��ת���飿��Ϊ��Ŀ���[a,b]��ʾ������ѧϰa����ѧb������˳��Ӧ����b a
�������ת����������˳���Ǻ�ѧϰ��˳���෴��
���򷵻ؿգ���Ϊ��ʱ����������пγ�
*/

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<int> inDegree(numCourses, 0);//����ÿ���ڵ�����
	list<int> *pList = new list<int>[numCourses];//�ڽӱ�
	queue<int> q;//���ڽ�����������Ķ���

	for (pair<int, int> i : prerequisites)
	{
		//���¶���i.first���ڽӾ���Ϊ����ߣ���ֻ����first->second
		pList[i.first].push_back(i.second);
		inDegree[i.second]++;//������ߵ��յ���ȼ�1
	}
	//������������
	for (int i = 0; i<numCourses; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);//���������Ϊ0�ĵ���±������
	}
	vector<int> res;//��¼��������ǰΪֹ��ɵĿγ�
	int count = 0;//��¼��ǰΪֹ��ɵĿγ���
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		res.push_back(v);//�ڵ�������
		count++;//��ɿγ�����1
		//��v�ڵ���ڽӱ�ÿһ��Ԫ����ȼ�1�����൱��ȥ����v�ڵ�
		for (auto it = pList[v].begin(); it != pList[v].end(); it++)
		{
			inDegree[*it]--;//��ȼ�1
							//�����ʱ�ڵ�i���Ϊ0��������Ϊ��㣬����������
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