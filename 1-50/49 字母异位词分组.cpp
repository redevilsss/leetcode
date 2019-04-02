#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

//49 字母异位词分组
/*
给定一个字符串数组，将字母异位词组合在一起。
字母异位词指字母相同，但排列不同的字符串。
示例:
输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[["ate","eat","tea"],["nat","tan"],["bat"]]
*/

//重点在于如何控制不同字母组成的字符串进入不同的数组中
//使用unordered_map，以排好序的string作为键值
//对每个元素进行排序与键值比较，若相等则直接加入
//若当前不存在该键值则插入该键值
//m是一个key为排序string，value为行号的unordered_map
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	vector<vector<string>> res;
	unordered_map<string, int> m;
	//在集合中用排好序的string作为键，值用来区分数组，
	//不同的值表示字母组成不同，要放在不同的字符串数组中
	int i = 0;
	for (auto str : strs) 
	{
		string str1 = str;
		sort(str1.begin(), str1.end());
		//如果存在该排序字符串，则说明str1与res[m[str1]]中的字符串是字母异位词
		if (m.count(str1) > 0) {
			res[m[str1]].push_back(str);
		}
		//不存在则说明之前还未出现过，新建一行，并且在m中也新加一个键值对与此对应
		//这样当下次遇到当前字符串的字母异位词是会直接插入
		else {
			m[str1] = i++;
			res.push_back(vector<string>{str});
		}
	}
	return res;
}