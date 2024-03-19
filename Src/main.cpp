#include <stdio.h>
#include <algorithm>

#include "Vector.hpp"

void PrintTestNum();
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

#define RUN_TEST(test_num)     \
    PrintTestNum();            \
    Test##test_num();          \

int main()
{
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
}

void PrintTestNum()
{
    static size_t test_cnt = 0;
    fprintf(stderr, "======================================\n");
    fprintf(stderr, "TEST %llu\n", ++test_cnt);
    fprintf(stderr, "+++++++\n");
}

// Test simple constructor and operator[]
void Test1()
{
    Vector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = 10 - i;

    v.DumpToSize();
}

// Test Front and Back 1
void Test2()
{
    Vector<int> v(1);

    int& front = v.Front();
    int& back  = v.Back();

    front = -1;
    fprintf(stderr, "v[0] = %d\n", v[0]);

    back = -2;
    fprintf(stderr, "v[0] = %d\n", v[0]);
}

// Test Front and Back 2
void Test3()
{
    Vector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = i;
    
    v.Front() = -1;
    v.Back()  = 100;
    v.DumpToSize();
}

// Test size
void Test4()
{
    Vector<int> v1(10);
    fprintf(stderr, "size     = %d\n", v1.Size());
    fprintf(stderr, "capacity = %d\n", v1.Capacity());

    Vector<int> v2(100);
    fprintf(stderr, "size = %d\n", v2.Size());
}

// Test empty
void Test5()
{
    Vector<int> v1(0);
    fprintf(stderr, "empty = %d\n", v1.Empty());
    
    Vector<int> v2(2);
    fprintf(stderr, "empty = %d\n", v2.Empty());
}

// Test push_back 1
void Test6()
{
    Vector<int> v(3, 2);
    v.PushBack(-1);
    v.DumpToSize();
    v.DumpToCap();
}

// Test push_back 2
void Test7()
{
    Vector<int> v(0);
    v.PushBack(100);

    v.DumpToSize();
    v.DumpToCap();
}

// Test push_back 3
void Test8()
{
    Vector<int> v(0);
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
    Vector<int> v(1, 10);
    v.PopBack();
    v.PopBack();

    v.DumpToSize();
    v.DumpToCap();
}

// Test pop_back 2
void Test10()
{
    Vector<int> v(0);

    for (int i = 1; i <= 10; i++)
        v.PushBack(i);
    
    for (int i = 0; i < 5; i++)
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
    Vector<int> v(1);
    v.Clear();
    fprintf(stderr, "size = %d\ncap  = %d\n", v.Size(), v.Capacity());   
}

// Test Resize 1
void Test12()
{
    Vector<int> v(10);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    v.Resize(10);
    v.DumpToSize();
    v.DumpToCap();
}

// Test Resize 2
void Test13()
{
    Vector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = i + 1;

    v.Resize(5);
    v.DumpToSize();
    v.DumpToCap();
}

// Test Resize 3
void Test14()
{
    Vector<int> v(5);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    v.Resize(10, -1);
    v.DumpToSize();
    v.DumpToCap();
}

// Test Reserve 1
void Test15()
{
    Vector<int> v(5);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    v.Reserve(10);
    v.DumpToSize();
    v.DumpToCap();
}

// Test Reserve 2
void Test16()
{
    Vector<int> v(10);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    v.Reserve(5);
    v.DumpToSize();
    v.DumpToCap();
}

void Test17()
{
    Vector<int> v(5);
    for (int i = 0; i < v.Size(); i++)
        v[i] = rand() % 100;

    std::sort(v.Begin(), v.End());
    v.DumpToSize();
}

// Test Insert 1
void Test18()
{
    Vector<int> v(5);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    v.Insert(v.Begin(), -1);
    v.DumpToSize();
}

// Test Insert 2
void Test19()
{
    Vector<int> v(5);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    auto it = v.End();

    v.Insert(it, -1);
    v.DumpToSize();
}

// Test Insert 3
void Test20()
{
    Vector<int> v(5);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    auto it = v.Begin();
    it += 3;

    v.Insert(it, -1);
    v.DumpToSize();
}

// Test Erase(Iter) 1
void Test21()
{
    Vector<int> v(5);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    auto it = v.Begin();
    v.Erase(it);
    v.DumpToSize();
}

// Test Erase(Iter) 2
void Test22()
{
    Vector<int> v(5);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    auto it = v.End() - 1;
    v.Erase(it);
    v.DumpToSize();
}

// Test Erase(Iter) 3
void Test23()
{
    Vector<int> v(5);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    auto it = v.End() - 3;
    v.Erase(it);
    v.DumpToSize();
}

// Test Erase(Iter) 4
void Test24()
{
    Vector<int> v(1, -1);

    v.Erase(v.Begin());
    v.DumpToSize();
}

// Test Erase(Iter, Iter) 1
void Test25()
{
    Vector<int> v(5);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    auto start = v.Begin();
    auto end   = v.End();
    v.Erase(start, end);
    v.DumpToSize();
}

// Test Erase(Iter, Iter) 2
void Test26()
{
    Vector<int> v(10);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    auto start = v.Begin() + 1;
    auto end   = v.End()   - 2;
    v.Erase(start, end);
    v.DumpToSize();
}

// Test Erase(Iter, Iter) 3
void Test27()
{
    Vector<int> v(10);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    auto start = v.Begin() + 6;
    auto end   = v.End() - 1;
    v.Erase(start, end);
    v.DumpToSize();
}

// Test Erase(Iter, Iter) 4
void Test28()
{
    Vector<int> v(10);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    auto start = v.Begin();
    auto end   = v.Begin();
    v.Erase(start, end);
    v.DumpToSize();
}

// Test Erase(Iter, Iter) 5
void Test29()
{
    Vector<int> v(10);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    auto start = v.Begin();
    auto end   = v.Begin() + 1;
    v.Erase(start, end);
    v.DumpToSize();
}

// Test reverse_iterator 1
void Test30()
{
    Vector<int> v(5);
    for (int i = 0; i < v.Size(); i++)
        v[i] = rand() % 100;

    std::sort(v.RBegin(), v.REnd());
    v.DumpToSize();
}

// Test reverse_iterator 2
void Test31()
{
    Vector<int> v(5);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    for (auto it = v.RBegin(); it != v.REnd(); ++it)
        printf("%d ", *it);
    printf("\n");
}

// Test allocator 1
void Test32()
{
    DefaultVectorAllocator<int> alloc;

    int* array = alloc.allocate(10); 

    for (int i = 0; i < 10; i++)
    {
        array[i] = i + 1;
        printf("%d ", array[i]);
    }
    printf("\n");

    alloc.deallocate(array, 10);
}

// Test allocator 2
struct A
{
    A(int a, char c)
    {
        a_ = a;
        c_ = c;
    }

    A(const A&) = default; 

    int  a_;
    char c_;
};

void Test33()
{
    DefaultVectorAllocator<A> alloc;

    A* array = alloc.allocate(2);
    alloc.construct<int, char>(array, -1, 'c');

    alloc.construct(array + 1, array[0]);

    for (int i = 0; i < 2; i++) 
    {
        printf("array[%d].a = %d\n", i, array[i].a_);
        printf("array[%d].c = %c\n", i, array[i].c_);
    }

    alloc.deallocate(array, 2);
}
