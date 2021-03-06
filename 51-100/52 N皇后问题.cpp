#include<iostream>
using namespace std;

//52 N皇后2

/*
皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给定一个整数 n，返回 n 皇后不同的解决方案的数量。
示例:
输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[[".Q..", "...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
*/
//为什么位运算要快
//因为之前的判断+回溯法要考虑所有的情况，要一直循环完才返回结果，行还是不行，因为这个时候没有对前n行的结果进行总结，只是单纯的判断
//而位运算+回溯解N皇后问题时，如果到某一行发现在前面的限制下无法放置了就会返回

int res;//记录结果
int upperlim;//记录n位1作为标记
void test(int row, int ld, int rd)
{
	int p, pos;//pos表示目前行所能放置皇后的位置
	if (row == upperlim)
	{
		res++;
		return;
	}
	else
	{
		// row，ld，rd进行“或”运算，求得所有可以放置皇后的列,对应位为0，  
		// 然后再取反后“与”上全1的数，来求得当前所有可以放置皇后的位置，对应列改为1  
		pos = upperlim &(~(row | ld | rd));
		while (pos)    // 0 -- 皇后没有地方可放，回溯  
		{
			// 拷贝pos最右边为1的bit，其余bit置0  
			// 也就是取得可以放皇后的最右边的列  
			p = pos & (-pos);

			// 将pos最右边为1的bit清零  
			// 也就是为获取下一次的最右可用列使用做准备，  
			// 程序将来会回溯到这个位置继续试探  
			pos -= p;
			// row + p，将当前列置1，表示记录这次皇后放置的列。  
			// (ld + p) << 1，标记当前皇后左边相邻的列不允许下一个皇后放置。  
			// (ld + p) >> 1，标记当前皇后右边相邻的列不允许下一个皇后放置。  
			// 此处的移位操作实际上是记录对角线上的限制，只是因为问题都化归到一行网格上来解决，所以表示为列的限制就可以了。
			//显然，随着移位在每次选择列之前进行，原来N×N网格中某个已放置的皇后针对其对角线上产生的限制都被记录下来了  
			test(row + p, (ld | p) << 1, (rd | p) >> 1);
		}
	}
}

int totalNQueens(int n) {
	res = 0;
	upperlim = (1 << n) - 1;
	test(0, 0, 0);
	return res;
}
};


int main()
{
	int res=totalNQueens(4);
	return 0;

}

