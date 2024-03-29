#include <stdio.h>
#include <algorithm>

#include "Vector.hpp"
#include "VectorDecor.hpp"

using type = int;

#define TEST_STL
#define TEST_VECTOR
#define TEST_SFINAE

void PrintTestNum(size_t test_num);
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();
void Test7();
void Test8();
void Test9();
void Test10();
void Test11();
void Test12();
void Test13();
void Test14();
void Test15();
void Test16();
void Test17();
void Test18();
void Test19();
void Test20();
void Test21();
void Test22();
void Test23();
void Test24();
void Test25();
void Test26();
void Test27();
void Test28();
void Test29();
void Test30();
void Test31();
void Test32();
void Test33();
void Test34();
void Test35();
void Test36();
void Test37();
void Test38();
void Test39();
void Test0();

#define RUN_TEST(test_num)     \
    PrintTestNum(test_num);    \
    Test##test_num();          \

int main()
{
    #ifdef TEST_SFINAE
        RUN_TEST(0);
    #endif

    #ifdef TEST_VECTOR
        RUN_TEST(1);
        RUN_TEST(2);
        RUN_TEST(3);
        RUN_TEST(4);
        RUN_TEST(5);
        RUN_TEST(6);
        RUN_TEST(7);
        RUN_TEST(8);
        RUN_TEST(9);
        RUN_TEST(10);
        RUN_TEST(11);
        RUN_TEST(12);
        RUN_TEST(13);
        RUN_TEST(14);
        RUN_TEST(15);
        RUN_TEST(16);
        RUN_TEST(17);
        RUN_TEST(18);
        RUN_TEST(19);
        RUN_TEST(20);
        RUN_TEST(21);
        RUN_TEST(22);
        RUN_TEST(23);
        RUN_TEST(24);
        RUN_TEST(25);
        RUN_TEST(26);
        RUN_TEST(27);
        RUN_TEST(28);
        RUN_TEST(29);
        RUN_TEST(30);
        RUN_TEST(31);
        RUN_TEST(32);
        RUN_TEST(33);
        RUN_TEST(34);
        RUN_TEST(35);
    #endif

    #ifdef TEST_STL
        RUN_TEST(36);
        RUN_TEST(37);
        RUN_TEST(38);
        RUN_TEST(39);
    #endif

}

void PrintTestNum(size_t test_num)
{
    fprintf(stderr, "======================================\n");
    fprintf(stderr, "TEST %zu\n", test_num);
    fprintf(stderr, "+++++++\n");
}

struct B {
    int a[10];
};

struct C {

    C() :
    a (0)
    { }

    C(const C& other)
    {
        a = other.a + 10;
    }

    int a;
};

void Test0()
{
    Vector<int> v1(10); 
    Vector<B>   v2(10); 
    Vector<C>   v3(10); 
}

// Test simple constructor and operator[]
void Test1()
{
    Vector<type> v(10);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = 10 - (type)i;

    v.DumpToSize();
}

// Test Front and Back 1
void Test2()
{
    Vector<type> v(1);

    type& front = v.Front();
    type& back  = v.Back();

    front = -1;
    fprintf(stderr, "v[0] = %d\n", v[0]);

    back = -2;
    fprintf(stderr, "v[0] = %d\n", v[0]);
}

// Test Front and Back 2
void Test3()
{
    Vector<type> v(10);
    for (size_t i = 0; i < 10; i++)
        v[i] = (type)i;
    
    v.Front() = -1;
    v.Back()  = 100;
    v.DumpToSize();
}

// Test size
void Test4()
{
    Vector<type> v1(10);
    fprintf(stderr, "size     = %zu\n", v1.Size());
    fprintf(stderr, "capacity = %zu\n", v1.Capacity());

    Vector<type> v2(100);
    fprintf(stderr, "size = %zu\n", v2.Size());
}

// Test empty
void Test5()
{
    Vector<type> v1(0);
    fprintf(stderr, "empty = %d\n", v1.Empty());
    
    Vector<type> v2(2);
    fprintf(stderr, "empty = %d\n", v2.Empty());
}

// Test push_back 1
void Test6()
{
    Vector<type> v(3, 2);
    v.PushBack(-1);
    v.DumpToSize();
    v.DumpToCap();
}

