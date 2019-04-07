#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>
#include<unordered_map>
using namespace std;

//315 �����Ҳ�С�ڵ�ǰԪ�صĸ���

/*
����һ���������� nums����Ҫ�󷵻�һ�������� counts������ counts �и����ʣ� counts[i] ��ֵ��  nums[i] �Ҳ�С�� nums[i] ��Ԫ�ص�������
ʾ��:
����: [5,2,6,1]
���: [2,1,1,0]
����:
5 ���Ҳ��� 2 ����С��Ԫ�� (2 �� 1).
2 ���Ҳ���� 1 ����С��Ԫ�� (1).
6 ���Ҳ��� 1 ����С��Ԫ�� (1).
1 ���Ҳ��� 0 ����С��Ԫ��.
*/

//�����鵽���ӿ϶������ñ�������
/*
�����кܶ�ܶ࣬����ѡȡ�鲢˼�롢��״����Ͷ������������ַ�������
���Ӷȶ���o(nlogn)
*/
//����һ���鲢������
/*
����Ԫ��ֵ���±�ļ�ֵ������nums��Ԫ��ֵ���ڱȽϣ��±귽�����Ԫ�ظ���
����ans������¼�����������Ϊ���յ����
�鲢˼�룬�Ȱ�������ַָ�ֱ��ÿ��������ֻ��һ��Ԫ�أ�Ȼ�������������鲢���򣬱�����߸����������
Ҫע����ǣ������������һ�����飬��������ָoffer51��һ��ֻ��Ҫ�������ɣ���������һ��Ҫ����Ԫ�غ��±������
��Ϊ�ڹ鲢������Ԫ�ص�λ�ûᷢ���仯��ֻ��ά����������ԣ����ܱ�֤���հ����ӵ����ʵ�λ��
����Ԫ�ص�λ���ڱ䣬���±�û�䣬��ô�ڼӵ�ʱ��ͻ�ӵ������λ��

��Ҫ������ô֪����...�Գ�����

��¼�ķ���Ϊ������ָ��i��j�ֱ�ָ��ǰһ��ͺ�һ���β(ǰһ��ͺ�һ���������)��ʼ����
������nums[i].first>nums[j].first��ʱ��˵����ʱ�Ӻ�һ�뿪ʼ���±�j����Ԫ�ض���nums[i].first�������򣬽�������Ӹ�ans[nums[i].second]
�ٽ�ֵ���븨������copy�У����nums[i].first<nums[j].first����˵��û������ֱ�ӷŵ�copy�м���

��������copy���������nums��������Ľ��
*/
void mergeSort(vector<pair<int, int>>& nums, vector<pair<int, int>>& copy, int start, int end, vector<int> &ans)
{
	if (start == end)
	{
		copy[start] == nums[start];
		return;
	}
	int len = (end - start) / 2;
	mergeSort(copy, nums, start, start + len, ans);
	mergeSort(copy, nums, start + len + 1, end, ans);

	//�����ӹ鲢����
	int i = start + len;
	int j = end;
	int indexCopy = end;
	int count = 0;
	while (i >= start&&j >= start + len + 1)
	{
		//��ʱ��������ԣ����ϴ���������������鲢�ӽ��������ӵ����ʵ�λ��
		if (nums[i].first > nums[j].first)
		{
			ans[nums[i].second] += j - start - len;
			copy[indexCopy--] = nums[i];
			i--;
		}
		else
		{
			copy[indexCopy--] = nums[j--];
		}

	}
	for (; i >= start; --i)
		copy[indexCopy--] = nums[i];
	for (; j >= start + len + 1; --j)
		copy[indexCopy--] = nums[j];
}
vector<int> countSmaller(vector<int>& nums) {
	if (nums.size() == 0) return {};
	int len = nums.size();
	vector<pair<int, int>> vec;
	for (int i = 0; i < len; i++) 
		vec.push_back(make_pair(nums[i], i));
	vector<int> ans(len, 0);
	vector<pair<int, int>> copy(vec);
	mergeSort(vec, copy, 0, len-1, ans);
	return ans;
}

