/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    this->_flag = false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!this->_flag) _value = Iterator::next();
        _flag = true;
        return _value;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (!this->_flag) return Iterator::next();
        this->_flag = false;
        return this->_value;
	}
	
	bool hasNext() const {
	     return this->_flag || Iterator::hasNext();
	}
    private:
        bool _flag;
        int _value;
};