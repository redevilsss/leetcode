#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

//49 ��ĸ��λ�ʷ���
/*
����һ���ַ������飬����ĸ��λ�������һ��
��ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����
ʾ��:
����: ["eat", "tea", "tan", "ate", "nat", "bat"],
���:
[["ate","eat","tea"],["nat","tan"],["bat"]]
*/

//�ص�������ο��Ʋ�ͬ��ĸ��ɵ��ַ������벻ͬ��������
//ʹ��unordered_map�����ź����string��Ϊ��ֵ
//��ÿ��Ԫ�ؽ����������ֵ�Ƚϣ��������ֱ�Ӽ���
//����ǰ�����ڸü�ֵ�����ü�ֵ
//m��һ��keyΪ����string��valueΪ�кŵ�unordered_map
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	vector<vector<string>> res;
	unordered_map<string, int> m;
	//�ڼ��������ź����string��Ϊ����ֵ�����������飬
	//��ͬ��ֵ��ʾ��ĸ��ɲ�ͬ��Ҫ���ڲ�ͬ���ַ���������
	int i = 0;
	for (auto str : strs) 
	{
		string str1 = str;
		sort(str1.begin(), str1.end());
		//������ڸ������ַ�������˵��str1��res[m[str1]]�е��ַ�������ĸ��λ��
		if (m.count(str1) > 0) {
			res[m[str1]].push_back(str);
		}
		//��������˵��֮ǰ��δ���ֹ����½�һ�У�������m��Ҳ�¼�һ����ֵ����˶�Ӧ
		//�������´�������ǰ�ַ�������ĸ��λ���ǻ�ֱ�Ӳ���
		else {
			m[str1] = i++;
			res.push_back(vector<string>{str});
		}
	}
	return res;
}