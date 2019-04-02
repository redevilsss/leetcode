#include<iostream>
#include<vector>
#include<algorithm>
#include<xfunctional>
#include<queue>
using namespace std;

//295 ����������λ��
/*
��λ���������б��м����������б�����ż������λ�������м���������ƽ��ֵ��
���磬
[2,3,4] ����λ���� 3
[2,3] ����λ���� (2 + 3) / 2 = 2.5
���һ��֧���������ֲ��������ݽṹ��
void addNum(int num) - �������������һ�����������ݽṹ�С�
double findMedian() - ����Ŀǰ����Ԫ�ص���λ����
ʾ����
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2
*/


//������һ��û����������顢��������顢���������������������AVL�������Ѻ���С�Ѽ��ֲ�ͬ�����ݽṹ��ʱ�临�Ӷ�
/*
*				���ݽṹ			�����ʱ�临�Ӷ�				�õ���λ����ʱ�临�Ӷ�
*				û�����������			O(1)								O(n)
*               ���������				O(n)								O(1)
*               ���������				O(n)								O(1)
*				����������			ƽ��O(logn)���O(n)				ƽ��O(logn)���O(n)
*				AVL��					O(logn)								O(1)
*				���Ѻ���С��			O(logn)								O(1)
*/

//˼·����һ������ʵ�ֽ�С��һ������������������һ����С��ʵ�ֽϴ��һ��������������
//ע�⣺
//��֤����ƽ�����䵽�������У�������������Ŀ֮��ܳ���1
//Ϊʵ��ƽ�����䣬��������ĿΪż��ʱ�������ݲ�����С�ѣ������������
//�����������ĿΪż����������Ҫ�嵽��С�ѣ�����������ݱ����ѵ�һЩ����С��ô�죿
//�Ȳ������ѣ�Ȼ������ѵ���������ó���������С�ѣ���֮��Ȼ


//��vector��Ϊ�������ڲ��������ÿ�ν��ж�����֤˳��
//Ҳ����ֱ�������ȶ��У������ȶ��еĻ��ǲ��������
class MedianFinder {
	vector<int> _min;
	vector<int> _max;
public:
	//ά��һ�����Ѻ���С�ѣ���С��������һ����������������������
	//��������Ϊż��ʱ�������ݻᱻ���뵽��С���У�������Ϊ��������ô��ʱ��λ��������С�ѵ�ͷ
	//����Ϊ����ʱ�������ݲ��뵽���ѣ�������Ϊż������λ���������Ѻ���С�ѵ�ͷԪ�ص�ƽ����
	/** initialize your data structure here. */
	MedianFinder() {

	}
	void addNum(int num) {
		if (((_min.size() + _max.size()) & 1) == 0)
		{
			//��ʱ����Ϊż������˵Ӧ�ò��뵽��С�ѣ����������ʱ��Ԫ�ر����ѵ�ͷԪ��С������Ҫ�����Ԫ�ز��뵽���ѵĺ���λ��
			//Ȼ�������ͷԪ���ó����ŵ����뵽��С��ȥ���������ܱ�֤��С�ѵ�����һ��������������ͷԪ�أ����ܱ�֤��ǰ��С�ѵ�ͷԪ�ؾ�����λ��
			if (_max.size()>0 && num<_max[0])
			{
				_max.push_back(num);
				//�Ե�ǰ����Ԫ�ؽ��н��������
				push_heap(_max.begin(), _max.end(), less<int>());
				//�������ѵ�ͷԪ��
				num = _max[0];
				//��begin�ƶ�����һ�����Ԫ�غ��棬ͬʱ��ʣ�µ�Ԫ�����¹����һ���µ�heap
				pop_heap(_max.begin(), _max.end(), less<int>());
				//�������е�ͷԪ�ص���
				_max.pop_back();
			}
			//num=max(_max[0],num)
			//��num������С�Ѳ��������򣬴�ʱ��λ������num
			_min.push_back(num);
			push_heap(_min.begin(), _min.end(), greater<int>());
		}
		//����ǰ����Ϊ����ʱ�������ݲ��뵽���ѣ��������ݿ��ܱ���С�����������������������
		//��С�ѵ�ͷԪ���ó������������ݲ��뵽��С�ѵĶ�Ӧλ��
		//�ٰ���С�ѵ�ͷԪ�ز������ѣ������¶�����
		else
		{
			if (_min.size()>0 && _min[0]<num)
			{
				_min.push_back(num);
				//�Ե�ǰ����Ԫ�ؽ������������
				push_heap(_min.begin(), _min.end(), greater<int>());
				//������С�ѵ�ͷԪ��
				num = _min[0];
				//��begin�ƶ�����һ�����Ԫ�غ��棬ͬʱ��ʣ�µ�Ԫ�����¹����һ���µ�heap
				pop_heap(_min.begin(), _min.end(), greater<int>());
				//����С���е�ͷԪ�ص���
				_min.pop_back();
			}
			//num=min(_min[0],num)
			//��num�������Ѳ��������򣬴�ʱ��λ������(_min[0]+_max[0])/2
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
	//ά��һ�����Ѻ���С�ѣ���С��������һ����������������������
	//��������Ϊż��ʱ�������ݻᱻ���뵽��С���У�������Ϊ��������ô��ʱ��λ��������С�ѵ�ͷ
	//����Ϊ����ʱ�������ݲ��뵽���ѣ�������Ϊż������λ���������Ѻ���С�ѵ�ͷԪ�ص�ƽ����
	/** initialize your data structure here. */
	MedianFinder() {

	}
	void addNum(int num) {
		if (big_heap.size() == small_heap.size())
		{
			//��ʱ����Ϊż������˵Ӧ�ò��뵽��С�ѣ����������ʱ��Ԫ�ر����ѵ�ͷԪ��С������Ҫ�����Ԫ�ز��뵽���ѵĺ���λ��
			//Ȼ�������ͷԪ���ó����ŵ����뵽��С��ȥ���������ܱ�֤��С�ѵ�����һ��������������ͷԪ�أ����ܱ�֤��ǰ��С�ѵ�ͷԪ�ؾ�����λ��
			if (big_heap.size()>0 && num<big_heap.top())
			{
				big_heap.push(num);
				num = big_heap.top();
				big_heap.pop();
			}
			small_heap.push(num);
		}
		//����ǰ����Ϊ����ʱ�������ݲ��뵽���ѣ��������ݿ��ܱ���С�����������������������
		//��С�ѵ�ͷԪ���ó������������ݲ��뵽��С�ѵĶ�Ӧλ��
		//�ٰ���С�ѵ�ͷԪ�ز������ѣ������¶�����
		else
		{
			if (small_heap.size()>0 && small_heap.top()<num)
			{
				small_heap.push(num);
				//������С�ѵ�ͷԪ��
				num = small_heap.top();
				//����С���е�ͷԪ�ص���
				small_heap.pop();
			}
			//num=min(_min[0],num)
			//��num�������Ѳ��������򣬴�ʱ��λ������(_min[0]+_max[0])/2
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