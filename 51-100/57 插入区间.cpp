#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//57 ��������

/*
����һ�����ص��� ������������ʼ�˵�����������б�
���б��в���һ���µ����䣬����Ҫȷ���б��е�������Ȼ�����Ҳ��ص�������б�Ҫ�Ļ������Ժϲ����䣩��
ʾ�� 1:
����: intervals = [[1,3],[6,9]], newInterval = [2,5]
���: [[1,5],[6,9]]
*/

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};

//������ѶȲ��󣬵��ǿ�������һ��Ҫȫ�棬���ȶ�ԭ���䰴����ֵ��С����
//���������⼸�������������
//1.���������ֵС������ԭ�������ֵ����ʱֱ�ӽ�������ӵ�ԭ������ǰ�漴��
//2.���������ָ��������ԭ�������ֵ����ʱֱ�ӽ�������ӵ�ԭ���������
//3.��������ԭ�����м�ĳ��λ�ã�����û���غϲ��֣�ֱ�Ӳ����ڸ�λ��
//4.��������ԭ�����м�ĳ��λ�������غϲ��֣��ҵ�������ɵĴ����䣬���Ĵ��������ֵ������������ֵ�͵�һ�������������غϵ�ԭ������ֵ���ߵĽ�Сֵ
//���Ĵ��������ֵ������������ֵ�͵�һ�������������غϵ�ԭ������ֵ���ߵĽ�Сֵ
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval> res;
	if (intervals.size() == 0)
	{
		res.push_back(newInterval);
		return res;
	}
	//��������ͷ��С����
	sort(intervals.begin(), intervals.end(), [](Interval x, Interval y) {return x.start<y.start; });
	//��ʱ�������ڵ�һ����ǰ�棬ֱ�ӷŽ�ȥ����ԭ�������鸴��
	if (intervals[0].start>newInterval.end)
	{
		res.push_back(newInterval);
		for (int i = 0; i<intervals.size(); i++)
			res.push_back(intervals[i]);
		return res;
	}
	//˵���ڵ�һ���ĺ��棬�ȸ������������ҵ�������ϲ��޹ص�ǰ������䲢����
	int i = 0;
	while (i<intervals.size() && intervals[i].end<newInterval.start)
	{
		res.push_back(intervals[i]);
		i++;
	}
	//����������䶼��ϲ��޹أ���˵���������start����ԭ������������ֵ��ֱ�ӷŵ�����β������
	if (i == intervals.size())//˵���µ����䵥�������
		res.push_back(newInterval);
	else
	{
		Interval temp = intervals[i];
		//��ʱ��������ԭ������ĵ�i������͵�i+1������֮�䣬û���غϲ���
		if (temp.start>newInterval.end)
		{
			res.push_back(newInterval);
			res.push_back(temp);
		}
		else
		{
			//ȡ�����串�ǵ����ֵ
			temp.start = min(intervals[i].start, newInterval.start);
			//�������串�ǵ��յ㣬Ҳ��������������������غϵ����һ�����鲢�޸��µĴ����������ֵ
			while (i + 1<intervals.size() && intervals[i].end<newInterval.end&&intervals[i + 1].start <= newInterval.end)
				i++;
			temp.end = max(intervals[i].end, newInterval.end);
			res.push_back(temp);
		}
		//��ʣ��������д���
		for (int j = i + 1; j<intervals.size(); j++)
			res.push_back(intervals[j]);
	}

	return res;
}

int main()
{
	vector<Interval> vec;
	vec.push_back(Interval(3, 5));
	vec.push_back(Interval(12, 15));
	//vec.push_back(Interval(6, 11));
	//vec.push_back(Interval(8, 10));
	//vec.push_back(Interval(12, 16));
	Interval newInterval(6, 6);
	vector<Interval> res = insert(vec, newInterval);
	return 0;
}