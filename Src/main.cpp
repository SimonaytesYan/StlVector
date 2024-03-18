#include <stdio.h>

#include "Vector.hpp"

int main()
{
    Vector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = 10 - i;

    for (int i = 0; i < 10; i++)
        printf("%d ", v[i]);

    printf("\n");
}