//������������״��������
/*
���ǿ�youtube��һ�����е�����...��֮������������е��Ѷȣ�Ϊʲô��ô��������ȫ�㶮�����Ǻ�����
���Ⱦٸ����� 5��2��6��1
���ĸ��������Ȱ����鵹�������1 6 2 5��ΪʲôҪ��������
��Ϊ�����������Ԫ��ֵ�õ�������״���飬��״���������ǰ׺�ͣ�
Ҳ����˵�ҹ�����״����������iλ��ֵ��ʾ���Ǵ�k(��Ҳ��֪��k�Ƕ��٣���������0~i֮��)��i-1������С�ڵ�ǰ���ĸ���
�����Ұ����鵹��������Ϊ�˺������㣬�������ս���ٵ�������

Ȼ������Ҫ����������������� Ҳ����˵������һ������sorted��1 4 2 3
ÿһλ����ԭ�����Ӧ��Ԫ���������е�����(�ظ�Ԫ��������ͬ)�������Ӧ��ϵ��һ����ϣ����ά��
��ϣ��ļ�ֵ�Դ洢��Ԫ�����������Ĺ�ϵ
��ranks���鱣����<1,1>��<6,4>��<2,2>��<5,3>���ĸ���ֵ��
������״����tree����ʼֵΪȫ0

���������Ĺ�����ʵ����Ԫ�ز�����״����Ĺ���
�����һ����(Ҳ���������ĵ�һ����)��ʼ����
nums[i]�������size-i��ranks[nums[i]]��ʾ�������������е�����
query(ranks[nums[i]]-1)���ǲ��ҵ�ǰ������λ�ڸ����Ҳ�������бȵ�ǰ��С��Ԫ�ظ���
���Ž���״�����ranks[nums[i]]�����ڵ��·��Ԫ�ض���1

��ʵ���ﱾ���Ĳ����������ģ�
������Ϊ��
����һ�� 0 0 0 0 0����
���ν�nums[i]Ԫ�ز����������ranks[nums[i]]λ��
��һ�� ��1�����±�1����һ��λ��+1  0 1 0 0 0 �ڵ�һλ֮ǰ����0��Ԫ��
�ڶ��� ��6�����±�4�����ĸ�λ��+1  0 1 0 0 1 �ڵ���λ֮ǰ����1��Ԫ��
������ ��2�����±�2���ڶ���λ��+1  0 1 1 0 0 �ڵڶ�λ֮ǰ����1��Ԫ��
���Ĳ� ��5�����±�3��������λ��+1  0 1 1 1 1 �ڵ���λ֮ǰ����2��Ԫ��
�õ���2 1 1 0�������Ľ��

�������״����������þ�����ǰranks[nums[i]]-1���
Ϊ�˽�������̵ĸ��ӶȽ�Ϊo(logn)
����ΪʲôҪ���������Ҳ����Ϊ����״��������ܷ��㣬��Ϊ������״������Ժܷ���ĸ��º���ǰ׺��
*/
class FenwickTree {
public:
	FenwickTree(int n) :sums(n + 1, 0) {};
	//��������Ԫ�أ��ӵ�ǰԪ�ص����ڵ�ȫ������
	void update(int i, int val)
	{
		while (i < sums.size())
		{
			sums[i] += val;
			i += lowbit(i);
		}
	}
	//����ǰi��ĺ�
	int query(int i) const
	{
		int sum = 0;
		while (i > 0)
		{
			sum += sums[i];
			i -= lowbit(i);
		}
		return sum;
	}
private:
	static inline int lowbit(int x) { return x&(-x); }
	vector<int> sums;

};

vector<int> countSmaller1(vector<int>& nums)
{
	//�������е�Ԫ��ֵ������
	set<int> sorted(nums.begin(), nums.end());
	//����һ����ϣ�����洢Ԫ�ص�ֵ-Ԫ���������е���λ�ļ�ֵ��
	unordered_map<int, int> ranks;
	int rank = 0;
	for (const int num : sorted)
		ranks[num] == ++rank;

	vector<int> ans;
	FenwickTree tree(ranks.size());
	//�����������
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		//���������Ҳ��ж������ֱȵ�ǰ������С
		//ǰ�����������һ���൱�ڸ�ǰranks[nums[i]]-1�����
		ans.push_back(tree.query(ranks[nums[i]] - 1));
		//������״�����е�ǰԪ����λ�����ڵ��·��Ԫ�ص�ֵ
		//ǰ���������ʵ�����ڸ���ranks[nums[i]]λ��1����Ϊ��״���鱣����ǲ��ֺͣ���������λ������λ�ô���Ҫ+1
		tree.update(ranks[nums[i]], 1);
	}
	//��ת�õ����ս��
	reverse(ans.begin(), ans.end());
	return ans;
}

/*
int main()
{
	vector<int> nums = { 2,0,1 };
	vector<int> res = countSmaller(nums);
	return 0;
}
*/