#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//165 比较版本号
/*
比较两个版本号 version1 和 version2。
如果 version1 > version2 返回 1，如果 version1 < version2 返回 -1， 除此之外返回 0。
你可以假设版本字符串非空，并且只包含数字和 . 字符。
. 字符不代表小数点，而是用于分隔数字序列。
例如，2.5 不是“两个半”，也不是“差一半到三”，而是第二版中的第五个小版本。
你可以假设版本号的每一级的默认修订版号为 0。例如，版本号 3.4 的第一级（大版本）和第二级（小版本）修订号分别为 3 和 4。其第三级和第四级修订号均为 0。
示例 1:
输入: version1 = "0.1", version2 = "1.1"
输出: -1
*/

/*
这道题就是一个简单的比较
同时遍历两个字符串，以.为分隔符，查找当前所在的两个.之间的部分（当前指向的小版本号），并将这部分转化为十进制去比较
如果比出大小就返回，否则清空保存的数值，继续遍历比较下一个小版本号
如果完全一样，就返回0

*/

int compareVersion(string version1, string version2) {
	int v1 = 0;
	int v2 = 0;
	for (int i = 0, j = 0; i<version1.length() || j<version2.length();)
	{
		int v1 = 0, v2 = 0;
		while (i<version1.length() && version1[i] != '.')
		{
			v1 = v1 * 10 + (version1[i] - '0');
			i++;
		}
		i++;
		while (j<version2.length() && version2[j] != '.')
		{
			v2 = v2 * 10 + (version2[j] - '0');
			j++;
		}
		j++;
		if (v1>v2)
			return 1;
		if (v1<v2)
			return -1;
	}
	return 0;
}

