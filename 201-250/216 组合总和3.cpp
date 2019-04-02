#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//216 ����ܺ�3

/*
�ҳ��������֮��Ϊ n �� k ��������ϡ������ֻ������ 1 - 9 ��������������ÿ������в������ظ������֡�
˵����
�������ֶ�����������
�⼯���ܰ����ظ�����ϡ�
ʾ�� 1:
����: k = 3, n = 7
���: [[1,2,4]]
*/


/*
���͵Ļ��ݵݹ�����
�ڽ���ݹ�ǰ��Ҫע��ļ��㣺
һ.��������������������������
1.���֮��Ϊn��ͨ���ڵݹ�������rest���������浱ǰʣ��ͣ���ʣ���С��0ʱ������
2.k������ͨ������ʱ����temp��Ԫ�ظ��������жϣ�����֤ÿ������г���k��������temp.size()����kʱ����
3.���ظ���ͨ������index��ʵ�֣���֤���������һ����ʱ�Ǵӵ�ǰtemp.back����+1��ʼ����
4.ֻ����1-9���������ݹ�������ѭ����1-9
��.�ݹ��Ƴ�����
1.��temp.size()>k��n<0ʱ���˳�
2.��temp.size()==k��nǡ��Ϊ0ʱ�����浱ǰ��temp���˳�
*/
vector<vector<int>> res;
vector<vector<int>> combinationSum3(int k, int n) {
	vector<int> temp;
	dfs(1, k, n, temp);
	return res;
}
//index������¼��һ����������λ�ã��������ܱ���Ԫ���ظ�
//rest������¼��ǰ��ʣ���
//k��������ÿ����ϵĸ���
void dfs(int index, int k, int& rest, vector<int>& temp)
{
	if (temp.size()>k || rest<0)
		return;
	if (temp.size() == k&&rest == 0)
	{
		res.push_back(temp);
		return;
	}
	for (int i = index; i <= 9; i++)
	{
		temp.push_back(i);
		rest -= i;
		dfs(i + 1, k, rest, temp);
		temp.pop_back();
		rest += i;
	}
}