#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

//71 简化路径

/*
以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。
在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；
此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。
请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。
最后一个目录名（如果存在）不能以 / 结尾。
此外，规范路径必须是表示绝对路径的最短字符串。
输入："/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。
*/

//这道题是借鉴别人的，自己理解了一下，其核心就是对栈的使用，stack用来存储文件名
//遇到../弹出栈顶，遇到./不做处理,当目前元素不为/时用fd来收集文件名，等于/但前面没有..或.时
//将其存入栈中，通过一次遍历实现简化路径

string simplifyPath(string path) {
	stack<string> s;
	string fd = "";//fd用来存储某一层的文件名，如果是..则返回上一层，弹出当前栈顶元素，如果是.则不变，将fd清空，如果是普通文件名，则将其入栈
	string res = "";
	path = path + "/";//在路径末尾加一个/，防止丢失最后的一个文件名

	for (auto c : path)//遍历字符串
	{
		if (c == '/'&&fd == "..")//当出现../时将栈顶元素弹出，即返回上一层，将此时的fd置零，继续遍历
		{
			if (!s.empty())
				s.pop();
			fd = "";
			continue;
		}
		else if (c == '/'&&fd == ".")//当出现./时清空fd，不做其他处理
		{
			fd = "";
			continue;
		}
		//这里的c是前面的/，前面两个分支的/是后面/，从前面的/开始记录fd，到后面的/检查fd
		else if (c == '/')//当c为/而fd不为..或者.时，看当前的fd是不是字符串，如果是就压入栈
		{
			if (fd != "")
				s.push(fd);//当c为/而fd不是空串时，将fd入栈，若遇到下一个fd为..再出栈
			fd = "";
			continue;
		}
		//当当前所指的字符为字母或.时，修改fd，在字符为/时做其他处理
		fd += c;
	}

	if (s.empty())
		return "/";
	while (!s.empty())
	{
		res = "/" + s.top() + res;
		s.pop();
	}
	return res;
}

int main()
{
	string str = "/home/.././home/a";
	string res=simplifyPath(str);
}