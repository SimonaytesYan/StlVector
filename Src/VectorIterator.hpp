#pragma once

template<class T>
class VectorIterator
{
public:
    using iterator_category = std::random_access_iterator_tag;

    using value_type      = T;
    using difference_type = std::ptrdiff_t; 
    using pointer         = T*;
    using reference       = T&;

    VectorIterator() :
    iter_ (nullptr)
    { }

    VectorIterator(T* ptr) :
    iter_ (ptr)
    { }

    VectorIterator(const VectorIterator<T>& other) = default;
    VectorIterator& operator=(const VectorIterator<T>& other) = default;

    T& operator*()
    { return *iter_; }

    const T& operator*() const
    { return *iter_; }

    VectorIterator operator+(difference_type value)
    { return iter_ + value; }
    
    VectorIterator operator-(difference_type value)
    { return iter_ - value; }

    VectorIterator& operator+=(difference_type value)
    {
        iter_ += value;
        return *this;
    }

    VectorIterator& operator-=(difference_type value)
    {
        iter_ -= value;
        return *this;
    }

    VectorIterator& operator++()
    { 
        iter_++;
        return *this;
    }

    VectorIterator operator++(int)
    {
        VectorIterator old_iter = *this;
        operator++();
        
        return old_iter;
    }

    VectorIterator& operator--()
    { 
        iter_--;
        return *this;
    }

    VectorIterator operator--(int)
    {
        VectorIterator old_iter = *this;
        operator--();
        
        return old_iter;
    }

    difference_type operator-(const VectorIterator<T>& other)
    { return iter_ - other.iter_; }

    // difference_type operator+(const VectorIterator<T>& other)
    // { return iter_ + other.iter_; }

    bool operator==(const VectorIterator& other)
    { return iter_ == other.iter_; }

    bool operator!=(const VectorIterator& other)
    { return iter_ != other.iter_; }

    bool operator<(const VectorIterator& other)
    { return (iter_ < other.iter_); }

    bool operator>(const VectorIterator& other)
    { return (iter_ > other.iter_); }

    bool operator<=(const VectorIterator& other)
    { return (iter_ <= other.iter_); }

    bool operator>=(const VectorIterator& other)
    { return (iter_ >= other.iter_); }

private:
    T* iter_;
};

// const iterator
// reverse iterator
// const reverse iterator
