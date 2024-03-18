#pragma once

#include <string.h>
#include <assert.h>

#include "VectorIterator.hpp"

template <class T>
class Vector
{

public:
//=====================MEMBER TYPES================================
    using size_type       = size_t;
    using difference_type = std::ptrdiff_t; 
    using value_type      = T;
    using pointer         = T*;
    using reference       = T&;

    using iterator               = VectorIterator<T>;
    using const_iterator         = VectorIterator<const T>; // ?
    // using reverse_iterator       = VectorReverseIterator<T>;
    // using const_reverse_iterator = VectorReverseIterator<const T>; // ?

//=====================CONSTRUCTORS================================
    Vector(size_type size = 0) :
    size_     (size),
    capacity_ (size),
    buffer_   (new value_type[size])
    { }

    Vector(size_type size, const value_type& value) :
    size_     (size),
    capacity_ (size),
    buffer_   (new value_type[size])
    {
        for (size_type i = 0; i < size; i++)
            buffer_[i] = value;
    }

    Vector(const Vector<T>& other) :
    size_     (other.size),
    capacity_ (other.capacity),
    buffer_   (new value_type[capacity_])
    {
        memcpy(buffer_, other.buffer_, sizeof(value_type) * size_);
    }

    Vector(Vector&& other) :
    size_     (other.size_),
    capacity_ (other.capacity_)
    {  Swap(other.buffer_, buffer_); }

//=========================OPERATORS===============================
    Vector<T>& operator=(const Vector<T>& other)
    {
        size_     = other.size_;
        capacity_ = other.capacity_;

        delete[] buffer_;
        buffer_ = new value_type[capacity_];
        for (size_type i = 0; i < size_; i++)
            buffer_[i] = other.buffer_[i];
        
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
        {
            Realloc();
        }

        buffer_[size_] = value;
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
                buffer_[i] = value;
        }
        size_ = new_size;
    }

    void Reserve(size_type new_capacity)
    {
        if (capacity_ < new_capacity)
            Realloc(new_capacity);
    }

    iterator Begin()
    { return iterator(buffer_); }

    iterator End()
    { return iterator(buffer_ + size_); }

    void Insert(const iterator& iterator, const value_type& new_elem)
    {
        assert(Begin() <= iterator && iterator <= End());

        size_type index = &(*iterator) - buffer_;

         if (size_ == capacity_)
             Realloc();

        size_++;
        for (size_type i = size_ - 1; i > index; i--)
            buffer_[i] = buffer_[i - 1];
        buffer_[index] = new_elem;
    }

    void Erase(const iterator& iterator)
    {
        assert(Begin() <= iterator && iterator < End());

        size_type index = iterator - Begin();
        size_--;
        // TODO элементы по индексу buffer_[size_] и buffer_[size_] равны. 
        //  Потенциальное говно при удалении

        for (size_type i = index; i < size_; i++)
            buffer_[i] = buffer_[i + 1];
    }

    void Erase(const iterator& it1, const iterator& it2)
    {
        assert(Begin() <= it1 && it1 < End());
        assert(Begin() <= it2 && it2 <= End());

        size_type start = it1 - Begin();
        size_type shift = it2 - it1;

        for (size_type index = start; index < start + (size_ - shift); index++)
            buffer_[index] = buffer_[index + shift];

        // TODO Аналогично с Erase(Iter)
        size_ -= shift;
    }

//========================DESTRUCTOR===============================
    ~Vector()
    { delete[] buffer_; }

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
        value_type* new_buffer = new value_type[new_capacity];
        
        for (size_type i = 0; i < size_; i++)
            new_buffer[i] = buffer_[i];
        
        delete[] buffer_;
        capacity_ = new_capacity;
        buffer_   = new_buffer;
    }

private:
    const size_type kExpansionCoeff = 2;
    const size_type kStartLen       = 2;

    size_type   size_;
    size_type   capacity_;
    value_type* buffer_;
};

template<class T>
static void Swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}
