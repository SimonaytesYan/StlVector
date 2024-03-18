#pragma once

#include <string.h>

template <class T>
class Vector
{

public:
//=====================MEMBER TYPES================================
    using value_type = T;
    using size_type  = size_t;

//=====================CONSTRUCTORS================================
    Vector(size_type size) :
    size_     (size),
    capacity_ (size),
    buffer_   (new value_type[size])
    { }

    Vector(size_type size, const value_type& value) :
    size_     (size),
    capacity_ (size),
    buffer_   (new value_type[size])
    {
        for (int i = 0; i < size; i++)
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
        for (int i = 0; i < size_; i++)
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

    size_type Size()
    { return size_; }

    size_type Capacity()
    { return capacity_; }
    
    bool Empty()
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
    {
        size_ = 0;
    }

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
            for (int i = size_; i < new_size; i++)
                buffer_[i] = value;
        }
        size_ = new_size;
    }

    void Reserve(size_type new_capacity)
    {
        if (capacity_ < new_capacity)
            Realloc(new_capacity);
    }

//========================DESTRUCTOR===============================
    ~Vector()
    { delete[] buffer_; }

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
        
        for (int i = 0; i < size_; i++)
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
