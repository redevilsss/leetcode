#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;
//187 �ظ���DNA����
/*
���� DNA ��һϵ����дΪ A��C��G �� T �ĺ�������ɣ����磺��ACGAATTCCG�������о� DNA ʱ��ʶ�� DNA �е��ظ�������ʱ����о��ǳ��а�����
��дһ������������ DNA ���������г��ֳ���һ�ε�10����ĸ�������У��Ӵ�����
ʾ�� :
����: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
��� : ["AAAAACCCCC", "CCCCCAAAAA"]
*/

//��������ҳ��ִ�������һ�ε�10����ĸ��������
/*
˼·1������ֱ�Ӹգ�����map�ļ�ֵ�Ի���set���ظ�Ԫ�ز���ʧ����ʵ��
��setΪ������������set����set1�в��벻��ȥ��ʱ����뵽set2����ô������ɺ�set2�б���ľ��ǳ��ֳ���һ�ε��ִ�
*/

vector<string> findRepeatedDnaSequences(string s) {
	if (s.length() < 10)
		return {};
	set<string> s1;
	set<string> s2;
	for (int i = 0; i<s.length()-9; i++)
	{
		string temp = s.substr(i,10);
		auto ret = s1.insert(temp);
		if (!ret.second)
			s2.insert(temp);
	}
	return vector<string>(s2.begin(),s2.end());
}

//������
/*
ǰ��ķ������ӶȺܸߣ��õ��˱Ƚϸ��ӵ����ݽṹ��Ч����õĴ������������ڻ����ķ���������
��Ϊֻ�����ֲ�ͬ�Ľṹ��������0 1 2 3�����棬Ҳ������λ����������ʾ����ô����Ϊ10�Ĵ�����Ҫ20λ�Ķ���������ʾ���ٶ���һ��1<<20λ����������ʾ������ʾ�������Ƿ����
�ȹ���һ����������ʾǰ10λ��Ȼ��ѱ�־�������Ի�����ǰֵΪ�±��λ�õ�ֵ��Ϊtrue
�������飬����ÿ�ƶ�һ�Σ���Ӧ�ַ����ĵ�һλҪȥ�������Ͻ�������һλ��������ֵҲ�ı�
ÿ�ζԵ�ǰ������ʾ�����ֽ����жϣ����Ϊtrue��˵��֮ǰ�Ѿ����ֹ���ֱ��insert,����ֵ��λtrue;
*/
int ctoi(char c)
{
	switch (c)
	{
		case 'A':return 0;
		case 'C':return 1;
		case 'G':return 2;
		case 'T':return 3;
	}
}

vector<string> findRepeatedDnaSequences(string s) {
	unordered_set<string> res;
	vector<bool> nums(1 << 20, false);
	int mask = 1 << 20 - 1;//���������룬����������20λ
	int temp = 0;
	//�����ʼ����
	for (int i = 0; i < 10; i++)
		temp = (temp << 2 | s[ctoi(i)]);
	nums[temp] = true;
	for (int i = 10; i < s.length(); i++)
	{
		temp = (temp << 2)&mask | s[ctoi(i)];//temp��������λ�͵�ǰ�ַ���ʾ�Ķ��������������mask��������������20λ��Ҳ����ÿ�μ���Ķ��ǵ�ǰ10���ַ���Ӧ��ֵ
		//��ǰλΪtrue,���룬��ϣ�������ظ�ֵ�ģ�ֻ�����һ��
		if (nums[temp])
			res.insert(s.substr(i - 9, 10));
		else
			nums[temp] = true;
	}
	return vector<string>(res.begin(), res.end());
}
int main()
{
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	findRepeatedDnaSequences(s);

	return 0;
}