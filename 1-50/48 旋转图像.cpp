#include<iostream>
#include<vector>
using namespace std;

// 48 旋转图像
/*
给定一个 n × n 的二维矩阵表示一个图像。
将图像顺时针旋转 90 度。
说明：
你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
示例 1:
给定 matrix =
[[1,2,3],[4,5,6],[7,8,9]],
原地旋转输入矩阵，使其变为:
[[7,4,1],[8,5,2],[9,6,3]]
*/


//这类题目最重要的就是要观察，旋转一层一层展开
//每一层的循环次数不定，每一次循环需要顺时针改变四个位置的值
//重点在于理清整个的过程，取好层数和循环次数
void rotate(vector<vector<int>>& matrix) {
	int rotateRange = matrix.size() - 1;
	//旋转层数为矩阵的行数/2，若为偶则没有中心，若为奇则中间一点不用变
	for (int i = 0; i<matrix.size() / 2; i++)
	{
		//设置旋转起始点
		int startIndex1 = i;
		int startIndex2 = i;
		//每一层的循环次数为行数-1-2*i，第一层循环行数-1次，以此类推
		for (int j = 0; j<matrix.size() - 2 * i - 1; j++)
		{
			//进行交换的四个坐标有一定的关联，通过rotateRange来实现转换
			//rotateRange是一个定值，等于行数-1
			int temp = matrix[startIndex1][startIndex2];
			matrix[startIndex1][startIndex2] = matrix[rotateRange - startIndex2][startIndex1];
			matrix[rotateRange - startIndex2][startIndex1] = matrix[rotateRange - startIndex1][rotateRange - startIndex2];
			matrix[rotateRange - startIndex1][rotateRange - startIndex2] = matrix[startIndex2][rotateRange - startIndex1];
			matrix[startIndex2][rotateRange - startIndex1] = temp;
			startIndex2++;
		}
	}
}

int main()
{
	vector<vector<int>> vec = { {5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16} };
	rotate(vec);
	return 0;
}