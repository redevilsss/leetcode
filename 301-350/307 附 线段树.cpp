#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//其实这里只是线段树一个很简单的应用
//线段树其实还支持修改某区间所有元素的值，修改单个值其实是一个特例
//支持区间修改的线段树需要在节点中新增变量addMark，延时标记
struct SegTreeNode
{
	int val;  //具体数值
	int len;  //覆盖区间长度
	int lazy; //延迟标记
	int l, r;  //左右儿子编号
	int addMark;//延迟标记
};

class SegTree
{
private:
	vector<SegTreeNode> tree;
	vector<int> nums;
public:
	SegTree()
	{
		this->tree.resize(nums.size() * 2);
		build(1, 1, tree.size() - 1);
	}
	//建树思想：递归建树，遇到叶子节点直接赋值，否则递归遍历左右建树，最后回溯即可。
	void build(int root, int l, int r)  //建树 
	{
		int mid;
		tree[root].l = l; tree[root].r = r;
		tree[root].len = r - l + 1;
		if (l == r) tree[root].val = nums[l];
		else
		{
			mid = (l + r) / 2;
			build(root * 2, l, mid);     //递归构造左子树
			build(root * 2 + 1, mid + 1, r); //递归构造右子数
			tree[root].val = tree[root * 2].val + tree[root * 2 + 1].val;//存储左右子树的和
		}
	}
	//递归更新，递归至要更新的叶子节点，回溯更改部分区间和，即当前叶子节点到跟节点路径上的节点值
	void updateOne(int root, int index, int addval)  //单点更新 
	{
		int mid;
		if (tree[root].l == tree[root].r)
		{
			tree[root].val += addval;
			return;
		}
		else
		{
			mid = (tree[root].l + tree[root].r) / 2;
			if (index <= mid) updateOne(root * 2, index, addval);
			else updateOne(root * 2 + 1, index, addval);
			tree[root].val = tree[root * 2].val + tree[root * 2 + 1].val;
		}
	}

	/*
	延迟标记：每个节点新增加一个标记，记录这个节点是否进行了某种修改(这种修改操作会影响其子节点)，
	对于任意区间的修改，我们先按照区间查询的方式将其划分成线段树中的节点，然后修改这些节点的信息，
	并给这些节点标记上代表这种修改操作的标记。在修改和查询的时候，如果我们到了一个节点p，并且决定考虑其子节点，
	那么我们就要看节点p是否被标记，如果有，就要按照标记修改其子节点的信息，并且给子节点都标上相同的标记，同时消掉节点p的标记。
	用于在查询时更新节点值
	*/
	void pushDown(int root)
	{
		if (tree[root].addMark != 0)
		{
			//设置左右孩子节点的标志域，因为孩子节点可能被多次延迟标记又没有向下传递
			//所以是 “+=”，累积延迟值
			tree[root * 2].addMark += tree[root].addMark;
			tree[root * 2 + 1].addMark += tree[root].addMark;
			//根据标志域设置孩子节点的值。因为我们是求区间和，因此当区间内每个元
			//素加上一个值时，区间和要加len倍的这个值
			tree[root * 2].val += tree[root * 2].len*tree[root].addMark;
			tree[root * 2 + 1].val += tree[root * 2 + 1].len*tree[root].addMark;
			//传递后，当前节点标记域清空
			tree[root].addMark = 0;
		}
	}

	//递归求区间和，注意lazy标记的传递
	int query(int root, int l, int r)  //计算区间和 
	{
		int mid;
		//当前节点区间包含在查询区间内
		if (tree[root].l >= l&&tree[root].r <= r)
			return tree[root].val;
		//查询区间和当前节点区间没有交集
		if (tree[root].l>r || tree[root].r<l)
			return 0;
		//延迟更新节点值
		if (tree[root].addMark)
			pushDown(root);    //pushdown操作----延迟标志域向下传递
		return query(root * 2, l, r) + query(root * 2 + 1, l, r);
	}
	/*
	区间更新是指更新某个区间内的叶子节点的值，因为涉及到的叶子节点不止一个，而叶子节点会影响其相应的非叶父节点，那么回溯需要更新的非叶子节点也会有很多，
	如果一次性更新完，操作的时间复杂度肯定不是O(lgn)，例如当我们要更新区间[0,3]内的叶子节点时，需要更新出了叶子节点3,9外的所有其他节点。
	为此引入了线段树中的延迟标记概念，这也是线段树的精华所在。
	*/
	void update(int root, int l, int r, int addval)  //区间更新 
	{
		//当前节点区间包含在更新区间内,此时只需要加上addval值的len倍
		if (tree[root].l >= l&&tree[root].r <= r)
		{
			tree[root].addMark += addval;
			tree[root].val += tree[root].len*addval;
			return;
		}
		//更新区间和当前节点区间没有交集，直接返回
		if (tree[root].l>r || tree[root].r<l)
			return;
		//如果当前节点有延迟，要从上到下更新节点值
		if (tree[root].addMark)
			pushDown(root); // 延迟标记向下传递，更新左右孩子节点
		update(root * 2, l, r, addval);
		update(root * 2 + 1, l, r, addval);
		//根据左右子树的值回溯更新当前节点的值
		tree[root].val = tree[root * 2].val + tree[root * 2 + 1].val;
	}
	/*
	区间更新举例说明：当我们要对区间[0,2]的叶子节点增加2，利用区间查询的方法从根节点开始找到了非叶子节点[0-2]，
	把它的值设置为1+2 = 3，并且把它的延迟标记设置为2，更新完毕；
	当我们要查询区间[0,1]内的最小值时，查找到区间[0,2]时，发现它的标记不为0，并且还要向下搜索，因此要把标记向下传递，
	把节点[0-1]的值设置为2+2 = 4，标记设置为2，节点[2-2]的值设置为1+2 = 3，标记设置为2（其实叶子节点的标志是不起作用的，这里是为了操作的一致性），
	然后返回查询结果：[0-1]节点的值4；当我们再次更新区间[0,1]（增加3）时，查询到节点[0-1],发现它的标记值为2，
	因此把它的标记值设置为2+3 = 5，节点的值设置为4+3 = 7。
	*/
};