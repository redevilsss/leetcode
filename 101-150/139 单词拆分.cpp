#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

//139 ���ʲ��

/*
����һ���ǿ��ַ��� s ��һ�������ǿյ����б���ֵ� wordDict���ж� s �Ƿ���Ա��ո���Ϊһ���������ֵ��г��ֵĵ��ʡ�
˵����
���ʱ�����ظ�ʹ���ֵ��еĵ��ʡ�
����Լ����ֵ���û���ظ��ĵ��ʡ�
ʾ�� 1��
����: s = "leetcode", wordDict = ["leet", "code"]
���: true
����: ���� true ��Ϊ "leetcode" ���Ա���ֳ� "leet code"��
*/

//�ö�̬�滮���������
//����һ������Ϊn+1�����飬������ĵ�iλ������ʾ�ַ�����ǰi���ַ��ܷ񱻲���ֵ��е�Ԫ��
bool wordBreak(string s, vector<string>& wordDict) {
	vector<bool> dp(s.size() + 1, false);
	//�ù�ϣ����Ϊ�в��ҹ��ܣ��س������Ӵ��ҿ���ֱ���ù�ϣ�������ҿ���û����֮��ȵĵ���
	unordered_set<string> m(wordDict.begin(), wordDict.end());
	dp[0] = true;//dp[0]��Ϊtrue
	//�����ַ���������dp����
	//��������ʵ����Ż�������ֵ�������ʳ���Ϊl����Ŀǰ�±�Ϊi��ʱ���ҵ�jֻ��Ҫ��i-l��l��������
	//��Ϊ��ʱ���i��0~i-l֮�䣬��ȡ����i-j�Ǵ���l�ģ�Ҳ����˵�����ܴ���ƥ��ĵ���
	//������Ҫȷ����ǰ�ֵ�������ʵĳ����Ƕ���
	int maxWordLength = 0;
	for (int i = 0; i < wordDict.size(); ++i) {
		maxWordLength = max(maxWordLength, (int)wordDict[i].size());
	}
	//��ʼ����
	for (int i = 1; i <= s.size(); i++)
	{
		for (int j = max(0, i-maxWordLength); j<i; j++)
			//substr(j, i-j)��ʾ��j�𣬳���Ϊi-j������ܲ鵽��˵���±�j��i���ַ������ֵ��еĵ���
			//����dp[i]��break����������
			if (dp[j] && m.find(s.substr(j, i-j)) != m.end())
			{
				dp[i] = true;
				break;
			}
	}
	return dp[s.size()];
}

int main()
{
	vector<string> wordDict = { "leet","code" };
	string s = "leetcode";
	bool res=wordBreak(s, wordDict);
	return 0;
}