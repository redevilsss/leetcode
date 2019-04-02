#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//84 ��״ͼ�����ľ���

/*
���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��
���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������
����: [2,1,5,6,2,3]
���: 10
*/

//��������...û�а취�İ취
int largestRectangleArea1(vector<int>& heights) {
	int n = heights.size();
	if (n == 0) return 0;
	int maxSquare = 0;
	int curSquare = 0;
	for (int i = 0; i<n - 1; i++)
	{
		int height = heights[i];
		for (int j = i; j<n; j++)
		{
			height = min(height, heights[j]);
			curSquare = (j - i + 1)*height;
			if (curSquare>maxSquare)
				maxSquare = curSquare;
		}
	}
	if (maxSquare < heights[n - 1])
		maxSquare = heights[n - 1];
	return maxSquare;
}
//����ջʵ��
//ʹ�õ�����ջ��һ����ջһ�γ�ջ�������
//��ʵ����������������ÿ������Ϊ�ߵ��������������бȽ�
//�����������ѭ��������������˼·�Ǻ������ĵ������㸴�ӶȻ�ܸߣ����䵱����ܳ���ʱ��
//��������˵�����ջ��ʹ��ͨ��һ����ջ��ջ�ͽ��������
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
			else//��ջ�ǿգ���ʱ�������ֵΪs.top()+1(��Ϊ�ղų�ջ���ʱ��top��ֵ��С�ڸø߶ȵ�)
				//��s.top()�±���Ҳ࣬���±�s.top()+1��ֵ�Ǵ��ڵ��ڸø߶ȵ�
				curSquare = heights[temp] * (i-s.top()-1);//�������(i-1)-(s.top()+1)+1
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

int main()
{
	vector<int> heights = { 2,1,5,6,2,3 };
	int res = largestRectangleArea(heights);
	return 0;

}