// Test push_back 2
void Test7()
{
    Vector<type> v(0);
    v.PushBack(100);

    v.DumpToSize();
    v.DumpToCap();
}

// Test push_back 3
void Test8()
{
    Vector<type> v(0);
    v.PushBack(-1);
    v.PushBack(-2);
    v.PushBack(-3);
    v.PushBack(-4);

    v.DumpToSize();
    v.DumpToCap();
}

// Test pop_back 1
void Test9()
{
    Vector<type> v(1, 10);
    v.PopBack();
    v.PopBack();

    v.DumpToSize();
    v.DumpToCap();
}

// Test pop_back 2
void Test10()
{
    Vector<type> v(0);

    for (size_t i = 1; i <= 10; i++)
        v.PushBack((type)i);
    
    for (size_t i = 0; i < 5; i++)
    {
        fprintf(stderr, "Back = %d\n", v.Back());
        v.PopBack();
    }

    v.DumpToSize();
    v.DumpToCap();
}

// Test clear
void Test11()
{
    Vector<type> v(1);
    v.Clear();
    fprintf(stderr, "size = %zu\ncap  = %zu\n", v.Size(), v.Capacity());   
}

// Test Resize 1
void Test12()
{
    Vector<type> v(10);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    v.Resize(10);
    v.DumpToSize();
    v.DumpToCap();
}

// Test Resize 2
void Test13()
{
    Vector<type> v(10);
    for (size_t i = 0; i < 10; i++)
        v[i] = (type)(i + 1);

    v.Resize(5);
    v.DumpToSize();
    v.DumpToCap();
}

// Test Resize 3
void Test14()
{
    Vector<type> v(5);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    v.Resize(10, -1);
    v.DumpToSize();
    v.DumpToCap();
}

// Test Reserve 1
void Test15()
{
    Vector<type> v(5);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    v.Reserve(10);
    v.DumpToSize();
    v.DumpToCap();
}

// Test Reserve 2
void Test16()
{
    Vector<type> v(10);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    v.Reserve(5);
    v.DumpToSize();
    v.DumpToCap();
}

void Test17()
{
    Vector<type> v(5);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = rand() % 100;

    std::sort(v.Begin(), v.End());
    v.DumpToSize();
}

// Test Insert 1
void Test18()
{
    Vector<type> v(5);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    v.Insert(v.Begin() + 1, -1);
    v.DumpToSize();
}

// Test Insert 2
void Test19()
{
    Vector<type> v(5);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    auto it = v.End();

    v.Insert(it, -1);
    v.DumpToSize();
}

// Test Insert 3
void Test20()
{
    Vector<type> v(5);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    auto it = v.Begin();
    it += 3;

    v.Insert(it, -1);
    v.DumpToSize();
}

// Test Erase(Iter) 1
void Test21()
{
    Vector<type> v(5);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    auto it = v.Begin();
    v.Erase(it);
    v.DumpToSize();
}

// Test Erase(Iter) 2
void Test22()
{
    Vector<type> v(5);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    auto it = v.End() - 1;
    v.Erase(it);
    v.DumpToSize();
}

// Test Erase(Iter) 3
void Test23()
{
    Vector<type> v(5);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    auto it = v.End() - 3;
    v.Erase(it);
    v.DumpToSize();
}

// Test Erase(Iter) 4
void Test24()
{
    Vector<type> v(1, -1);

    v.Erase(v.Begin());
    v.DumpToSize();
}

// Test Erase(Iter, Iter) 1
void Test25()
{
    Vector<type> v(5);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    auto start = v.Begin();
    auto end   = v.End();
    v.Erase(start, end);
    v.DumpToSize();
}

// Test Erase(Iter, Iter) 2
void Test26()
{
    Vector<type> v(10);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    auto start = v.Begin() + 1;
    auto End   = v.End()   - 2;
    v.Erase(start, End);
    v.DumpToSize();
}

// Test Erase(Iter, Iter) 3
void Test27()
{
    Vector<type> v(10);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    auto start = v.Begin() + 6;
    auto End   = v.End() - 1;
    v.Erase(start, End);
    v.DumpToSize();
}

