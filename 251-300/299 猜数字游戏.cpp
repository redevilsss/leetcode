#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//299 ��������Ϸ

/*
�����ں���������� �����֣�Bulls and Cows����Ϸ����д��һ��������������Ѳ¡�ÿ�����²�������һ����ʾ���������ж���λ���ֺ�ȷ��λ�ö��¶��ˣ���Ϊ��Bulls��, ��ţ�����ж���λ���ֲ¶��˵���λ�ò��ԣ���Ϊ��Cows��, ��ţ����������ѽ��������ʾ�����£�ֱ���³��������֡�
��д��һ�������������ֺ����ѵĲ²���������ʾ�ĺ������� A ��ʾ��ţ���� B ��ʾ��ţ��
��ע���������ֺ����ѵĲ²��������ܺ����ظ����֡�
ʾ�� 1:
����: secret = "1807", guess = "7810"
���: "1A3B"
����: 1 ��ţ�� 3 ��ţ����ţ�� 8����ţ�� 0, 1 �� 7��
*/

//�������������ʵ�ܼ򵥣��ѵĵط����ڶ�������...
/*
bulls���ܺ��ң�ֻҪ���ַ�����Ӧλ����ȣ���ok
cows��ͨ��������ϣ����ʵ�֣��ֱ��¼ÿ�����ֳ��ֵĴ���
����ÿ�����ֳ��ֵĴ���������ϣ���Ӧλ�ý�С������ȷ��
cows��bulls�����ģ���bulls��϶�����cows������ͨ��ifelse��֧��ʵ��
*/
string getHint(string secret, string guess) {
	if (secret.length() == 0)
		return "";
	int i = 0;
	int bulls = 0;
	//�ֱ��¼���ַ����и����ֳ��ֵĸ���
	vector<int> flag1(10, 0);
	vector<int> flag2(10, 0);
	//��¼bulls��������
	while (i<secret.size())
	{
		if (secret[i] == guess[i])
			bulls++;
		else
		{
			flag1[secret[i]-'0']++;
			flag2[guess[i]-'0']++;
		}
		i++;
	}
	//��¼cows
	int cows = 0;
	for (int i = 0; i<10; i++)
		cows += min(flag1[i], flag2[i]);
	//ת�������ʽ
	string res = to_string(bulls);
	res += "A" + to_string(cows) + "B";
	return res;

}

int main()
{
	string secret = "1123", guess = "0111";
	string res = getHint(secret, guess);
	return 0;
}