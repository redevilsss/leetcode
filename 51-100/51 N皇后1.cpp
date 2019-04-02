#include<iostream>
#include<vector>
#include<string>
using namespace std;

//51 N�ʺ�1

/*
�ʺ������о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������
����һ������ n������ n �ʺ�ͬ�Ľ��������������
ʾ��:
����: 4
���: 2
����: 4 �ʺ������������������ͬ�Ľⷨ��
[[".Q..", "...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
*/

//˼·���õݹ�����
//��Ҫ����Ŀռ�����¼��λ���Ƿ���Է��ûʺ󣬹�����������ֱ��ʾ�У��Խ��ߺͷ��Խ��ߵķ������
//�����ɱ������Ƶģ�ÿһ��ֻ����һ��λ�÷Żʺ�
//index������¼��ǰ���õ�������

vector<vector<string>> res;
vector<int> visitedCol;
vector<int> visitedDia1;
vector<int> visitedDia2;
vector<vector<string>> solveNQueens(int n)
{
	visitedCol.resize(n);
	visitedDia1.resize(2 * n - 1);//15���Խ��� ���ϵ�����
	visitedDia2.resize(2 * n - 1);//15�����Խ��� ���µ�����
	vector<int> temp;
	dfs(temp, 0, n);
	return res;
}
void dfs(vector<int>& temp, int index, int n)//index��ʾĿǰƥ�䵽�˵ڼ��У����ܺ���
{
	if (index == n)
	{
		vector<string> board(n, string(n, '.'));
		for (int i = 0; i<n; i++)
			board[i][temp[i]] = 'Q';
		res.push_back(board);
		return;
	}
	for (int i = 0; i<n; i++)//i��ʾ�У�Ҳ����˵���ѭ����Ե��ǵ�index�е�i�У������λ���ܲ��ܷŽ����жϣ��ܷžͷţ����ܷžͿ���һ��λ��
		if (!visitedCol[i] && !visitedDia1[index + i] && !visitedDia2[index - i + n - 1])
		{
			temp.push_back(i);
			visitedCol[i]++;
			visitedDia1[index + i]++;//����������
			visitedDia2[index - i + n - 1]++;//�����ӣ�������-1-������
			dfs(temp, index + 1, n);
			visitedCol[i]--;
			visitedDia1[index + i]--;
			visitedDia2[index - i + n - 1]--;
			temp.pop_back();
		}
	return;
}