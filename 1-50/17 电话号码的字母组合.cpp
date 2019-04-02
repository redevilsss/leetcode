#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// 17 电话号码的字母组合
/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
示例:
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
//核心思想在于使用queue，每一位的进行queue都要先出后进
//举个例子，“23”
//在函数中，首先遍历‘2’所对应的所有字符，写入queue，有“a” “b” “c”三个
//再遍历‘3’对应的所有字符，依次分别加到上一步queue中保存的字符串上
//从a开始 给a分别加d e f，保存，依次类推
//就像流水线一样，一批一批加工，也就是每遍历到一个字符，就要完成一次出队和入队
vector<string> letterCombinations(string digits) {
	vector<string> table = { " ","*", "abc","def", "ghi", "jkl","mno","pqrs","tuv","wxyz" };
	if (digits == "")
		return vector<string>{};
	queue<string> res;
	res.push("");
	//像流水线一样做批次操作，每次保存前i+1个数组成的所有结果，下一次再在这一基础上添加新的字符，直到遍历完所有数字
	for (int i = 0; i<digits.length(); i++)
	{
		//记录此时数组中的元素，因为随着queue的变化size可能会变
		int length = res.size();
		for (int j = 0; j<length; j++)
		{
			string temp = res.front();
			res.pop();
			for (char c : table[digits[i] - '0'])
				res.push(temp + c);
		}
	}
	//将队列中的元素依次放入数组，就是结果
	vector<string>ans;
	while (!res.empty()) {
		ans.push_back(res.front());
		res.pop();
	}
	return ans;