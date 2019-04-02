#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

//208 实现trie树
/*
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
示例:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");
trie.search("app");     // 返回 true
*/

//这道题考察的就是字典树，之前没有看过相关的东西
//其实字典树就是26叉树，每个节点的所有子节点值都不同
//每次插入到达某一层如果没有该字符，就新建节点，否则就继续遍历
//查找成功的条件是是当前节点不为空且isWord标志位位true

//构造前缀树节点，每个节点最多有26个子节点，分别表示26个字母，初始时为nullptr，其实前缀树就是一个26叉树
//isword用来标记到当前为止是不是一个单词
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
	TrieNode* root;
public:

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

	/*和插入的思路类似，遍历string，同时指针p从root节点一直往下next，
	如果碰到对应字符的letter[]为NULL或者string已经遍历完成，则退出循环。
	最后检查p是否为不为NULL以及isword是否为true，两者都满足则说明这个词存在于Trie树。
	*/
	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* p = root;
		//当p不为空且i小于字符串长度时，遍历找节点
		for (int i = 0; i < word.length()&p != nullptr; i++)
			p = p->letter[word[i] - 'a'];
		//退出时说明此时遍历完字符串或者当前到达的节点为空而没遍历完整个串
		//如果字符串遍历完，返回时p应不为空，且此时p的isWord标志为true
		return p != nullptr&&p->isWord == true;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	//实现上基本同查找，唯一的区别在于，无需检查isword是否为true
	bool startsWith(string prefix) {
		TrieNode* p = root;
		for (int i = 0; i < prefix.length() && p != nullptr; i++)
			p = p->letter[prefix[i] - 'a'];
		return p != nullptr;
	}
};