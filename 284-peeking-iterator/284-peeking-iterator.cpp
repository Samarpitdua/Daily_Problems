/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
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
    vector<int> v;
    int ct = 0;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        v.resize(nums.size());
        v = nums;
        // for(auto x : v)
        //     cout<<x<<" ";
        ct = -1;
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return v[ct + 1];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        
	    ct++;
        return v[ct];
            
	}
	
	bool hasNext() const {
        if(ct == -1 or ct<(v.size()-1))
        {
            return true;
        }
        return false;
	}
};