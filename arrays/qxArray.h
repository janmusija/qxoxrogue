//
// qxArray.h
// 2026-01-18
// qxoxrogue
//

#ifndef qxArray_h
#define qxArray_h

#include <memory>
#include <unordered_map>

/*
    class qxArray<T>

    important functions:
    iterator
    remove : size_type -> * remove something from the array.
    insert : T -> size_type add a new element to the array, and return its position in the array
    operator[] -> : size_type -> (const) reference : access any position in the array 
    
    Currently qxArray<T> is implemented as:
    unordered_map<int,std::unique_ptr<T>>

    running times for current implementations:
    remove -> O(1)
    insert -> unsure, but generally << O(size). typically O(1) if the array is full or if there is a block of unoccupied memory
    operator[] -> O(1)


    bools represent whether they are in use (true) or safe to overwrite (false)
*/

template < typename T> class qxArray{ // a map larping as a noncontiguous vector
    public:
    typedef std::unordered_map<int,std::unique_ptr<T>>  ulm_type; // (u)nder(l)ying (m)ap
    typedef T                                           value_type;
    typedef typename ulm_type::key_type		    size_type;
    typedef T &		                            reference;
    typedef const T &                        	const_reference;
    typedef typename ulm_type::iterator		    iterator;
    typedef typename ulm_type::const_iterator	const_iterator;

    private:
    ulm_type ulm;
    size_type next_free;

    private:
    void increment_next_free(){ // this works even if next_free == ulm.size()
        while (ulm.contains(++next_free) && ulm[next_free]){}
    }
    
    public:
    qxArray(){
        next_free = 0;
    }

    bool contains(size_type n) const{ // includes null
        return ulm.contains(n);
    }

    bool nonnull(size_type n) const{ 
        return (contains(n) && ulm.at(n));
    }

    bool remove(size_type n) { // return 0 if removed position was already flagged as removed/nullptr
        bool b = ulm.contains(n) && ulm[n];
        if (n < next_free){next_free = n;}
        ulm.erase(n);
        return b;
    }

    iterator begin() noexcept { return ulm.begin();}
    const_iterator begin() const noexcept { return ulm.begin();}
    iterator end() noexcept { return ulm.end();}
    const_iterator end() const noexcept { return ulm.end();}

    template <typename SubT, typename... Args> size_type insert(Args&&... args) { // returns the position of the newly added object
        static_assert(std::is_base_of_v<T, SubT>,"SubT must derive from T");
        size_type pos = next_free;
        increment_next_free();
        ulm.erase(pos);
        ulm.try_emplace(pos,std::make_unique<SubT>(std::forward<Args>(args)...));
        return pos;
    }

    size_type size() { // returns the size of the array.
        return ulm.size();
    }

    // element access
    reference operator[](size_type __n){
        return *ulm[__n];
    }
    // const access
    reference at(size_type __n){
        return *ulm.at(__n);
    }
    // const access
    const_reference at(size_type __n) const{
        return *ulm.at(__n);
    }

};

#endif // qxArray.h