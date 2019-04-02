#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

//211 添加与搜索单词

/*
设计一个支持以下两种操作的数据结构：
void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。
示例:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
*/


//这道题的思想还是字典树，和前面的208题很像，不同点就在于多了一个正则匹配
//也就是在search的时候，如果当前位置是‘.’，说明可以是26个字母中任意一个，跳过该位置去判断后面的单词是否能查找到
class WordDictionary {
	class Node {
	public:
		bool isWord;
		vector<Node*> next;
		Node()
		{
			next.resize(26, nullptr);
			isWord = false;
		}
		~Node()
		{
			for (int i = 0; i<26; i++)
				delete next[i];
		}
	};
public:
	/** Initialize your data structure here. */
	Node* root;
	WordDictionary() {
		root = new Node();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		Node* node = root;
		for (int i = 0; i<word.length(); i++)
		{
			if (node->next[word[i] - 'a'] == nullptr)
				node->next[word[i] - 'a'] = new Node();
			node = node->next[word[i] - 'a'];
		}
		node->isWord = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool serach(Node* node, string word, int index)
	{
		if (!node)
			return false;
		if (word.length() == index)
			return node->isWord;
		if (word[index] == '.')
		{
			for (int i = 0; i<26; i++)
				if (node->next[i] && serach(node->next[i], word, index + 1))
					return true;
		}
		else
		{
			if (node->next[word[index] - 'a'] && serach(node->next[word[index] - 'a'], word, index + 1))
				return true;
		}

		return false;

	}
	bool search(string word) {
		return serach(root, word, 0);
	}
};

int main()
{
	WordDictionary* dict = new WordDictionary{};
	dict->addWord("a");
	dict->addWord("a");
	bool res1=dict->search(".");
	bool res2 = dict->search("a");
	bool res3 = dict->search("aa");
	bool res4 = dict->search("a");
	bool res5 = dict->search(".a");
	bool res6 = dict->search("a.");
	return 0;

	
}