#pragma once

#include "BasicVector.hpp"
#include "Errors.h"

CREATE_PREDICATE((sizeof(U) > sizeof(int) || !std::is_trivially_copy_constructible_v<U>), ComplexObject);

// Vector for not complex objects
template <typename T, typename Allocator = DefaultVectorAllocator<T>, typename Checker = void>
class Vector : public BasicVector<T, Allocator>
{
public:
    using size_type       = typename BasicVector<T, Allocator>::size_type;
    using allocator_type  = typename BasicVector<T, Allocator>::allocator_type;
    using difference_type = typename BasicVector<T, Allocator>::difference_type;
    using value_type      = typename BasicVector<T, Allocator>::value_type;
    using pointer         = typename BasicVector<T, Allocator>::pointer;
    using const_pointer   = typename BasicVector<T, Allocator>::const_pointer;
    using reference       = typename BasicVector<T, Allocator>::reference;

    using iterator               = typename BasicVector<T, Allocator>::iterator;
    using const_iterator         = typename BasicVector<T, Allocator>::const_iterator;
    using reverse_iterator       = typename BasicVector<T, Allocator>::reverse_iterator;
    using const_reverse_iterator = typename BasicVector<T, Allocator>::const_reverse_iterator;

//================================CONSTRUCTORS===========================
    Vector(const BasicVector<T, Allocator>& basic_vector) :
    BasicVector<T, Allocator>(basic_vector)
    {
        printf("Not Complex Vector\n");
    }

    Vector(size_type size = 0) :
    BasicVector<T, Allocator>(size)
    {
        printf("Not Complex Vector\n");
    }

    Vector(size_type size, const value_type& value) :
    BasicVector<T, Allocator>(size, value)
    {
        printf("Not Complex Vector\n");
    }

    Vector(const Vector<T>& other) :
    BasicVector<T, Allocator>(other)
    {
        printf("Not Complex Vector\n");
    }

    Vector(Vector&& other) :
    BasicVector<T, Allocator>(other)
    {
        printf("Not Complex Vector\n");
    }

//================================OPERATORS===========================
    
    Vector<T>& operator=(const Vector<T>& other)
    {
        size_type old_capacity = this->capacity_;
        this->size_                  = other.size_;
        this->capacity_              = other.capacity_;

        this->allocator_.deallocate(this->buffer_, old_capacity);
        this->buffer_ = this->allocator_.allocate(this->capacity_);

        memcpy(this->buffer_, other, sizeof(T) * this->size_);
        return *this;
    }

    void Resize(size_type new_size) override
    {
        if (this->capacity_ < new_size)
            Realloc(new_size);        
        this->size_ = new_size;
    }

    void Resize(size_type new_size, value_type value) override
    {
        if (this->capacity_ < new_size)
            Realloc(new_size);

        if (this->size_ < new_size)
        {
            for (size_type i = this->size_; i < new_size; i++)
                this->allocator_.construct(&this->buffer_[i]);
        }
        else if (this->size_ > new_size)
        {
            for (size_t i = new_size; i < this->size_; i++)
                this->allocator_.destruct(&this->buffer_[i]);
        }

        this->size_ = new_size;
    }

    void Erase(const iterator& iterator) override
    {
        if (!(this->Begin() <= iterator && iterator < this->End()))
            throw IteratorOutOfBounce();

        size_type index = size_type(iterator - this->Begin());
        this->size_--;

        for (size_type i = index; i < this->size_; i++)
            this->buffer_[i] = this->buffer_[i + 1];
        this->allocator_.destruct(&this->buffer_[this->size_]);
    }

