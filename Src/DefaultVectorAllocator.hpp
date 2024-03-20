#pragma once

template<class T>
class DefaultVectorAllocator
{
public:
    using value_type      = T;
    using pointer         = T*;
    using const_pointer   = const T*;
    using reference       = T&;
    using const_reference = const T&;
    using size_type       = size_t;

    DefaultVectorAllocator()
    {}

    DefaultVectorAllocator(const DefaultVectorAllocator& other) = default;

    pointer address(reference object)
    { return &object; }

    pointer allocate(size_t n)
    { return (pointer)(::operator new(sizeof(value_type) * n)); }

    void deallocate(pointer ptr, size_t n)
    { ::operator delete(ptr, sizeof(value_type) * n); }

    void construct(pointer ptr, const_reference val)
    { ::new(ptr) value_type(val); }

    template <class ...Args>
    void construct(pointer ptr, Args... args)
    { ::new((void*)ptr) value_type(args...); }
    
    void destruct(pointer ptr)
    { ptr->~value_type(); }
};

