#include <stdio.h>

int change(int *);
int main()
{
    int a = 5, b;
    printf("Value of A = %d\n", a);

    change(&a);
    printf("Value of A = %d\n", a);
    return 0;
}

// Function Defination
int change(int *a)
{
    *a = 20;
    return *a;
}