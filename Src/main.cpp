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
}

void PrintTestNum()
{
    static size_t test_cnt = 0;
    printf("======================================\n");
    printf("TEST %d\n", ++test_cnt);
    printf("+++++++\n");
}

// Test simple constructor and operator[]
void Test1()
{
    Vector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = 10 - i;

    for (int i = 0; i < 10; i++)
        printf("%d ", v[i]);
    printf("\n");
}

// Test Front and Back 1
void Test2()
{
    Vector<int> v(1);

    int& front = v.Front();
    int& back  = v.Back();

    front = -1;
    printf("v[0] = %d\n", v[0]);

    back = -2;
    printf("v[0] = %d\n", v[0]);
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
        printf("%d ", v[i]);
    printf("\n");
}

// Test size
void Test4()
{
    Vector<int> v1(10);
    printf("size     = %d\n", v1.Size());
    printf("capacity = %d\n", v1.Capacity());

    Vector<int> v2(100);
    printf("size = %d\n", v2.Size());
}

// Test empty
void Test5()
{
    Vector<int> v1(0);
    printf("empty = %d\n", v1.Empty());
    
    Vector<int> v2(2);
    printf("empty = %d\n", v2.Empty());
}

// Test push_back 1
void Test6()
{
    Vector<int> v(3, 2);
    v.PushBack(-1);
    for (int i = 0; i < v.Size(); i++)
        printf("%d ", v[i]);
    printf("\n");
    
    for (int i = 0; i < v.Capacity(); i++)
        printf("%d ", v[i]);
    printf("\n");
}

// Test push_back 2
void Test7()
{
    Vector<int> v(0);
    v.PushBack(100);

    for (int i = 0; i < v.Size(); i++)
        printf("%d ", v[i]);
    printf("\n");

    for (int i = 0; i < v.Capacity(); i++)
        printf("%d ", v[i]);
    printf("\n");
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
        printf("%d ", v[i]);
    printf("\n");

    for (int i = 0; i < v.Capacity(); i++)
        printf("%d ", v[i]);
    printf("\n");
}

// Test pop_back 1
void Test9()
{
    Vector<int> v(1, 10);
    v.PopBack();
    v.PopBack();

    for (int i = 0; i < v.Size(); i++)
        printf("%d ", v[i]);
    printf("\n");

    for (int i = 0; i < v.Capacity(); i++)
        printf("%d ", v[i]);
    printf("\n");
}

// Test pop_back 2
void Test10()
{
    Vector<int> v(0);

    for (int i = 1; i <= 10; i++)
        v.PushBack(i);
    
    for (int i = 0; i < 5; i++)
    {
        printf("Back = %d\n", v.Back());
        v.PopBack();
    }

    for (int i = 0; i < v.Size(); i++)
        printf("%d ", v[i]);
    printf("\n");

    for (int i = 0; i < v.Capacity(); i++)
        printf("%d ", v[i]);
    printf("\n");
}

// Test pop_back
void Test()
{

}
