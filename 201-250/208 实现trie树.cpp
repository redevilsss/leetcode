#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

//208 ʵ��trie��
/*
ʵ��һ�� Trie (ǰ׺��)������ insert, search, �� startsWith ������������
ʾ��:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // ���� true
trie.search("app");     // ���� false
trie.startsWith("app"); // ���� true
trie.insert("app");
trie.search("app");     // ���� true
*/

//����⿼��ľ����ֵ�����֮ǰû�п�����صĶ���
//��ʵ�ֵ�������26������ÿ���ڵ�������ӽڵ�ֵ����ͬ
//ÿ�β��뵽��ĳһ�����û�и��ַ������½��ڵ㣬����ͼ�������
//���ҳɹ����������ǵ�ǰ�ڵ㲻Ϊ����isWord��־λλtrue

//����ǰ׺���ڵ㣬ÿ���ڵ������26���ӽڵ㣬�ֱ��ʾ26����ĸ����ʼʱΪnullptr����ʵǰ׺������һ��26����
//isword������ǵ���ǰΪֹ�ǲ���һ������
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

	//�������ڵ�
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}
	//�����ַ���
	/*������Ҫ�����string��ͬʱָ��p��rootһֱ����next��
	�����Ӧ�ַ���nextΪNULL���ʹ���һ���µ�TrieNode
	�������������Ǹ�TireNode���ΪTrue����ʾ���TrieNode��Ӧ�Ĵ������Trie���д��ڡ�
	*/
	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* p = root;
		for (int i = 0; i < word.length(); i++)
		{
			//���word�ĵ�iλ�ַ��ڵ�ǰ�ڵ��letter������Ŀǰ��û�У����½�һ���ڵ㣬Ȼ����µ�ǰ�ڵ㵽�ýڵ�
			//����ͼ���������һ��
			if (p->letter[word[i] - 'a'] == nullptr)
				p->letter[word[i] - 'a'] = new TrieNode();
			p = p->letter[word[i] - 'a'];
		}
		//������ɺ�ѵ�ǰ�ڵ��isWord��true,�����Ӹ��ڵ㵽�˴���ʾһ����
		p->isWord = true;
	}

	/*�Ͳ����˼·���ƣ�����string��ͬʱָ��p��root�ڵ�һֱ����next��
	���������Ӧ�ַ���letter[]ΪNULL����string�Ѿ�������ɣ����˳�ѭ����
	�����p�Ƿ�Ϊ��ΪNULL�Լ�isword�Ƿ�Ϊtrue�����߶�������˵������ʴ�����Trie����
	*/
	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* p = root;
		//��p��Ϊ����iС���ַ�������ʱ�������ҽڵ�
		for (int i = 0; i < word.length()&p != nullptr; i++)
			p = p->letter[word[i] - 'a'];
		//�˳�ʱ˵����ʱ�������ַ������ߵ�ǰ����Ľڵ�Ϊ�ն�û������������
		//����ַ��������꣬����ʱpӦ��Ϊ�գ��Ҵ�ʱp��isWord��־Ϊtrue
		return p != nullptr&&p->isWord == true;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	//ʵ���ϻ���ͬ���ң�Ψһ���������ڣ�������isword�Ƿ�Ϊtrue
	bool startsWith(string prefix) {
		TrieNode* p = root;
		for (int i = 0; i < prefix.length() && p != nullptr; i++)
			p = p->letter[prefix[i] - 'a'];
		return p != nullptr;
	}
};