#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
using namespace std;

//318 ��󵥴ʳ��ȳ˻�
/*
����һ���ַ������� words���ҵ� length(word[i]) * length(word[j]) �����ֵ���������������ʲ����й�����ĸ���������Ϊÿ������ֻ����Сд��ĸ������������������������ʣ����� 0��
ʾ�� 1:
����: ["abcw","baz","foo","bar","xtfn","abcdef"]
���: 16
����: ����������Ϊ "abcw", "xtfn"��
*/

//�����ֱ��ȥ�����϶��в�ͨ
/*
�ȽϺõķ����ǹ����ϣ��26λ���±�i��ֵΪ1���ʾ�����д�����ĸ'a'+i����
��ôÿ�����ʶ�������һ��26λ�ַ�������ʾ,������һ����words�ȳ�������value��
����abc����11100000000000000000000000
abd����11010000000000000000000000
����ж������������Ƿ�����ظ�Ԫ���أ�
ֱ�����뼴��
����abc��Ӧ�����ֺ�abd��Ӧ����������ͷ�0��˵�����ظ�

��ô��words��ÿ��Ԫ�ض�ת����һ��26λ����������ά��һ����󳤶Ȼ�res��ֵΪ0����ѭ��
iȡ0��words.size(),jȡi+1��words.size(),�ж϶�Ӧλ�õ�����value[i]��value[j]�����Ƿ�Ϊ0
��Ϊ0��˵��words[i]��words[j]û���ظ�����¼�䳤�ȳ˻�����ά��res
���������res�б���ľ�����ĿҪ��Ľ��
*/
int maxProduct(vector<string>& words) {
	if (words.size() == 0)
		return 0;
	vector<int> value(words.size(), 0);
	//����value����
	for (int i = 0; i<words.size(); i++)
	{
		for (int j = 0; j<words[i].length(); j++)
			value[i] = (value[i] | (1 << (words[i][j] - 'a')));
	}
	//������
	int res = 0;
	for (int i = 0; i<words.size(); i++)
	{
		for (int j = i + 1; j<words.size(); j++)
		{
			//�ж�words[i]��words[j]�Ƿ�����ظ�Ԫ��
			if ((value[i] & value[j]) == 0)
				res = max(res, (int)(words[i].length()*words[j].length()));
		}
	}
	return res;
}

int main()
{
	vector<string> words = { "abcw","baz","foo","bar","xtfn","abcdef" };
	int res = maxProduct(words);
	return 0;
}