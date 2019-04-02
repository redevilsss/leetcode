#include<iostream>
#include<vector>
using namespace std;
//169 求众数

/*
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在众数。
示例 1:
输入: [3,2,3]
输出: 3
*/

//这道题也可以记录每个数出现的次数去但是太麻烦了
/*
这个题就是剑指offer上39题，方法如下：
从头到尾遍历数组，初始时设置nums[0]为temp值，设置times=1，表示当前times连续出现了1次
如果下一个元素和temp相同，times+1，否则times-1，times为0时修改temp值为当前值，times置为1
考虑一下极端情况，当数组共2n+1个数，而某个数出现n+1次时，只有当这个数出现的位置分别时下标0 2 4....直到2n时，times不会+1，但此时保存的temp会是nums[2n]，同样是这个数
无论如何，times为0说明前面的非众数和众数一样多，那么剩余数组中必然众数比非众数多，这样数组遍历完时，temp一定是众数
*/
int majorityElement(vector<int>& nums) {
	int times = 1;
	int temp = nums[0];
	for (int i = 1; i<nums.size(); i++)
	{
		if (times == 0)
		{
			temp = nums[i];
			times = 1;
		}
		else if (nums[i] == temp)
			times++;
		else
			times--;
	}
	return temp;

}