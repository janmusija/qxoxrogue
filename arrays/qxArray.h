//
// qxArray.h
// 2026-01-18
// qxoxrogue
//

#ifndef qxArray_h
#define qxArray_h

#include <vector>

/*
    class qxArray<T>

    important functions:
    get_next : size_type -> size_type, returns next position in array currently in use
    remove : size_type -> * remove something from the array.
    insert : T -> size_type add a new element to the array, and return its position in the array
    operator[] -> : size_type -> (const) reference : access any position in the array 
    
    Currently qxArray<T> is implemented as:
    vector of pairs (T, bool)

    running times for current implementations:
    get_next -> O(size) in worst case but O(1) on average (iterating through whole array is O(size)).
    remove -> O(1)
    insert -> unsure, but generally << O(size). typically O(1) if the array is full or if there is a block of unoccupied memory
    operator[] -> O(1)


    bools represent whether they are in use (true) or safe to overwrite (false)
*/

template < typename T> class qxArray{
    public:
    typedef std::vector<std::pair<T,bool>>              pairs_list_type;
    typedef T                                           value_type;
    typedef typename pairs_list_type::size_type		    size_type;
    typedef typename pairs_list_type::reference		    reference;
    typedef typename pairs_list_type::const_reference	const_reference;

    private:
    pairs_list_type pairs_list;
    size_type next_free;

    private:
    void increment_next_free(){ // this works even if next_free == pairs_list.size()
        while (++next_free < pairs_list.size() && (pairs_list[next_free].second())){}
    }
    
    public:
    qxArray(){
        next_free = 0;
    }

    size_type get_next (size_type n) const{ // return the next position in the array which is flagged as in use, or 0 otherwise (note "0" is never NEXT!)
        while (++n < pairs_list.size() && !(pairs_list[n].second())){}
        if (n < pairs_list.size()) {return n;}
        return 0;
    }

    bool remove(size_type n) { // return 0 if removed position was already flagged as removed
        bool b = pairs_list[n].second();
        if (n < next_free){next_free = n;}
        return b;
    }

    size_type insert(const T & __x) { // returns the position of the newly added object
        size_type pos = next_free;
        increment_next_free;
        if (pos > pairs_list.size()){
            pairs_list.push_back(__x);
        } else {
            pairs_list[pos].first() = __x;
            pairs_list[pos].second() = true;
        }
        return pos;
    }

    size_type size() { // returns the size of the array. does not 
        return pairs_list.size();
    }

    // element access
    reference operator[](size_type __n){
        return pairs_list[__n].first();
    }
    // const access
    const_reference operator[](size_type __n) const{
        return pairs_list[__n].first();
    }
    // check bool
    bool in_use(size_type __n) const{
        return pairs_list[__n].second();
    }

};

#endif // qxArray.h