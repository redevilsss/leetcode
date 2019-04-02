#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//56 �ϲ�����

/*
����һ������ļ��ϣ���ϲ������ص������䡣
ʾ�� 1:
����: [[1,3],[2,6],[8,10],[15,18]]
���: [[1,6],[8,10],[15,18]]
����: ���� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
ʾ�� 2:
����: [[1,4],[4,5]]
���: [[1,5]]
����: ���� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣
*/
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};

//˼·��Ҫ�ϲ��������Ƚ��������������������ֵ������
//��ôֻҪǰһ���������ֵ���ں�һ���������ֵ�����ܰ�����ϲ�
//���ǰһ���������ֵ�Ⱥ�һ���������ֵ���󣬻��ü�������
//ֱ���ҵ��Ǹ���ֵ�ȸղ��Ǹ�������ֵ������䣬���κϲ���ɣ����ϲ�����������������
//���ǰһ������ͺ�һ������û�н�������ֱ�ӽ�ǰһ���������������
vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> res;
	if (intervals.size() <= 1)
		return intervals;
	//���������䣬ֻҪ����ǰ���end���ڵ��ں����start����������Ϳ��Ժϲ�
	//����[a,b] [c,d]���Ժϲ���������a<c<=b<d��c<a<=d<b
	//�����a<c b<d��ֻҪc<=b�ɿ��Ժϲ�������������ܺ�ǰ��ĺϲ�����c>b,��������Ҳ���ܺϲ�����Ϊ���������start��c��������start>b
	sort(intervals.begin(), intervals.end(), [](Interval x, Interval y) {return x.start<y.start; });
	int i = 0;
	Interval temp = intervals[0];
	while (i<intervals.size())
	{

		if (i + 1<intervals.size() && temp.end >= intervals[i + 1].start)
		{
			if (temp.end<intervals[i + 1].end)//����ߵ���һ��������һ����i+1�����ѭ��ʱif�ǲ������ģ���Ϊ��ʱendС����һ����end��
											  //��С������һ����start�������elseֱ�ӽ��޸ĺ�������
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