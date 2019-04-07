#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//307 区域和检索
/*
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。
示例:
Given nums = [1, 3, 5]
sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
*/
//方法一
/*
使用线段树来求解
开始之前先了解线段树的概念
线段树是一种平衡二叉搜索树（完全二叉树），他将一个线段区间划分成一些单元区间。对于线段树中的每个非叶子节点 [a,b]，他的左儿子表示的区间为 [ a, (a+b)/2] ，右儿子表示的区间为 [(a+b)/2+1, b] , 最后的叶子节点数目为 N， 与数组下标对应。
线段树的一般包括建立、查询、插入、更新等操作，建立规模为 N 的时间复杂度是 O(nlogn)，其他操作时间复杂度为O(logn)。
一般而言，线段树都有两个成员函数
query用于实现功能，如取最大值、取最小值、求区间和等
update用于更新某个叶子节点的值，叶子节点的值更新后，需要将从根到该叶子路径上所有的节点值进行更新

这里采用之前在youtube上看到的一种方法来实现，我现在需要构建一个类似于二叉树的数组
每个节点都是数组的部分和
比如nums为[0,1,2,3,4,5]
那么我把nums数组元素作为叶子节点构建二叉树数组，构造的新的线段树数组长度应该为2*nums.size()
其中后一半保存叶子节点，即nums元素，前一半则作为父节点保存相应的值,这个值具体保存什么视题目而定，本题要求区间和，所以父节点i保存的是左子节点2i和右子节点2i+1的和
如下图所示
值：       X   sum(6,11) sum(8,11)  sum(6,7)   sum(8,9) sum(10,11)    1       2       3       4       5       6
下标：     0       1         2          3         4         5         6       7       8       9       10      11

如上图所示先构造线段树，sum(a,b)表示下标从a到b的和
*/
class NumArray {
public:
	//初始化线段树，重点在于线段树的构造，复杂度为o(n)
	NumArray(vector<int> nums) {
		tree.resize(nums.size() * 2);
		size = nums.size();
		buildTree(nums);
	}
	//更新某一个值，则相应的有这个值在的所有区间和也要更新，即该叶子节点的所有父节点的值要修改
	void update(int i, int val) {
		i += size;
		//修改叶子节点
		tree[i] = val;
		//修改相关的所有父节点值
		while (i>0)
		{
			int left, right;
			//i下标为偶数，为父节点的左子节点
			if (i % 2 == 0)
			{
				left = i;
				right = i + 1;
			}
			//i下标为奇数，为父节点的右子节点
			else
			{
				right = i;
				left = i - 1;
			}
			//修改父节点的值
			tree[i / 2] = tree[right] + tree[left];
			i /= 2;
		}
	}
	//区间查询
	/*
	区间查询大体上可以分为3种情况讨论： 
	1. 当前结点所代表的区间完全位于给定需要被查询的区间之外，则不应考虑当前结点 
	2. 当前结点所代表的区间完全位于给定需要被查询的区间之内，则可以直接查看当前结点的母结点 
	3. 当前结点所代表的区间部分位于需要被查询的区间之内，部分位于其外，则我们先考虑位于区间外的部分，后考虑区间内的
	（注意总有可能找到完全位于区间内的结点，因为叶子结点的区间长度为1，因此我们总能组合出合适的区间）
	*/
	//求从下标i到j的和，即求tree数组从size+i到size+j的和
	int sumRange(int i, int j) {
		i += size;
		j += size;
		int sum = 0;
		while (i <= j)
		{
			//如果下标i为父节点的右子树，则sum叠加其值，i+1，此时i为其父节点的左子树
			if (i % 2 == 1)
				sum += tree[i++];
			//如果下标j为父节点的左子树，则sum叠加其值，j-1，此时j为其父节点的右子树
			if (j % 2 == 0)
				sum += tree[j--];
			//为什么要进行上面的操作呢？因为当i表示左子树而j表示右子树的时候，才可以直接取其父节点的值，否则当前所有节点并不都是成对存在的(即所有的节点两两互为左右兄弟)
			//以上面的数组为例，求下标1~4的和，把对应的树画出来可以看到结果是2、3、4、5的和，而3、4的父节点值就是和
			//这块的处理其实类似于递归，每一步判断i和j为左还是右子节点，再根据情况来选择是否加
			//这里我能理解但是说不清楚
			i /= 2;
			j /= 2;
		}
		return sum;
	}

