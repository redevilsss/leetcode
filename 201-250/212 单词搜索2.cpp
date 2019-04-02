#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
//212 单词搜索2

/*
给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
示例:
输入:
words = ["oath","pea","eat","rain"] and board =
[['o','a','a','n'],['e','t','a','e'],['i','h','k','r'],['i','f','l','v']]
输出: ["eat","oath"]
*/

/*
这道题如果按照找一个单词的方法进行回溯的话，效率会很低，因为如果words数组很长，每次都要进行回溯
最好的方法是把字符串转化成更够表现字符间联系的一种形式来做
比如字典树
这里直接搬来了208题的字典树，因为只涉及创建字典树，所以只保留了insert成员函数
在此基础上先把字符串数组转成字典树
再遍历二维矩阵
*/

class TrieNode
{
public:
	vector<TrieNode*> letter;
	bool isWord;
	TrieNode()
	{
		letter.resize(26, NULL);
		isWord = false;
	}
};
class Trie {

public:
	TrieNode* root;
	//创建根节点
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}
	//插入字符串
	/*遍历需要插入的string，同时指针p从root一直往下next，
	如果对应字符的next为NULL，就创建一个新的TrieNode
	遍历完后，在最后那个TireNode标记为True，表示这个TrieNode对应的词在这课Trie树中存在。
	*/
	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* p = root;
		for (int i = 0; i < word.length(); i++)
		{
			//如果word的第i位字符在当前节点的letter数组中目前还没有，就新建一个节点，然后更新当前节点到该节点
			//否则就继续遍历下一步
			if (p->letter[word[i] - 'a'] == nullptr)
				p->letter[word[i] - 'a'] = new TrieNode();
			p = p->letter[word[i] - 'a'];
		}
		//插入完成后把当前节点的isWord置true,标明从根节点到此处表示一个数
		p->isWord = true;
	}
};

//递归遍历数组
void recursion(int row, int col, string& str, TrieNode* root, vector<vector<char>>& board, vector<string>& res)
{
	char c = board[row][col];//取当前值
	if (c == '.')//如果该值为‘.’,说明此次遍历中该位置已经取过,返回
		return;
	//否则判断字典树在该位置是否非空，若为空则说明没有路了
	if (root->letter[c - 'a'] == nullptr)
		return;
	//此时说明该节点在本次遍历中还未被访问，将其置为‘.’,表示已访问
	board[row][col] = '.';
	//将节点的字符值入string
	str.push_back(c);
	//如果根节点到该节点表示一个单词，单词入res，修改isWord变量以免重复入res
	if (root->letter[c - 'a']->isWord)
	{
		res.push_back(str);
		root->letter[c - 'a']->isWord = false;
	}
	//递归遍历当前点的上下左右四个点
	if (col<board[row].size() - 1)
		recursion(row, col + 1, str, root->letter[c - 'a'], board, res);
	if (col>0)
		recursion(row, col - 1, str, root->letter[c - 'a'], board, res);
	if (row<board.size() - 1)
		recursion(row + 1, col, str, root->letter[c - 'a'], board, res);
	if (row>0)
		recursion(row - 1, col, str, root->letter[c - 'a'], board, res);
	//恢复当前字符值
	board[row][col] = c;
	//str最后一个字符出数组
	str.pop_back();
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	//创建字典树，把words中单词插入字典树中
	Trie dict;
	for (string word : words)
		dict.insert(word);
	//root为字典树的根
	TrieNode* root = dict.root;
	vector<string> res;
	string str = "";
	//遍历数组
	for (int row = 0; row < board.size(); row++)
	{
		for (int col = 0; col < board[0].size(); col++)
		{
			recursion(row, col, str, root, board, res);
		}
	}
	return res;
}



int main()
{
	vector<string> words = 
	{"bbaabaabaaaaabaababaaaaababb","aabbaaabaaabaabaaaaaabbaaaba",
		"babaababbbbbbbaabaababaabaaa","bbbaaabaabbaaababababbbbbaaa",
		"babbabbbbaabbabaaaaaabbbaaab","bbbababbbbbbbababbabbbbbabaa",
		"babababbababaabbbbabbbbabbba","abbbbbbaabaaabaaababaabbabba",
		"aabaabababbbbbbababbbababbaa","aabbbbabbaababaaaabababbaaba",
		"ababaababaaabbabbaabbaabbaba","abaabbbaaaaababbbaaaaabbbaab",
		"aabbabaabaabbabababaaabbbaab","baaabaaaabbabaaabaabababaaaa",
		"aaabbabaaaababbabbaabbaabbaa","aaabaaaaabaabbabaabbbbaabaaa",
		"abbaabbaaaabbaababababbaabbb","baabaababbbbaaaabaaabbababbb",
		"aabaababbaababbaaabaabababab","abbaaabbaabaabaabbbbaabbbbbb",
		"aaababaabbaaabbbaaabbabbabab","bbababbbabbbbabbbbabbbbbabaa",
		"abbbaabbbaaababbbababbababba","bbbbbbbabbbababbabaabababaab",
		"aaaababaabbbbabaaaaabaaaaabb","bbaaabbbbabbaaabbaabbabbaaba",
		"aabaabbbbaabaabbabaabababaaa","abbababbbaababaabbababababbb",
		"aabbbabbaaaababbbbabbababbbb","babbbaabababbbbbbbbbaabbabaa" };
	vector<vector<char>> board = 
	{ {'b','a','a','b','a','b'},
	{'a','b','a','a','a','a'},
	{'a','a','a','a','a','b'},
	{'a','b','a','b','b','a'},
	{'a','a','b','b','a','b'},
	{'a','a','b','b','b','a'},
	{'a','a','b','a','a','b'} };
	vector<string> res = findWords(board, words);
	return 0;
}
	
	