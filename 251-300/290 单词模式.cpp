#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
#include<string>
using namespace std;

//290 ����ģʽ

/*
����һ�� pattern(ģʽ) ��һ���ַ��� str ���ж� str �Ƿ���ѭ��ͬ��ģʽ��
�������ѭָ��ȫƥ�䣬���磬 pattern ���ÿ����ĸ���ַ��� str �е�ÿ���ǿյ���֮�������˫�����ӵĶ�Ӧģʽ��
ʾ��1:
����: pattern = "abba", str = "dog cat cat dog"
���: true
*/

//����һ���Լ�����������
//���Ȱ�str�ַ����ָ�ɵ���,���������s��
//Ȼ����pattern[i]Ϊ����s[i]Ϊֵ����һ�β��룬�����ǰ����keyֵ����map[key]�����ڵ�ǰ��s[i],����false�����keyֵ�����������(pattern[i],s[i])
//������s[i]Ϊ����pattern[i]Ϊֵ����һ�β���,ͬ��
//ΪʲôҪ�����ж����Σ���ΪҪ��֤��Ӧ��ϵ����Ҫa��ӳ�䵽b��bҲ��ӳ�䵽a
bool wordPattern(string pattern, string str) {
	if (pattern.length() == 0 && str.length() == 0)
		return true;
	if (pattern.length() == 0 || str.length() == 0)
		return false;
	vector<string> s;
	int i = 0, j = 0;
	for (; j<str.length(); j++)
	{
		if (str[j] == ' ')
		{
			string temp = str.substr(i, j - i);
			s.push_back(temp);
			i = j + 1;
		}
	}
	string temp = str.substr(i, j - i);
	s.push_back(temp);

	//�жϳ����Ƿ����
	if (s.size() != pattern.length())
		return false;
	unordered_map<char, string> check1;
	for (int i = 0; i<s.size(); i++)
	{
		if (check1.find(pattern[i]) != check1.end())
		{
			if (check1[pattern[i]] == s[i])
				continue;
			else
				return false;
		}
		else
			check1.insert(pair<char, string>(pattern[i], s[i]));
	}

	unordered_map<string, char> check2;
	for (int i = 0; i<s.size(); i++)
	{
		if (check2.find(s[i]) != check2.end())
		{
			if (check2[s[i]] == pattern[i])
				continue;
			else
				return false;
		}
		else
			check2.insert(pair<string, char>(s[i], pattern[i]));
	}
	return true;
}

//�����������еķ���
//˼·�����϶����
//������istringstream��ʵ�ַָ�...֮ǰû�Ӵ���
//����Ĵ����õ�������˼�룺
//����ĸ�͵��ʷֱ�ӳ���int����ĳһ��(char,string)����ʱ���ֱ��޸ĵ�ǰmap1��char��ֵ��map2��string��ֵ
//��Ϊ��˳����������Ե�char��stringһһ��Ӧʱ���������map1��char��ֵ����map2��string��ֵ
//ֻҪ��һ������˵������������һ�������������Ķ�Ӧ��ϵ�������߲�ͬʱ���ֵ�ĳһ�α�����ֵ���޸�
bool wordPattern1(string pattern, string str) {
	unordered_map<char, int> p2i;
	unordered_map<string, int> w2i;
	istringstream in(str);
	int i = 0, n = pattern.size();
	for (string word; in >> word; i++)
	{
		if (i == n || p2i[pattern[i]] != w2i[word])
			return false;
		p2i[pattern[i]] = w2i[word] = i + 1;
	}
	return i == n;
}
/*
int main()
{
	string pattern = "abba";
	string str = "dog cat cat dog";
	bool res = wordPattern(pattern, str);
	return 0;
}
*/