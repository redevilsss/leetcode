#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��ʵ����ֻ���߶���һ���ܼ򵥵�Ӧ��
//�߶�����ʵ��֧���޸�ĳ��������Ԫ�ص�ֵ���޸ĵ���ֵ��ʵ��һ������
//֧�������޸ĵ��߶�����Ҫ�ڽڵ�����������addMark����ʱ���
struct SegTreeNode
{
	int val;  //������ֵ
	int len;  //�������䳤��
	int lazy; //�ӳٱ��
	int l, r;  //���Ҷ��ӱ��
	int addMark;//�ӳٱ��
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
	//����˼�룺�ݹ齨��������Ҷ�ӽڵ�ֱ�Ӹ�ֵ������ݹ�������ҽ����������ݼ��ɡ�
	void build(int root, int l, int r)  //���� 
	{
		int mid;
		tree[root].l = l; tree[root].r = r;
		tree[root].len = r - l + 1;
		if (l == r) tree[root].val = nums[l];
		else
		{
			mid = (l + r) / 2;
			build(root * 2, l, mid);     //�ݹ鹹��������
			build(root * 2 + 1, mid + 1, r); //�ݹ鹹��������
			tree[root].val = tree[root * 2].val + tree[root * 2 + 1].val;//�洢���������ĺ�
		}
	}
	//�ݹ���£��ݹ���Ҫ���µ�Ҷ�ӽڵ㣬���ݸ��Ĳ�������ͣ�����ǰҶ�ӽڵ㵽���ڵ�·���ϵĽڵ�ֵ
	void updateOne(int root, int index, int addval)  //������� 
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
	�ӳٱ�ǣ�ÿ���ڵ�������һ����ǣ���¼����ڵ��Ƿ������ĳ���޸�(�����޸Ĳ�����Ӱ�����ӽڵ�)��
	��������������޸ģ������Ȱ��������ѯ�ķ�ʽ���仮�ֳ��߶����еĽڵ㣬Ȼ���޸���Щ�ڵ����Ϣ��
	������Щ�ڵ����ϴ��������޸Ĳ����ı�ǡ����޸ĺͲ�ѯ��ʱ��������ǵ���һ���ڵ�p�����Ҿ����������ӽڵ㣬
	��ô���Ǿ�Ҫ���ڵ�p�Ƿ񱻱�ǣ�����У���Ҫ���ձ���޸����ӽڵ����Ϣ�����Ҹ��ӽڵ㶼������ͬ�ı�ǣ�ͬʱ�����ڵ�p�ı�ǡ�
	�����ڲ�ѯʱ���½ڵ�ֵ
	*/
	void pushDown(int root)
	{
		if (tree[root].addMark != 0)
		{
			//�������Һ��ӽڵ�ı�־����Ϊ���ӽڵ���ܱ�����ӳٱ����û�����´���
			//������ ��+=�����ۻ��ӳ�ֵ
			tree[root * 2].addMark += tree[root].addMark;
			tree[root * 2 + 1].addMark += tree[root].addMark;
			//���ݱ�־�����ú��ӽڵ��ֵ����Ϊ������������ͣ���˵�������ÿ��Ԫ
			//�ؼ���һ��ֵʱ�������Ҫ��len�������ֵ
			tree[root * 2].val += tree[root * 2].len*tree[root].addMark;
			tree[root * 2 + 1].val += tree[root * 2 + 1].len*tree[root].addMark;
			//���ݺ󣬵�ǰ�ڵ��������
			tree[root].addMark = 0;
		}
	}

	//�ݹ�������ͣ�ע��lazy��ǵĴ���
	int query(int root, int l, int r)  //��������� 
	{
		int mid;
		//��ǰ�ڵ���������ڲ�ѯ������
		if (tree[root].l >= l&&tree[root].r <= r)
			return tree[root].val;
		//��ѯ����͵�ǰ�ڵ�����û�н���
		if (tree[root].l>r || tree[root].r<l)
			return 0;
		//�ӳٸ��½ڵ�ֵ
		if (tree[root].addMark)
			pushDown(root);    //pushdown����----�ӳٱ�־�����´���
		return query(root * 2, l, r) + query(root * 2 + 1, l, r);
	}
	/*
	���������ָ����ĳ�������ڵ�Ҷ�ӽڵ��ֵ����Ϊ�漰����Ҷ�ӽڵ㲻ֹһ������Ҷ�ӽڵ��Ӱ������Ӧ�ķ�Ҷ���ڵ㣬��ô������Ҫ���µķ�Ҷ�ӽڵ�Ҳ���кܶ࣬
	���һ���Ը����꣬������ʱ�临�Ӷȿ϶�����O(lgn)�����統����Ҫ��������[0,3]�ڵ�Ҷ�ӽڵ�ʱ����Ҫ���³���Ҷ�ӽڵ�3,9������������ڵ㡣
	Ϊ���������߶����е��ӳٱ�Ǹ����Ҳ���߶����ľ������ڡ�
	*/
	void update(int root, int l, int r, int addval)  //������� 
	{
		//��ǰ�ڵ���������ڸ���������,��ʱֻ��Ҫ����addvalֵ��len��
		if (tree[root].l >= l&&tree[root].r <= r)
		{
			tree[root].addMark += addval;
			tree[root].val += tree[root].len*addval;
			return;
		}
		//��������͵�ǰ�ڵ�����û�н�����ֱ�ӷ���
		if (tree[root].l>r || tree[root].r<l)
			return;
		//�����ǰ�ڵ����ӳ٣�Ҫ���ϵ��¸��½ڵ�ֵ
		if (tree[root].addMark)
			pushDown(root); // �ӳٱ�����´��ݣ��������Һ��ӽڵ�
		update(root * 2, l, r, addval);
		update(root * 2 + 1, l, r, addval);
		//��������������ֵ���ݸ��µ�ǰ�ڵ��ֵ
		tree[root].val = tree[root * 2].val + tree[root * 2 + 1].val;
	}
	/*
	������¾���˵����������Ҫ������[0,2]��Ҷ�ӽڵ�����2�����������ѯ�ķ����Ӹ��ڵ㿪ʼ�ҵ��˷�Ҷ�ӽڵ�[0-2]��
	������ֵ����Ϊ1+2 = 3�����Ұ������ӳٱ������Ϊ2��������ϣ�
	������Ҫ��ѯ����[0,1]�ڵ���Сֵʱ�����ҵ�����[0,2]ʱ���������ı�ǲ�Ϊ0�����һ�Ҫ�������������Ҫ�ѱ�����´��ݣ�
	�ѽڵ�[0-1]��ֵ����Ϊ2+2 = 4���������Ϊ2���ڵ�[2-2]��ֵ����Ϊ1+2 = 3���������Ϊ2����ʵҶ�ӽڵ�ı�־�ǲ������õģ�������Ϊ�˲�����һ���ԣ���
	Ȼ�󷵻ز�ѯ�����[0-1]�ڵ��ֵ4���������ٴθ�������[0,1]������3��ʱ����ѯ���ڵ�[0-1],�������ı��ֵΪ2��
	��˰����ı��ֵ����Ϊ2+3 = 5���ڵ��ֵ����Ϊ4+3 = 7��
	*/
};