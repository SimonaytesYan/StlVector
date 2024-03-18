#include <stdio.h>

#include "Vector.hpp"

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

const size_t test_number = 4;

int main()
{
    printf("TEST 1\n");
    Test1();
    printf("TEST 2\n");
    Test2();
    printf("TEST 3\n");
    Test3();
}