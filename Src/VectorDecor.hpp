#include "Vector.hpp"

template <class T, class Allocator = DefaultVectorAllocator<T>>
class STLVectorDecor
{
public:

//=====================MEMBER TYPES================================
    using size_type       = typename Vector<T, Allocator> ::size_type;
    using allocator_type  = typename Vector<T, Allocator> ::allocator_type;
    using difference_type = std::ptrdiff_t; 
    using value_type      = T;
    using pointer         = typename Allocator::pointer;
    using const_pointer   = typename Allocator::const_pointer;
    using reference       = T&;

    using iterator               = VectorIterator<T>;
    using const_iterator         = VectorIterator<const T>;
    using reverse_iterator       = VectorReverseIterator<T>;
    using const_reverse_iterator = VectorReverseIterator<const T>;

    STLVectorDecor(Vector<T, Allocator>& other) :
    vector (other)
    { }
    
    value_type& front() { return vector.Front(); }
    value_type& back()  { return vector.Back(); }

    const value_type& front()    const { return vector.Front(); }
    const value_type& back()     const { return vector.Back(); }
    size_type         size()     const { return vector.Size(); }
    size_type         capacity() const { return vector.Capacity(); }
    bool              empty()    const { return vector.Size(); }

    void push_back(const T& value)           { return vector.PushBack(value); }
    void pop_back ()                         { return vector.PopBack(); }
    void clear    ()                         { return vector.Clear(); }
    void resize   (size_type new_size)       { return vector.Resize(new_size); }
    void reserve  (size_type new_capacity)   { return vector.Reserve(new_capacity); }
    void erase    (const iterator& iterator) { return vector.Erase(iterator); }

    void resize(size_type new_size, value_type value)  
    { return vector.Resize(new_size, value); }
    void insert(const iterator& iterator, const value_type& value)  
    { return vector.PushBack(); }
    void erase(const iterator& it1, const iterator& it2)  
    { return vector.PushBack(); }
    
    template<class... Args>
    iterator emplace(const iterator& pos, Args&&... args)
    { return vector.Emplace(pos, args...); }

    template<class... Args>
    void emplace_back(Args&&... args)
    { return vector.EmplaceBack(args...); }

    iterator         begin()   { return vector.Begin();   }
    iterator         end()     { return vector.End();     }
    const_iterator   cbegin()  { return vector.CBegin();  }
    const_iterator   cend()    { return vector.CEnd();    }
    reverse_iterator rbegin()  { return vector.RBegin();  }
    reverse_iterator rend()    { return vector.REnd();    }
    reverse_iterator crbegin() { return vector.CRBegin(); }
    reverse_iterator crend()   { return vector.CREnd();   }

private:
    Vector<T, Allocator>& vector;
};
