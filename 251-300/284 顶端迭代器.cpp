#include<iostream>
#include<vector>
using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

//��class Iterator�Ļ��������һ��class PeekingIterator����Ҫ������һ��peek()�������÷�����ú͵���next()һ����ֵ�����ǵ��������ƶ���
//next��hasNext����ͨ������Iterator��ʵ�֣�����������Ҫ���ľ��Ƕ���һ����ǣ�isPeek������ʾ��һ��Ϊpeek������value��¼ֵ
//�����һ��Ϊpeek��������ônext���صľ���valueֵ������ֱ�ӵ���ԭnext����,ע���ʱisPeek��ʧЧ����Ϊ�����ֵΪvalue��Ԫ���Ѿ�������
//�����һ��Ϊpeek��������ôhasNext���صľ���true����Ϊ��peek��˵������Ԫ���ڣ�����ֱ�ӵ���ԭhasNext����
//peek����ʱ�������һ��Ϊpeek����˵��peek�����Σ��ڶ��ο���ֱ���õ�һ�εĽ����������isPeekΪtrue������ԭnext��ֵ��value������value
class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		this->isPeek = false;
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if (this->isPeek)
			return value;
		this->isPeek = true;
		return this->value = Iterator::next();
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (this->isPeek)
		{
			this->isPeek = false;
			return this->value;
		}
		return Iterator::next();
	}

	bool hasNext() const {
		if (this->isPeek)
			return true;
		return Iterator::hasNext();
	}

private:
	bool isPeek;
	int value;
};