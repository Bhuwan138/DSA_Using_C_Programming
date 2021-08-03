#include <stdio.h>
int LinearSearch(int arr[], int size, int search)
{
    for (int i = 0; i < size; i++)
    {
        if (search == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[100] = {34, 5, 76, 34, 87, 98, 99, 4, 12, 4, 23};
    int size = sizeof(arr) / sizeof(int);
    int search = 2;
    int LS = LinearSearch(arr, size, search);

    if (LS != -1)
    {
        printf("\nThe number %d is found in %d location ", search, LS);
    }
    else
    {
        printf("\nNumber Not FOUND!!!");
    }
}