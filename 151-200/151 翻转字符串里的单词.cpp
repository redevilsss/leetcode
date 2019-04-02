#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//151 ��ת�ַ�����ĵ���

/*
����һ���ַ����������ת�ַ����е�ÿ�����ʡ�
ʾ�� 1��
����: "the sky is blue"
���: "blue is sky the"
ʾ�� 2��
����: "  hello world!  "
���: "world! hello"
����: �����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
*/


//��ָoffer�������Ƶ���
//˼·��
// 1.��ת��������
// 2.����������תÿ�����ʣ�������ָ����Ƶ��ʵ���β�����������õĳ�ʼֵΪ�յĽ���ַ�����

//��ת�ַ���s��begin��end
void reverse(int begin, int end, string& s)
{
	while (begin < end)
	{
		int temp = s[begin];
		s[begin] = s[end];
		s[end] = temp;
		begin++;
		end--;
	}
}

string reverseWords(string s)
{
	if (s.length() == 0)
		return "";
	//��ת�����ַ���
	reverse(0, s.length() - 1, s);
	string res;
	int left = 0;
	int right = 0;
	int end = s.length();
	while (left<end)
	{
		//�����ո��ҵ���һ���ǿ��ַ�
		while (left<end&&s[left] == ' ')
			left++;
		//�������ĩβ��ֱ���˳�
		if (left == end)
			break;
		//����right������ǰ������һ���ո�
		right = left;
		while (right<end&&s[right] != ' ')
			right++;
		//left��right-1֮����ַ����һ�����ʣ��������ո񣩣�right��ʱָ��ո�right-1Ϊ�������һ����ĸ�������ʷ�ת
		reverse(left, right - 1,s);
		string subS = s.substr(left, right - left);//ȡ������
		res += subS + ' ';//�𲽹������ַ���
		left = right;//������leftֵ
	}
	return res.substr(0,res.size()-1);

}
int main()
{
	string s = "  hello world!    ";
	string res = reverseWords(s);
	return 0;
}