#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//79 ��������

/*
����һ����ά�����һ�����ʣ��ҳ��õ����Ƿ�����������С�
���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�
ʾ��:
board =[['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
���� word = "ABCCED", ���� true.
���� word = "SEE", ���� true.
���� word = "ABCB", ���� false.
*/

//����һ��//�����ڽ�ָoffer��12�⣬�����������ȽϷ��ӣ���ѡ����һ��ʱû��ȡ�ᣬ����Ч�ʲ�
bool hasPath(vector<vector<char>>& board, int rows, int cols, int row, int col, const string str, int& pathLength, vector<vector<bool>>& visited);

bool exist(vector<vector<char>>& board, string word) {
	if (board.size() == 0 || board[0].size() == 0)
		return false;
	int rows = board.size();
	int cols = board[0].size();
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	int pathLength = 0;//��¼��ǰƥ�䳤��
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			if (hasPath(board, rows, cols, i, j, word, pathLength, visited))
				return true;
		}
	}
	return false;
}

bool hasPath(vector<vector<char>>& board, int rows, int cols, int row, int col, const string str, int& pathLength, vector<vector<bool>>& visited)
{
	if (str[pathLength] == '\0')
		return true;
	bool flag = false;
	if (row>=0 && row<rows&&col>=0 && col<cols && 
		!visited[row][col] && str[pathLength] == board[row][col])
	{
		++pathLength;
		visited[row][col] = true;
		flag = hasPath(board, rows, cols, row - 1, col, str, pathLength, visited) ||
			hasPath(board, rows, cols, row + 1, col, str, pathLength, visited) || 
			hasPath(board, rows, cols, row, col - 1, str, pathLength, visited) || 
			hasPath(board, rows, cols, row, col + 1, str, pathLength, visited);
		if (!flag)
		{
			--pathLength;
			visited[row][col] = false;
		}
	}
	return flag;
}







//������ ����һ��go�������ڸı䵱ǰ���꣬���зֱ��Ӧ��������
//�����Ĵο�ÿ�β������ܷ����ƥ���ַ�������һ���ַ���������ԣ��ݹ飬������һ��
int go[4][2] = { 1, 0, 0, 1, -1, 0, 0 ,-1 };//go�����ʾ���¡����ҡ����ϡ�����ʱ������仯���
int m, n;
vector<vector<char>> Board;//�����ȫ�ֱ���
string Word;//ͬ��
vector<vector<int>> visited;
//������idx���ڴ洢��ǰƥ��ĵ��ʳ��ȣ������ʱ�õ��������������һ����ֵ�����ַ�����һ���ַ����ͼ�������
bool dfs(int r, int c, int idx) {
	if (idx == Word.length())//��ʱ˵��ƥ����ɣ�����true
		return true;
	int tr, tc;//��ǰ����
			   //��������������ƥ�俪ʼ�ĵط���ch�������浱ǰƥ���±����һ���ַ��������������visited���鵫��Ҫ�򵥺ܶ࣬
			   //��ƥ��ߵ���λ�ã���ĳһλƥ����ʱ��ͨ��swap������ʱ��Ԫ�غ���ǰһ��Ԫ�أ��������߻�ͷ·
	for (int i = 0; i < 4; i++) {
		tr = r + go[i][0];
		tc = c + go[i][1];
		//���Լ���ƥ��
		if (tr >= 0 && tc >= 0 && tr<m && tc<n && Board[tr][tc] == Word[idx] && visited[tr][tc] == 0) {
			visited[tr][tc]++;
			if (dfs(tr, tc, idx + 1))
				return true;
			visited[tr][tc]--;//�����˻ص���һ��
		}
	}
	return false;
}
bool exist(vector<vector<char>>& board, string word) {
	Board = board;
	Word = word;
	m = Board.size(), n = Board[0].size();
	//��ʼ��visited����
	visited.resize(m);
	for (int i = 0; i < m; i++)
		visited[i].resize(n);
	visited[0].resize(n);
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			visited[i][j] = 0;
	//������ĳ���괦�����ַ�����һ���������ҵ�������visited��ǲ�����ݹ�
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (Board[i][j] == Word[0] && visited[i][j] == 0) {
				visited[i][j]++;
				if (dfs(i, j, 1))
					return true;
				visited[i][j]--;
			}
	return false;
}
int main()
{
	vector<vector<char>> vec = { {'A','B','C','E'}, { 'S','F','C','S' }, { 'A','D','E','E' } };
	string str = "ABCCED";
	bool res = exist(vec, str);
	return 0;
}