// Test Erase(Iter, Iter) 4
void Test28()
{
    Vector<type> v(10);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    auto start = v.Begin();
    auto End   = v.Begin();
    v.Erase(start, End);
    v.DumpToSize();
}

// Test Erase(Iter, Iter) 5
void Test29()
{
    Vector<type> v(10);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    auto start = v.Begin();
    auto End   = v.Begin() + 1;
    v.Erase(start, End);
    v.DumpToSize();
}

// Test reverse_iterator 1
void Test30()
{
    Vector<type> v(5);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = rand() % 100;

    std::sort(v.RBegin(), v.REnd());
    v.DumpToSize();
}

// Test reverse_iterator 2
void Test31()
{
    Vector<type> v(5);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = (type)(i + 1);

    for (auto it = v.RBegin(); it != v.REnd(); ++it)
        fprintf(stderr, "%d ", *it);
    fprintf(stderr, "\n");
}

// Test allocator 1
void Test32()
{
    DefaultVectorAllocator<type> alloc;

    type* array = alloc.allocate(10); 

    for (size_t i = 0; i < 10; i++)
    {
        array[i] = (type)(i + 1);
        fprintf(stderr, "%d ", array[i]);
    }
    fprintf(stderr, "\n");

    alloc.deallocate(array, 10);
}

// Test allocator 2
struct A
{
    A() :
    a_ (0),
    c_ (0)
    {}

    A(int a, char c) :
    a_ (a),
    c_ (c)
    { }

    A(const A&) = default; 

    int  a_;
    char c_;
};

void Test33()
{
    DefaultVectorAllocator<A> alloc;

    A* array = alloc.allocate(2);
    alloc.construct<type, char>(array, -1, 'c');

    alloc.construct(array + 1, array[0]);

    for (size_t i = 0; i < 2; i++) 
    {
        fprintf(stderr, "array[%zu].a = %d\n", i, array[i].a_);
        fprintf(stderr, "array[%zu].c = %c\n", i, array[i].c_);
    }

    alloc.deallocate(array, 2);
}

// Test Emplace
void Test34()
{
    Vector<A> v(2, {10, 'a'});

    v.Emplace(v.Begin() + 1, -1, '4');

    for (size_t i = 0; i < v.Size(); i++)
        fprintf(stderr, "{%d, %c} ", v[i].a_, v[i].c_);
    fprintf(stderr, "\n");
}

// Test EmplaceBack
void Test35()
{
    Vector<A> v(2, {10, 'a'});

    v.EmplaceBack(-1, '4');

    for (size_t i = 0; i < v.Size(); i++)
        fprintf(stderr, "{%d, %c} ", v[i].a_, v[i].c_);
    fprintf(stderr, "\n");
}

// Test std::for_each
void Test36()
{
    Vector<type> v1(5);
    for (type i = 0; i < v1.Size(); i++)
        v1[i] = i * 2;
        
    STLVectorDecor<type> stl_v1(v1);

    std::for_each(stl_v1.cbegin(), stl_v1.cend(), 
                  [](const type& elem) { fprintf(stderr, "%d ", elem); });
    fprintf(stderr, "\n");
}

// Test std::copy
void Test37()
{
    Vector<type> v1(5, 0);
    Vector<type> v2(5, 0);
    for (type i = 0; i < v1.Size(); i++)
        v1[i] = i * 2;

    STLVectorDecor<type> stl_v1(v1);
    STLVectorDecor<type> stl_v2(v2);

    std::copy(stl_v1.begin(), stl_v1.end(), stl_v2.begin());

    v2.DumpToSize();
}

// Test range base for
void Test38()
{
    Vector<type> v(5);
    for (type i = 0; i < v.Size(); i++)
        v[i] = (1 << i);
    
    STLVectorDecor<type> stl_v(v);

    for (auto elem : stl_v)
        fprintf(stderr, "%d ", elem);
    fprintf(stderr, "\n");
}

// Test std::sort
void Test39()
{
    Vector<type> v(5);
    for (size_t i = 0; i < v.Size(); i++)
        v[i] = rand() % 100;
    
    v.DumpToSize();
    STLVectorDecor<type> stl_v(v);

    std::sort(stl_v.begin(), stl_v.end());
    
    v.DumpToSize();
}