	void buildTree(vector<int> nums)
	{
		//先将nums数组元素，即叶子节点放入新tree数组的后一半
		for (int i = 0; i<nums.size(); i++)
			tree[i + nums.size()] = nums[i];
		//填充下标1到nums.size-1，也就是二叉树的父节点，有tree[i]=tree[2*i]+tree[2*i+1]
		for (int i = size - 1; i>0; i--)
			tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
private:
	vector<int> tree;
	int size;
};

//方法二：树状数组
/*
引入一种数据结构 - 树状数组 ( Binary Indexed Tree，BIT，二分索引树 )，它只有两种基本操作，并且都是操作线性表的数据的：
1、add( i, 1 )      (1<=i<=n)                       对第i个元素的值自增1           O(logn)
2、sum( i )         (1<=i<=n)                       统计[1...i]元素值的和             O(logn)
试想一下，如果用HASH来实现这两个函数，那么1的复杂度是O(1)，而2的复杂度就是O(n)了，而树状数组实现的这两个函数可以让两者的复杂度都达到O(logn)，具体的实现先卖个关子，留到第二节着重介绍。
有了这两种操作，我们需要将它们转化成之前设计的数据结构的那三种操作，首先：
1、插入(Insert)，对应的是 add(i, 1)，时间复杂度O( logn )
2、删除(Delete), 对应的是 add(i, -1), 时间复杂度O( logn )
3、询问(Query), 由于sum( i )能够统计[1...i]元素值的和，换言之，它能够得到我们之前插入的数据中小于等于i的数的个数，那么如果能够知道sum(i) >= r + 1的最小的i，那这个i就是所有插入数据的中位数了（因为根据上文的条件，插入的数据时刻保证有2r+1个）。因为sum(i)是关于 i 的递增函数，所以基于单调性我们可以二分枚举i (1 <= i <= n)，得到最小的 i 满足sum(i) >= r + 1，每次的询问复杂度就是 O( logn * logn )。 一个logn是二分枚举的复杂度，另一个logn是sum函数的复杂度。
结点的含义
然后我们来看树状数组上的结点Ci具体表示什么，这时候就需要利用树的递归性质了。我们定义Ci的值为它的所有子结点的值 和 Ai 的总和，之前提到当i为奇数时Ci一定为叶子结点，所以有Ci = Ai  ( i为奇数 )。从图中可以得出：
C1 = A1
C2 = C1 + A2 = A1 + A2
C3 = A3
C4 = C2 + C3 + A4 = A1 + A2 + A3 + A4
C5 = A5
C6 = C5 + A6 = A5 + A6
C7 = A7
C8 = C4 + C6 + C7 + A8 = A1 + A2 + A3 + A4 + A5 + A6 + A7 + A8
建议直接看C8，因为它最具代表性。
我们从中可以发现，其实Ci还有一种更加普适的定义，它表示的其实是一段原数组A的连续区间和。根据定义，右区间是很明显的，一定是i，即Ci表示的区间的最后一个元素一定是Ai，那么接下来就是要求Ci表示的第一个元素是什么。从图上可以很容易的清楚，其实就是顺着Ci的最左儿子一直找直到找到叶子结点，那个叶子结点就是Ci表示区间的第一个元素。
更加具体的，如果i的二进制表示为 ABCDE1000，那么它最左边的儿子就是 ABCDE0100，这一步是通过结点父子关系的定义进行逆推得到，并且这条路径可以表示如下：
ABCDE1000 => ABCDE0100 => ABCDE0010 => ABCDE0001
这时候，ABCDE0001已经是叶子结点了，所以它就是Ci能够表示的第一个元素的下标，那么我们发现，如果用k来表示i的二进制末尾0的个数，Ci能够表示的A数组的区间的元素个数为2^k，又因为区间和的最后一个数一定是Ai，所以有如下公式：
Ci  =  sum{ A[j] |  i - 2^k + 1 <= j <= i }    （帮助理解：将j的两个端点相减+1 等于2^k）
*/
class NumArray {
private:
	vector<int> c;//部分和数组
	vector<int> m_nums;//原数组
public:
	//初始化两个数组，注意部分和数组c的有效元素下标从1开始到nums.size()结束
	NumArray(vector<int> nums)
	{
		c.resize(nums.size() + 1);
		m_nums = nums;
		//初始化部分和数组
		for (int i = 0; i < nums.size(); i++) {
			add(i + 1, nums[i]);
		}
	}
	/*
	明白了Ci的含义后，我们需要通过它来求sum{ A[j] | 1 <= j <= i }，也就是之前提到的sum(i)函数。
	为了简化问题，用一个函数lowbit(i)来表示2^k (k等于i的二进制表示中末尾0的个数)。那么：
	sum(i) = sum{ A[j] | 1 <= j <= i }
	= A[1] + A[2] + ... + A[i]
	= A[1] + A[2] + A[i-2^k] + A[i-2^k+1] + ... + A[i]
	= A[1] + A[2] + A[i-2^k] + C[i]
	= sum(i - 2^k) + C[i]
	= sum( i - lowbit(i) ) + C[i]
	*/
	//pos-lowbit(pos)表示去掉pos二进制最右的1，最终变为0
	//将pos按照上述过程从pos降到0，累计c[pos]和可以得到前pos项和，其实就是对应的树所有子节点的和
	//pos+lowbit(pos)表示给pos二进制的值加1或再最右补0，最终变为size
	//将pos按照上述过程从pos升到size，其实就是遍历从根节点到子节点更新节点值
	int lowbit(int pos)
	{
		return pos&(-pos);
	}
	//更新下标c[pos]，初始化和每次update需要用到
	/*
	每次修改的是c数组pos以后的位置，因为c[pos]表示的是下标从i(大于等于1)~pos的和，当pos位置变化时只会影响到pos及以后位置
	举例：add(5,2)
	给c[5] c[6] c[7]都加2
	*/
	void add(int pos, int value) {
		while (pos < c.size()) {
			c[pos] += value;
			pos += lowbit(pos);
		}
	}
	/*求前pos个数的和
	sum(7)=c[111]+c[110]+c[100]=a[7]+a[5]+a[6]+a[1]+a[2]+a[3]+a[4]
	求前pos个和只关注前pos个数，这个过程对应到树上其实就是求树的子节点值之和
	*/
	int sum(int pos) {
		int res = 0;
		while (pos > 0) {
			res += c[pos];
			pos -= lowbit(pos);
		}
		return res;
	}
	//完成更新需要分别更新两个数组，m_nums只需变化相应位置，但是c数组需要更改的位置不止一处，包含m_nums[pos]这一元素的部分和都要进行修改，比如，update(3,2),那么c[3] c[4] c[8]都需要修改
	//对应到树，就是从根节点一直遍历向上直到c[size]
	void update(int i, int val) {
		int ori = m_nums[i];
		int delta = val - ori;
		m_nums[i] = val;
		add(i + 1, delta);
	}
	//求部分和，很简单，注意sum(j+1)其实表示的就是从下标0到下标j的和，sum(i)表示的是下标0到i-1的和
	int sumRange(int i, int j) {
		return sum(j + 1) - sum(i);
	}
};




int main()
{
	vector<int> nums = { 1,2,3,4,5,6 };
	NumArray n(nums);
	int res1 =  n.sumRange(0, 2);
	n.update(1, 2);
	int res2 = n.sumRange(0, 2);
	return 0;
}