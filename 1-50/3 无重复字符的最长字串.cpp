#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;

//3 无重复字符的最长字串

/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/


//我的方法，参照剑指offer第48题，但要注意的是此题案例中字符不仅有字母，还有许多其他字符，如空格等
int lengthOfLongestSubstring(const string& str)
{
	int curLength = 0;
	int maxLength = 0;
	//定义长度为128的表，用来保存acsi码值等于下标的字符最近一次出现的位置
	vector<int> position(128, -1);
	for (int i = 0; i < str.length(); i++)
	{
		//PrevIndex用来获取上一次字符出现的位置
		int PrevIndex = position[str[i]];
		//如果没出现过或者出现位置与现在位置的差距大于当前累计长度（无影响）
		if (PrevIndex<0 || i - PrevIndex>curLength)
			++curLength;
		else
		{
			//更新最大长度
			if (curLength > maxLength)
				maxLength = curLength;
			//此时出现位置与现在位置的差距小于累计长度，长度更新为从上一个该字符后开始计数
			curLength = i - PrevIndex;
		}
		//更新表中字符出现的位置信息
		position[str[i]] = i;
	}
	if (curLength > maxLength)
		maxLength = curLength;
	return maxLength;
}

//方法二，与上面方法思想一致，更简练
int lengthOfLongestSubstring(string s)
{
	vector<int>v(128, 0);//位置信息表，初值为0
	int t = 0; int ans = 0;//t表示上次出现的位置，ans表示最大长度
	for (int i = 0; i<s.length(); i++)
	{
		t = max(t, v[s[i]]);//用max取上次出现的位置
		ans = max(ans, i - t + 1);//更新最大距离
		v[s[i]] = i + 1;//更新位置信息表
	}
	return ans;
}