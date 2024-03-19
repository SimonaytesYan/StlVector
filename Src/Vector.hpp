#pragma once

#include <string.h>
#include <assert.h>

#include "VectorIterator.hpp"
#include "DefaultVectorAllocator.hpp"

// TODO add concept for allocator
// TODO add emplace_back

template <class T, class Allocator = DefaultVectorAllocator<T>>
class Vector
{

public:
//=====================MEMBER TYPES================================
    using size_type       = size_t;
    using allocator_type  = Allocator;
    using difference_type = std::ptrdiff_t; 
    using value_type      = T;
    using pointer         = typename Allocator::pointer;
    using const_pointer   = typename Allocator::const_pointer;
    using reference       = T&;

    using iterator               = VectorIterator<T>;
    using const_iterator         = VectorIterator<const T>;
    using reverse_iterator       = VectorReverseIterator<T>;
    using const_reverse_iterator = VectorReverseIterator<const T>;

//=====================CONSTRUCTORS================================
    Vector(size_type size = 0) :
    size_      (size),
    capacity_  (size),
    allocator_ (),
    buffer_    (allocator_.allocate(size))
    { }

    Vector(size_type size, const value_type& value) :
    size_      (size),
    capacity_  (size),
    allocator_ (),
    buffer_    (allocator_.allocate(size))
    {
        for (size_type i = 0; i < size; i++)
            allocator_.construct(&buffer_[i], value);
    }

    Vector(const Vector<T>& other) :
    size_      (other.size),
    capacity_  (other.capacity),
    allocator_ (),
    buffer_    (allocator_.allocate(capacity_))
    {
        for (int i = 0; i < size_; i++)
            allocator_.construct(&buffer_[i], other.buffer_[i]);
    }

    Vector(Vector&& other) :
    size_      (other.size_),
    capacity_  (other.capacity_),
    allocator_ (),
    buffer_    (nullptr)
    {  Swap(other.buffer_, buffer_); }

//=========================OPERATORS===============================
    Vector<T>& operator=(const Vector<T>& other)
    {
        size_type old_capacity;
        size_     = other.size_;
        capacity_ = other.capacity_;

        allocator_.deallocate(buffer_, old_capacity);
        buffer_ = allocator_.allocate(capacity_);
        for (size_type i = 0; i < size_; i++)
            allocator_.construct(&buffer_[i], other.buffer_[i]);
        
        return *this;
    }

    Vector<T>& operator=(Vector<T>&& other)
    {
        size_     = other.size_;
        capacity_ = other.capacity_;
        Swap(other.buffer_, buffer_);
        
        return *this;
    }

    value_type& operator[](size_type index)
    { return buffer_[index]; }

    const value_type& operator[](size_type index) const
    { return buffer_[index]; }

//=========================GET INFO================================
    const value_type& Front() const
    { return buffer_[0]; }
    
    value_type& Front()
    { return buffer_[0]; }

    const value_type& Back() const
    { return buffer_[size_ - 1]; }
    
    value_type& Back()
    { return buffer_[size_ - 1]; }

    size_type Size() const
    { return size_; }

    size_type Capacity() const
    { return capacity_; }
    
    bool Empty() const
    { return size_ == 0; }

//========================CHANGE VECTOR=============================

    void PushBack(const T& value)
    {
        if (size_ == capacity_)
            Realloc();

        allocator_.construct(&buffer_[size_], value);
        size_++;
    }

    void PopBack()
    { 
        if (size_ > 0)
            size_--; 
    }

    void Clear()
    { size_ = 0; }

    void Resize(size_type new_size)
    {
        if (capacity_ < new_size)
            Realloc(new_size);
        size_ = new_size;
    }

    void Resize(size_type new_size, value_type value)
    {
        if (capacity_ < new_size)
            Realloc(new_size);

        if (size_ < new_size)
        {
            for (size_type i = size_; i < new_size; i++)
                allocator_.construct(&buffer_[i], value);
        }
        size_ = new_size;
    }

