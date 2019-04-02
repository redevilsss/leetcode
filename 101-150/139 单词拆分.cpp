#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

//139 单词拆分

/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
说明：
拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
*/

//用动态规划来解决问题
//构造一个长度为n+1的数组，则数组的第i位用来表示字符串的前i个字符能否被拆成字典中的元素
bool wordBreak(string s, vector<string>& wordDict) {
	vector<bool> dp(s.size() + 1, false);
	//用哈希表，因为有查找功能，截出来的子串我可以直接用哈希表来查找看有没有与之相等的单词
	unordered_set<string> m(wordDict.begin(), wordDict.end());
	dp[0] = true;//dp[0]置为true
	//遍历字符串，更新dp数组
	//这里可以适当的优化，如果字典中最长单词长度为l，当目前下标为i的时候，我的j只需要从i-l到l遍历即可
	//因为此时如果i在0~i-l之间，截取长度i-j是大于l的，也就是说不可能存在匹配的单词
	//所以我要确定当前字典中最长单词的长度是多少
	int maxWordLength = 0;
	for (int i = 0; i < wordDict.size(); ++i) {
		maxWordLength = max(maxWordLength, (int)wordDict[i].size());
	}
	//开始遍历
	for (int i = 1; i <= s.size(); i++)
	{
		for (int j = max(0, i-maxWordLength); j<i; j++)
			//substr(j, i-j)表示从j起，长度为i-j，如果能查到，说明下标j到i的字符串是字典中的单词
			//更新dp[i]后break，继续遍历
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