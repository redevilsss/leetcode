#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

//211 �������������

/*
���һ��֧���������ֲ��������ݽṹ��
void addWord(word)
bool search(word)
search(word) �����������ֻ�������ʽ�ַ������ַ���ֻ������ĸ . �� a-z �� . ���Ա�ʾ�κ�һ����ĸ��
ʾ��:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
*/


//������˼�뻹���ֵ�������ǰ���208����񣬲�ͬ������ڶ���һ������ƥ��
//Ҳ������search��ʱ�������ǰλ���ǡ�.����˵��������26����ĸ������һ����������λ��ȥ�жϺ���ĵ����Ƿ��ܲ��ҵ�
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