#include <stdio.h>

int binarySearch(int arr[], int size, int search)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {

        int mid = (high + low) / 2;
        if (search == arr[mid])
        {
            return mid;
        }

        if (search > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[100] = {2, 34, 54, 65, 78, 98, 90, 234, 547, 879, 890};
    int search = 34;
    //Here size doesnot give the size, so put size manually
    int size = sizeof(arr) / sizeof(int);
    int bs = binarySearch(arr, size, search);
    if (bs != -1)
    {
        printf("\n\nThe Number %d is found at %d location ", search, bs);
    }
    else
    {
        printf("\n\nNumber Not FOUND !!!");
    }
}