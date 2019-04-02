#include<iostream>
using namespace std;

//278 ��һ������汾

/*
���ǲ�Ʒ����Ŀǰ���ڴ���һ���Ŷӿ����µĲ�Ʒ�����ҵ��ǣ���Ĳ�Ʒ�����°汾û��ͨ��������⡣����ÿ���汾���ǻ���֮ǰ�İ汾�����ģ����Դ���İ汾֮������а汾���Ǵ�ġ�
�������� n ���汾 [1, 2, ..., n]�������ҳ�����֮�����а汾����ĵ�һ������İ汾��
�����ͨ������ bool isBadVersion(version) �ӿ����жϰ汾�� version �Ƿ��ڵ�Ԫ�����г���ʵ��һ�����������ҵ�һ������İ汾����Ӧ�þ������ٶԵ��� API �Ĵ�����
ʾ��:
���� n = 5������ version = 4 �ǵ�һ������İ汾��
���� isBadVersion(3) -> false
���� isBadVersion(5) -> true
���� isBadVersion(4) -> true
���ԣ�4 �ǵ�һ������İ汾��
*/


//���ֲ��Ҽ��ɣ�ע�����mid��ʱ������(end - start) / 2 + start)������(end + start) / 2�����߿��ܻ����

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int start = 1;
		int end = n;
		int res = 1;
		while (start <= end)
		{
			int mid = (end - start) / 2 + start;
			if (isBadVersion(mid))
			{
				res = mid;
				end = mid - 1;
			}
			else
				start = mid + 1;
		}
		return res;
	}
};