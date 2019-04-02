#include<iostream>
#include<vector>
using namespace std;

//75 颜色分类

/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
注意:
不能使用代码库中的排序函数来解决这道题。
示例:
输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
*/

//思想：遇2放到尾，遇0放到头，遇1则继续，要注意2放到尾后原i处是i+1的值
void sortColors(vector<int>& nums) {
	//这个为什么要用三个变量，两个头，因为其中begin和end用来标记begin之前和end之后都是排好序的
	//每次把0挪到数组头后begin++，把2挪到数组尾时end--
	int begin = 0;
	int end = nums.size() - 1;
	int i = 0;
	//变量i表示当前遍历到的下标
	while (i <= end)
	{
		//此时把2拿出来，然后i到end的数左移，把2放到end处
		//注意这里为什么没有i++，因为当i位置的2拿走后，新的i位置的数字就是原来i+1的数字
		//要是i++,会错过这个数字
		if (nums[i] == 2)
		{
			for (int j = i; j<end; j++)
				nums[j] = nums[j + 1];
			nums[end] = 2;
			end--;
		}
		//此时把0拿出来，begin~i之间的数右移，把0放在begin处，此时的交换与i后面的数字无关，完成后i+1,
		else if (i != 0 && nums[i] == 0)
		{
			for (int j = i; j>begin; j--)
				nums[j] = nums[j - 1];
			nums[begin] = 0;
			begin++;
			i++;
		}
		else
			i++;
	}
}

int main()
{
	vector<int> vec = { 1,0,2,1,2,0 };
	sortColors(vec);
	return 0;
}