    void Erase(const iterator& it1, const iterator& it2) override
    {
        if (!(this>Begin() <= it1 && it1 < this->End()))
            throw IteratorOutOfBounce();
        if (!(this->Begin() <= it2 && it2 < this->End()));
            throw IteratorOutOfBounce();
        if (!(it1 <= it2))
            throw It1BiggerThanIt2();

        size_type start = size_type(it1 - this->Begin());
        size_type shift = size_type(it2 - it1);
        size_type end_ind   = size_type(this->End() - it2);

        for (size_type index = start; index < end_ind; index++)
            this->buffer_[index] = this->buffer_[index + shift];

        for (size_type index = end_ind; index < this->size_; index++)
            this->allocator_.destruct(&this->buffer_[index]);

        this->size_ -= shift;
    }

//========================DESTRUCTOR===============================
    ~Vector()
    { this->allocator_.deallocate(this->buffer_, this->capacity_); }

protected:

    void Realloc(size_type new_capacity) override
    {
        value_type* new_buffer = this->allocator_.allocate(new_capacity);
        
        memcpy(new_buffer, this->buffer_, this->size_ * sizeof(T));
        this->allocator_.deallocate(this->buffer_, this->capacity_);

        this->capacity_ = new_capacity;
        this->buffer_   = new_buffer;
    }
};

// Vector for complex objects
template <class T, class Allocator>
class Vector<T,Allocator, typename EnableIf<ComplexObject<T>::value, void>::type> : public BasicVector<T, Allocator>
{
public:
    using size_type       = typename BasicVector<T, Allocator>::size_type;
    using allocator_type  = typename BasicVector<T, Allocator>::allocator_type;
    using difference_type = typename BasicVector<T, Allocator>::difference_type;
    using value_type      = typename BasicVector<T, Allocator>::value_type;
    using pointer         = typename BasicVector<T, Allocator>::pointer;
    using const_pointer   = typename BasicVector<T, Allocator>::const_pointer;
    using reference       = typename BasicVector<T, Allocator>::reference;

    using iterator               = typename BasicVector<T, Allocator>::iterator;
    using const_iterator         = typename BasicVector<T, Allocator>::const_iterator;
    using reverse_iterator       = typename BasicVector<T, Allocator>::reverse_iterator;
    using const_reverse_iterator = typename BasicVector<T, Allocator>::const_reverse_iterator;

//================================CONSTRUCTORS===========================
    Vector(const BasicVector<T, Allocator>& basic_vector) :
    BasicVector<T, Allocator>(basic_vector)
    {
        printf("Complex Vector(sizeof(T) = %d)\n", sizeof(T));
    }

    Vector(size_type size = 0) :
    BasicVector<T, Allocator>(size)
    { 
        printf("Complex Vector(sizeof(T) = %d)\n", sizeof(T));
    }

    Vector(size_type size, const value_type& value) :
    BasicVector<T, Allocator>(size, value)
    { 
        printf("Complex Vector(sizeof(T) = %d)\n", sizeof(T));
    }

    Vector(const Vector<T>& other) :
    BasicVector<T, Allocator>(other)
    { 
        printf("Complex Vector(sizeof(T) = %d)\n", sizeof(T));
    }

    Vector(Vector&& other) :
    BasicVector<T, Allocator>(other)
    { 
        printf("Complex Vector(sizeof(T) = %d)\n", sizeof(T));
    }

//===============================OPERATOR================================
    Vector<T>& operator=(const Vector<T>& other)
    {
        size_type old_capacity = this->capacity_;
        this->size_                  = other.size_;
        this->capacity_              = other.capacity_;

        this->allocator_.deallocate(this->buffer_, old_capacity);
        this->buffer_ = this->allocator_.allocate(this->capacity_);
        for (size_type i = 0; i < this->size_; i++)
            this->allocator_.construct(&this->buffer_[i], other.buffer_[i]);

        return *this;
    }

    Vector<T>& operator=(Vector<T>&& other)
    {
        this->size_     = other.size_;
        this->capacity_ = other.capacity_;
        Swap(other.buffer_, this->buffer_);
        
        return *this;
    }

//===========================DESTRUCTOR===============================
    ~Vector()
    {
        for (size_type i = 0; i < this->size_; i++)
            this->allocator_.destruct(&this->buffer_[i]);
        this->allocator_.deallocate(this->buffer_, this->capacity_);
    }
};
