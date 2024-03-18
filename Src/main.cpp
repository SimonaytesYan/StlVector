#include <stdio.h>

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
}

void PrintTestNum()
{
    static size_t test_cnt = 0;
    fprintf(stderr, "======================================\n");
    fprintf(stderr, "TEST %d\n", ++test_cnt);
    fprintf(stderr, "+++++++\n");
}

// Test simple constructor and operator[]
void Test1()
{
    Vector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = 10 - i;

    for (int i = 0; i < 10; i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");
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
    for (int i = 0; i < 10; i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");
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
    for (int i = 0; i < v.Size(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");
    
    for (int i = 0; i < v.Capacity(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");
}

// Test push_back 2
void Test7()
{
    Vector<int> v(0);
    v.PushBack(100);

    for (int i = 0; i < v.Size(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");

    for (int i = 0; i < v.Capacity(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");
}

// Test push_back 3
void Test8()
{
    Vector<int> v(0);
    v.PushBack(-1);
    v.PushBack(-2);
    v.PushBack(-3);
    v.PushBack(-4);

    for (int i = 0; i < v.Size(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");

    for (int i = 0; i < v.Capacity(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");
}

// Test pop_back 1
void Test9()
{
    Vector<int> v(1, 10);
    v.PopBack();
    v.PopBack();

    for (int i = 0; i < v.Size(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");

    for (int i = 0; i < v.Capacity(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");
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

    for (int i = 0; i < v.Size(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");

    for (int i = 0; i < v.Capacity(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");
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
    for (int i = 0; i < v.Size(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");

    for (int i = 0; i < v.Capacity(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");
}

// Test Resize 2
void Test13()
{
    Vector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = i + 1;

    v.Resize(5);
    for (int i = 0; i < v.Size(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");

    for (int i = 0; i < v.Capacity(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");
}

// Test Resize 3
void Test14()
{
    Vector<int> v(5);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    v.Resize(10, -1);
    for (int i = 0; i < v.Size(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");

    for (int i = 0; i < v.Capacity(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");
}

// Test Reserve 1
void Test15()
{
    Vector<int> v(5);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    v.Reserve(10);
    for (int i = 0; i < v.Size(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");

    for (int i = 0; i < v.Capacity(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");
}

// Test Reserve 2
void Test16()
{
    Vector<int> v(10);
    for (int i = 0; i < v.Size(); i++)
        v[i] = i + 1;

    v.Reserve(5);
    for (int i = 0; i < v.Size(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");

    for (int i = 0; i < v.Capacity(); i++)
        fprintf(stderr, "%d ", v[i]);
    fprintf(stderr, "\n");
}
