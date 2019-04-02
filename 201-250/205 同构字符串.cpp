#include<iostream>
#include<vector>
#include<string>
using namespace std;

//205 同构字符串

/*

*/


//方法一，标志数组
/*
这道题主要是对对应关系，也就是映射的考察，一开始我是想把字符串转化成同类型的数字来计算
但是实现的时候想偏了，最终的实现在方法二，很简洁但是效率一般
新的解题思路如下：定义两个长度为128的标志数组用来表示到当前为止，某个字母上次出现的时刻（遍历的次数）
如果两个字符串同构，那么到达当前位置i时，s[i]上次出现的时刻是等于t[i]上次出现的时刻的，否则不同构
这是一个很巧妙的思路，只不过需要额外的空间来完成
*/
bool isIsomorphic(string s, string t) {
	//长度不同直接退出
	if (s.length() != t.length())
		return false;
	int len = s.length();
	//定义标志数组
	vector<int> flagA(128, 0);
	vector<int> flagB(128, 0);
	//遍历字符串
	for (int i = 0; i<len; i++)
	{
		//到i为止，字符s[i]和t[i]上一次出现的位置不同则退出
		if (flagA[s[i]] != flagB[t[i]])
			return false;
		//相同则将两个位置的值都更新成相同数值，注意这里为什么要用i+1来给赋值
		//首先为什么不用i，因为i的话第一位会置为0，这和初始值相同，这样就不能判断第一位是否同构
		//其次这里赋值的意义到底是什么？
		//其实怎么赋值都行，只要保证值不为0，且满足值不重复出现就行，只不过这里用i+1非常便于解释，前面的赋值是为后面的比较提供线索
		//如果值重复出现，就意味着同一个标志数组中不同的位可能出现同样的值，比较就失去了意义
		flagA[s[i]] = i + 1;
		flagB[t[i]] = i + 1;
	}
	return true;
}


//方法二
/*
用find来实现，类似于把字符串转成对应的数字
以paper和title为例
第一步：0 0
第二步：1 1
第三步：0 0
第四步：3 3
第五步：4 4
相等
01034 01034 转成了和字符串同构的数字，就很好比较
*/
bool isIsomorphic(string s, string t) {
	if (s.length() == 0)return true;
	int i = 0;
	while (i<s.length())
	{
		//这里为什么会用find呢？
		//这里的find起的是定位的作用，位置就是当前字符第一次出现的位置
		//以egg和add为例，find的结果是011和011，也就是说这是一个把字符串转换成数字的过程
		//一旦不等就退出
		if (s.find(s[i]) != t.find(t[i]))
			return false;
		i++;
	}
	return true;
}