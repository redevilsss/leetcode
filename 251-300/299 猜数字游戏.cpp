#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//299 猜数字游戏

/*
你正在和你的朋友玩 猜数字（Bulls and Cows）游戏：你写下一个数字让你的朋友猜。每次他猜测后，你给他一个提示，告诉他有多少位数字和确切位置都猜对了（称为“Bulls”, 公牛），有多少位数字猜对了但是位置不对（称为“Cows”, 奶牛）。你的朋友将会根据提示继续猜，直到猜出秘密数字。
请写出一个根据秘密数字和朋友的猜测数返回提示的函数，用 A 表示公牛，用 B 表示奶牛。
请注意秘密数字和朋友的猜测数都可能含有重复数字。
示例 1:
输入: secret = "1807", guess = "7810"
输出: "1A3B"
解释: 1 公牛和 3 奶牛。公牛是 8，奶牛是 0, 1 和 7。
*/

//分析：这道题其实很简单，难的地方在于读懂题意...
/*
bulls数很好找，只要两字符串对应位置相等，就ok
cows数通过两个哈希表来实现，分别记录每个数字出现的次数
最终每个数字出现的次数由两哈希表对应位置较小的数来确定
cows和bulls对立的，即bulls则肯定不是cows，所以通过ifelse分支来实现
*/
string getHint(string secret, string guess) {
	if (secret.length() == 0)
		return "";
	int i = 0;
	int bulls = 0;
	//分别记录两字符串中各数字出现的个数
	vector<int> flag1(10, 0);
	vector<int> flag2(10, 0);
	//记录bulls和两数组
	while (i<secret.size())
	{
		if (secret[i] == guess[i])
			bulls++;
		else
		{
			flag1[secret[i]-'0']++;
			flag2[guess[i]-'0']++;
		}
		i++;
	}
	//记录cows
	int cows = 0;
	for (int i = 0; i<10; i++)
		cows += min(flag1[i], flag2[i]);
	//转化输出形式
	string res = to_string(bulls);
	res += "A" + to_string(cows) + "B";
	return res;

}

int main()
{
	string secret = "1123", guess = "0111";
	string res = getHint(secret, guess);
	return 0;
}