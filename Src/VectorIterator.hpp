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

    difference_type operator-(const VectorIterator<T>& other) const
    { return iter_ - other.iter_; }

    VectorIterator operator+(difference_type value) const
    { return iter_ + value; }
    
    VectorIterator operator-(difference_type value) const
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

    bool operator==(const VectorIterator& other) const
    { return iter_ == other.iter_; }

    bool operator!=(const VectorIterator& other) const
    { return iter_ != other.iter_; }

    bool operator<(const VectorIterator& other) const
    { return (iter_ < other.iter_); }

    bool operator>(const VectorIterator& other) const
    { return (iter_ > other.iter_); }

    bool operator<=(const VectorIterator& other) const
    { return (iter_ <= other.iter_); }

    bool operator>=(const VectorIterator& other) const
    { return (iter_ >= other.iter_); }

private:
    T* iter_;
};


template<class T>
class VectorReverseIterator
{
public:
    using iterator_category = std::random_access_iterator_tag;

    using value_type      = T;
    using difference_type = std::ptrdiff_t; 
    using pointer         = T*;
    using reference       = T&;

    VectorReverseIterator() :
    iter_ (nullptr)
    { }

    VectorReverseIterator(T* ptr) :
    iter_ (ptr)
    { }

    VectorReverseIterator(const VectorReverseIterator<T>& other) = default;
    VectorReverseIterator& operator=(const VectorReverseIterator<T>& other) = default;

    T& operator*()
    { return *iter_; }

    const T& operator*() const
    { return *iter_; }

    difference_type operator-(const VectorIterator<T>& other) const
    { return other.iter_ - VectorIterator<T>::iter_; }

    VectorReverseIterator operator+(difference_type value) const
    { return iter_ - value; }
    
    VectorReverseIterator operator-(difference_type value) const
    { return iter_ + value; }

    VectorReverseIterator& operator+=(difference_type value)
    {
        iter_ -= value;
        return *this;
    }

    VectorReverseIterator& operator-=(difference_type value)
    {
        iter_ += value;
        return *this;
    }

    VectorReverseIterator& operator++()
    { 
        iter_--;
        return *this;
    }

    VectorReverseIterator operator++(int)
    {
        VectorReverseIterator old_iter = *this;
        operator++();
        
        return old_iter;
    }

    VectorReverseIterator& operator--()
    { 
        iter_++;
        return *this;
    }

    VectorReverseIterator operator--(int)
    {
        VectorReverseIterator old_iter = *this;
        operator--();
        
        return old_iter;
    }
    
    difference_type operator-(const VectorReverseIterator<T>& other) const
    { return iter_ - other.iter_; }

    bool operator==(const VectorReverseIterator& other) const
    { return iter_ == other.iter_; }

    bool operator!=(const VectorReverseIterator& other) const
    { return iter_ != other.iter_; }

    bool operator<(const VectorReverseIterator& other) const
    { return (iter_ > other.iter_); }

    bool operator>(const VectorReverseIterator& other) const
    { return (iter_ < other.iter_); }

    bool operator<=(const VectorReverseIterator& other) const
    { return (iter_ >= other.iter_); }

    bool operator>=(const VectorReverseIterator& other) const
    { return (iter_ <= other.iter_); }

private:
    T* iter_;
};
