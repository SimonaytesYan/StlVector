#pragma once

#include <strinig.h>

template <class T>
class Vector
{

//=====================MEMBER TYPES==========================
    using value_type = T;
    using size_type  = size_t;

//=====================CONSTRUCTORS==========================
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
    buffer_   (new value_type[capacity])
    {
        memcpy(buffer_, v.buffer, sizeof(value_type) * size_);
    }

    Vector(Vector&& other) :
    size_     (other.size_),
    capacity_ (other.capacity_),
    buffer_   (other.buffer_)
    { }
    
//=====================OPERATORS==========================
    Vector<T>& operator=(const Vector<T>& other)
    {
        size_     = other.size_;
        capacity_ = other.capacity_;

        delete[] buffer_;
        buffer_ = new value_type[capacity_];
        for (int i = 0; i < size_; i++)
            buffer_[i] = other_.buffer[i];
        
        return *this;
    }

    Vector<T>& operator=(Vector<T>&& other)
    {
        size_     = other.size_;
        capacity_ = other.capacity_;
        buffer_   = std::swap(other.buffer_, buffer_);
        
        return *this;
    }

    T& operator[](size_type index)
    {
        return buffer_[index];
    }

    ~Vector()
    {
        delete[] buffer_;
    }

private:
    const size_type kExpansionCoeff = 2;

    size_type   size_;
    size_type   capacity_;
    value_type* buffer_;
};