#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//85 ������

/*
����һ�������� 0 �� 1 �Ķ�ά�����ƾ����ҳ�ֻ���� 1 �������Σ��������������
����:
[["1","0","1","0","0"],
 ["1","0","1","1","1"],
 ["1","1","1","1","1"],
 ["1","0","0","1","0"]]
���: 6
*/

//��������һ��˼·��ͬ��ֻ��Ҫ�Ƚ��ַ�������һ���Ĵ��������־���
//Ȼ����Ǽ��������״ͼ���ֵ������
//����������Ϊ����ת�����ľ���Ϊ
/*
** 1 0 1 0 0
** 2 0 2 1 1
** 3 1 3 2 2
** 4 0 0 3 0
*/
//Ȼ�����������ÿһ�н���84����һ�������㴦��������ֵ
//ע�⣬����ĳһ��ĳһ��Ԫ��֮���ж��ٸ�1��ֻҪ�����괦Ϊ0�����־����ڸô�ֵ��Ϊ0

int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return 0;
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>> heights(m, vector<int>(n, 0));
	int maxSquare = 0;
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			if (i == 0)
			{
				//�ȳ�ʼ����һ��
				if (matrix[i][j] == '1')
					heights[i][j] = 1;
			}
			if (i != 0 && matrix[i][j] == '1')
			{
				//����Ե�һ��Ϊ��׼����ת��
				if (matrix[i][j] == '1')
					heights[i][j] = 1 + heights[i - 1][j];
			}
		}
		maxSquare = max(maxSquare, largestRectangleArea(heights[i]));
	}
	return maxSquare;
}


int largestRectangleArea(vector<int>& heights) {
	int len = heights.size();
	if (len == 0)
		return 0;
	int maxSquare = 0;//���ֵ
	int curSquare = 0;//�ֲ����ֵ
	int i = 0;
	stack<int> s;//���ڴ洢�±��ջ
	while (i < len)
	{
		//���ջΪ�ջ򼴽���ջ�±괦��Ԫ����ջ����Ȼ��������ʱ�����±��ջ�����±�ֵ+1
		if (s.empty() || heights[s.top()] <= heights[i])
			s.push(i++);
		else
		{
			//����˵����ʱջ���±��Ӧ�ĸ߶ȴ��ڼ�����ջ�±��Ӧ�ĸ߶�
			//˵����ʱ��ջ���±��Ӧ�߶�Ϊ��͵�ľ��ο������ֵΪ������ջ�±�-1��Ҳ����i-1
			int temp = s.top();//����ջ���±�ֵ������ջ���±�
			s.pop();
			//�����Դ˸߶�Ϊ��͵�ľ���������������һ���ֲ����ֵ
			if (s.empty())//��ջΪ�գ�ֱ���øø߶ȳ˵�ǰ�±꣬Ҳ����˵��ʱ�������ֵ��0
				curSquare = heights[temp] * i;//������Կ�����ջ���±�Ϊ-1
			else//��ջ�ǿգ���ʱ�������ֵΪs.top()+1(��Ϊ�ղų�ջ���ʱ��top��ֵ��С�ڸø߶ȵ�)				//��s.top()�±���Ҳ࣬���±�s.top()+1��ֵ�Ǵ��ڵ��ڸø߶ȵ�
				curSquare = heights[temp] * (i - s.top() - 1);//�������(i-1)-(s.top()+1)+1
		}
		//�������ֵ
		if (maxSquare < curSquare)
			maxSquare = curSquare;
	}
	//��ǰ��ͬ����ʱ��i��ָ��λ�����������ӵ����
	while (!s.empty())
	{
		int temp = s.top();
		s.pop();
		if (s.empty())
			curSquare = heights[temp] * i;
		else
			curSquare = heights[temp] * (i - s.top() - 1);
		if (maxSquare < curSquare)
			maxSquare = curSquare;
	}
	return maxSquare;

}