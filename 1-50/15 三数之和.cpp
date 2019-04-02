#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//15 ����֮��
/*
����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��
ʹ�� a + b + c = 0 ���ҳ��������������Ҳ��ظ�����Ԫ�顣
ע�⣺���в����԰����ظ�����Ԫ�顣
����, �������� nums = [-1, 0, 1, 2, -1, -4]��
����Ҫ�����Ԫ�鼯��Ϊ��
[
[-1, 0, 1],
[-1, -1, 2]
]
*/

//����⵱ʱ�����˺ó�ʱ�䣬˼�����ȡ�̶�һ��������������֮�͵�������̶������෴��
//����Ӧ���Ǳ���ȡ��һ������Ȼ��ȡ�ڶ��������һ�����ƶ�ָ��ڶ��������һ������ִ��
//�ҳ�����
//������ȡ�˵�һ���������һ������ȡ�м���������������ܼӿ��ٶ�
//���������Ļ���һ�ְ������޷�ͨ����
//-2 -1 -1 1 1 2
//����õ�-2 1 1�����ò���1 1 -2����Ϊÿ�ζ�Ҫ�ƶ��±꣬���ַ�����©��һЩ���

//�ջ񣺶Զ�������б���ʱһ��Ҫ�в��
//���ȸ���Ҫ���費��Ҫ��������һ��һ������İ�����������һ���Ծ�Ϊ�˿��Լ�Ϲ��
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.size() < 3)
		return res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 2; i++)
	{
		//��Ϊ�����ֿ��ܻ����ظ����֣�������ظ����ֶ�����
		//�ظ�������Ҫ��������Ϊ���ظ�������ظ���
		if (i == 0 || nums[i] > nums[i - 1])
		{
			//ȡi���ұߺ�����ĩβ����ָ��
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				int s = nums[i] + nums[left] + nums[right];
				if (s == 0)
				{
					res.push_back(vector<int>{nums[i], nums[left], nums[right]});
					left++;
					right--;
					//�����ظ�Ԫ�أ������������ǰ�������������ͬ����˼
					//ǰ���������Ϊ�˱�����ͬ�ĵ�һ������������Ϊ�˱�����ͬ�ĵڶ�������
					while (left < right&&nums[left] == nums[left - 1])
						left++;
					while (left < right&&nums[right] == nums[right + 1])
						right--;
				}
				//����ʹ���0����Ҫ��С��ȡ����right����
				else if (s > 0)
					right--;
				else//������Ҫ������ȡ��left����
					left++;
			}
		}
	}

	return res;
}

int main()
{
	vector<int> nums = { -1,0,1,2,-1,-4 };
	vector<vector<int>> res = threeSum(nums);
	return 0;
}