    void Reserve(size_type new_capacity)
    {
        if (capacity_ < new_capacity)
            Realloc(new_capacity);
    }

    void Insert(const iterator& iterator, const value_type& value)
    {
        assert(Begin() <= iterator && iterator <= End());

        size_type index = size_type(&(*iterator) - buffer_);

         if (size_ == capacity_)
             Realloc();
 
        allocator_.construct(&buffer_[size_], buffer_[size_ - 1]);
        for (size_type i = size_ - 1; i > index; i--)
            buffer_[i] = buffer_[i - 1];
        size_++;

        buffer_[index] = value;
    }

    void Erase(const iterator& iterator)
    {
        assert(Begin() <= iterator && iterator < End());

        size_type index = size_type(iterator - Begin());
        size_--;

        for (size_type i = index; i < size_; i++)
            buffer_[i] = buffer_[i + 1];
        allocator_.destruct(&buffer_[size_]);
    }

    void Erase(const iterator& it1, const iterator& it2)
    {
        assert(Begin() <= it1 && it1 < End());
        assert(Begin() <= it2 && it2 <= End());
        assert(it1 <= it2);

        size_type start = size_type(it1 - Begin());
        size_type shift = size_type(it2 - it1);
        size_type end   = size_type(End() - it2);

        for (size_type index = start; index < end; index++)
            buffer_[index] = buffer_[index + shift];

        for (size_type index = end; index < size_; index++)
            allocator_.destruct(&buffer_[index]);

        size_ -= shift;
    }

    // template<class... Args>
    // iterator Emplace(const_iterator pos, Args&&... args)
    // {
    //     assert(Begin() < pos && pos <= End());

    //     allocator_.c
        
    // }

//========================ITERATORS================================

    iterator Begin()
    { return iterator(buffer_); }

    iterator End()
    { return iterator(buffer_ + size_); }

    const_iterator CBegin()
    { return const_iterator(buffer_); }

    const_iterator CEnd()
    { return const_iterator(buffer_ + size_); }

    reverse_iterator RBegin()
    { return reverse_iterator(buffer_ + size_ - 1); }

    reverse_iterator REnd()
    { return reverse_iterator(buffer_ - 1); }

    reverse_iterator CRBegin()
    { return const_reverse_iterator(buffer_ + size_ - 1); }

    reverse_iterator CREnd()
    { return const_reverse_iterator(buffer_ - 1); }

//========================DESTRUCTOR===============================
    ~Vector()
    {
        for (size_type i = 0; i < size_; i++)
            allocator_.destruct(&buffer_[i]);
        allocator_.deallocate(buffer_, capacity_);
    }

    void DumpToSize()
    {
        for (size_type i = 0; i < size_; i++)
            fprintf(stderr, "%d ", buffer_[i]);
        fprintf(stderr, "\n");
    }

    void DumpToCap()
    {
        for (size_type i = 0; i < capacity_; i++)
            fprintf(stderr, "%d ", buffer_[i]);
        fprintf(stderr, "\n");
    }

private:
    void Realloc()
    {
        size_type new_capacity = capacity_ * kExpansionCoeff;
        if (new_capacity == 0)
            new_capacity = kStartLen;
        Realloc(new_capacity);
    }

    void Realloc(size_type new_capacity)
    {
        value_type* new_buffer = allocator_.allocate(new_capacity);
        
        for (size_type i = 0; i < size_; i++)
            allocator_.construct(&new_buffer[i], buffer_[i]);
        
        for (size_type i = 0; i < size_; i++)
            allocator_.destruct(&buffer_[i]);
        allocator_.deallocate(buffer_, capacity_);

        capacity_ = new_capacity;
        buffer_   = new_buffer;
    }

    // void ShiftRight(const iterator& iterator)
    // {

    // }

private:
    const size_type kExpansionCoeff = 2;
    const size_type kStartLen       = 2;

    size_type   size_;
    size_type   capacity_;
    Allocator   allocator_; 
    value_type* buffer_;
};

template<class T>
static void Swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}
