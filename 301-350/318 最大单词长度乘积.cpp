#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
using namespace std;

//318 最大单词长度乘积
/*
给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。
示例 1:
输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
输出: 16
解释: 这两个单词为 "abcw", "xtfn"。
*/

//这道题直接去暴力肯定行不通
/*
比较好的方法是构造哈希表，26位，下标i的值为1则表示单词中存在字母'a'+i存在
那么每个单词都可以用一个26位字符串来表示,保存在一个与words等长的数组value中
比如abc就是11100000000000000000000000
abd就是11010000000000000000000000
如何判断这两个数字是否存在重复元素呢？
直接相与即可
比如abc对应的数字和abd对应的数字相与就非0，说明有重复

那么将words中每个元素都转换成一个26位二进制数，维护一个最大长度积res初值为0两层循环
i取0到words.size(),j取i+1到words.size(),判断对应位置的数字value[i]和value[j]相与是否为0
若为0则说明words[i]和words[j]没有重复，记录其长度乘积用于维护res
遍历完毕则res中保存的就是题目要求的结果
*/
int maxProduct(vector<string>& words) {
	if (words.size() == 0)
		return 0;
	vector<int> value(words.size(), 0);
	//构造value数组
	for (int i = 0; i<words.size(); i++)
	{
		for (int j = 0; j<words[i].length(); j++)
			value[i] = (value[i] | (1 << (words[i][j] - 'a')));
	}
	//找最大积
	int res = 0;
	for (int i = 0; i<words.size(); i++)
	{
		for (int j = i + 1; j<words.size(); j++)
		{
			//判断words[i]和words[j]是否存在重复元素
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