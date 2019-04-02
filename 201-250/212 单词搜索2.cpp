#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
//212 ��������2

/*
����һ����ά���� board ��һ���ֵ��еĵ����б� words���ҳ�����ͬʱ�ڶ�ά������ֵ��г��ֵĵ��ʡ�
���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ��һ�������в������ظ�ʹ�á�
ʾ��:
����:
words = ["oath","pea","eat","rain"] and board =
[['o','a','a','n'],['e','t','a','e'],['i','h','k','r'],['i','f','l','v']]
���: ["eat","oath"]
*/

/*
��������������һ�����ʵķ������л��ݵĻ���Ч�ʻ�ܵͣ���Ϊ���words����ܳ���ÿ�ζ�Ҫ���л���
��õķ����ǰ��ַ���ת���ɸ��������ַ�����ϵ��һ����ʽ����
�����ֵ���
����ֱ�Ӱ�����208����ֵ�������Ϊֻ�漰�����ֵ���������ֻ������insert��Ա����
�ڴ˻������Ȱ��ַ�������ת���ֵ���
�ٱ�����ά����
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
};

//�ݹ��������
void recursion(int row, int col, string& str, TrieNode* root, vector<vector<char>>& board, vector<string>& res)
{
	char c = board[row][col];//ȡ��ǰֵ
	if (c == '.')//�����ֵΪ��.��,˵���˴α����и�λ���Ѿ�ȡ��,����
		return;
	//�����ж��ֵ����ڸ�λ���Ƿ�ǿգ���Ϊ����˵��û��·��
	if (root->letter[c - 'a'] == nullptr)
		return;
	//��ʱ˵���ýڵ��ڱ��α����л�δ�����ʣ�������Ϊ��.��,��ʾ�ѷ���
	board[row][col] = '.';
	//���ڵ���ַ�ֵ��string
	str.push_back(c);
	//������ڵ㵽�ýڵ��ʾһ�����ʣ�������res���޸�isWord���������ظ���res
	if (root->letter[c - 'a']->isWord)
	{
		res.push_back(str);
		root->letter[c - 'a']->isWord = false;
	}
	//�ݹ������ǰ������������ĸ���
	if (col<board[row].size() - 1)
		recursion(row, col + 1, str, root->letter[c - 'a'], board, res);
	if (col>0)
		recursion(row, col - 1, str, root->letter[c - 'a'], board, res);
	if (row<board.size() - 1)
		recursion(row + 1, col, str, root->letter[c - 'a'], board, res);
	if (row>0)
		recursion(row - 1, col, str, root->letter[c - 'a'], board, res);
	//�ָ���ǰ�ַ�ֵ
	board[row][col] = c;
	//str���һ���ַ�������
	str.pop_back();
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	//�����ֵ�������words�е��ʲ����ֵ�����
	Trie dict;
	for (string word : words)
		dict.insert(word);
	//rootΪ�ֵ����ĸ�
	TrieNode* root = dict.root;
	vector<string> res;
	string str = "";
	//��������
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
	
	