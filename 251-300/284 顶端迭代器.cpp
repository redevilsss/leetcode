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

//在class Iterator的基础上设计一个class PeekingIterator。主要是增加一个peek()方法。该方法获得和调用next()一样的值，但是迭代器不移动。
//next和hasNext可以通过调用Iterator类实现，则新类中需要做的就是定义一个标记，isPeek用来表示上一步为peek操作，value记录值
//如果上一步为peek操作，那么next返回的就是value值，否则直接调用原next函数,注意此时isPeek将失效，因为保存的值为value的元素已经弹出了
//如果上一步为peek操作，那么hasNext返回的就是true，因为刚peek完说明还有元素在，否则直接调用原hasNext函数
//peek操作时，如果上一步为peek，那说明peek了两次，第二次可以直接用第一次的结果，否则，置isPeek为true，返回原next的值给value，返回value
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