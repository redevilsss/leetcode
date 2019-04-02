#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// 17 �绰�������ĸ���
/*
����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
ʾ��:
���룺"23"
�����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
//����˼������ʹ��queue��ÿһλ�Ľ���queue��Ҫ�ȳ����
//�ٸ����ӣ���23��
//�ں����У����ȱ�����2������Ӧ�������ַ���д��queue���С�a�� ��b�� ��c������
//�ٱ�����3����Ӧ�������ַ������ηֱ�ӵ���һ��queue�б�����ַ�����
//��a��ʼ ��a�ֱ��d e f�����棬��������
//������ˮ��һ����һ��һ���ӹ���Ҳ����ÿ������һ���ַ�����Ҫ���һ�γ��Ӻ����
vector<string> letterCombinations(string digits) {
	vector<string> table = { " ","*", "abc","def", "ghi", "jkl","mno","pqrs","tuv","wxyz" };
	if (digits == "")
		return vector<string>{};
	queue<string> res;
	res.push("");
	//����ˮ��һ�������β�����ÿ�α���ǰi+1������ɵ����н������һ��������һ����������µ��ַ���ֱ����������������
	for (int i = 0; i<digits.length(); i++)
	{
		//��¼��ʱ�����е�Ԫ�أ���Ϊ����queue�ı仯size���ܻ��
		int length = res.size();
		for (int j = 0; j<length; j++)
		{
			string temp = res.front();
			res.pop();
			for (char c : table[digits[i] - '0'])
				res.push(temp + c);
		}
	}
	//�������е�Ԫ�����η������飬���ǽ��
	vector<string>ans;
	while (!res.empty()) {
		ans.push_back(res.front());
		res.pop();
	}
	return ans;