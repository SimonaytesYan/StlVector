#include <stdio.h>

#include "Vector.hpp"

void PrintTestNum();
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();

const size_t test_number = 5;

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

// Test 1 front and back
void Test2()
{
    Vector<int> v(1);

    int& front = v.front();
    int& back  = v.back();

    front = -1;
    printf("v[0] = %d\n", v[0]);

    back = -2;
    printf("v[0] = %d\n", v[0]);
}

// Test 2 front and back
void Test3()
{
    Vector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = i;
    
    v.front() = -1;
    v.back()  = 100;
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
