#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//219 �����ظ�Ԫ��2

/*
����һ�����������һ������ k���ж��������Ƿ����������ͬ������ i �� j��ʹ�� nums [i] = nums [j]������ i �� j �Ĳ�ľ���ֵ���Ϊ k��
ʾ�� 1:
����: nums = [1,2,3,1], k = 3
���: true
*/

//����һ�����ù�ϣ����ʵ��
//��ȻҪ�Ƚ���ͬԪ���±�����Ҫ�����ֵ�ԣ�key��ֵ��value���±꣬ѡ��hashmap��ʵ��
//�������飬ÿһ��ͨ��count������鵱ǰhsahmap����û�е�ǰԪ��
//����У����жϵ�ǰ�±����һ����ͬԪ�ص��±���ǲ���С�ڵ���k������������������㣬����true
//���򽫵�ǰ��(nums[i],i)��ֵ�Բ��룺֮ǰ����м�nums[i]������£����û�У��Ͳ���
bool containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_map<int, int> record;//ֵ���±�
	for (int i = 0; i<nums.size(); i++)
	{
		if (record.count(nums[i]) && (i - record[nums[i]]) <= k)
			return true;
		else
			record[nums[i]] = i;
	}
	return false;
}

//��������������
/*
ͨ��������ʵ�֣���������������|i-j|<k,��ʵ���Ը���Ϊi-j<k
����ά��һ������Ϊk�Ļ�����ÿ���ڵ�ǰ�����в��һ����ұ߽��Ҳ�Ԫ��
����Ҫ���쳤��Ϊ2k+1�Ļ���(�Ե�ǰ�ڵ�Ϊ�е�)����Ϊ������ܻ�������ģ�����Ϊk����
��Ϊ��ǰԪ��nums[i]���±�i�ͻ����е�Ԫ���±�j����i-j<k��Ҳ����˵���������в������Ԫ���Ƿ��ظ�ʱ��ֻ��Ҫ��������������Ƿ����nums[i]����
�������£�
1.�ѻ�����߽�����һλ����ʱ�������ȱ�Ϊk-1
2.�ڻ����в���Ԫ��nums[i]������ҵ��ͷ���true
3.�Ҳ����Ͱ��ұ߽�����һλ����nums[i]
4.�ظ���������ֱ���������
*/
bool containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_set<int> s;
	for (int i = 0; i<nums.size(); i++)
	{
		//�������������һλ
		if (i>k)
			s.erase(nums[i - k - 1]);
		//���ҵ�ǰ����������ֵ����nums[i]��Ԫ��
		if (s.find(nums[i]) != s.end())
			return true;
		//�����ұ�����һλ��ʵ�ֻ����ƶ�
		s.insert(nums[i]);
	}
	return false;
}
int main()
{
	vector<int> vec = { 1,2,3,1 };
	bool res = containsNearbyDuplicate(vec, 3);
	return 0;
}