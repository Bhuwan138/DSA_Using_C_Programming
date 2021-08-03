/*
    * Name  : Bhuwan Raj Pandey
    * Date  : Monday , July , 05 , 2021
*/

#include <stdio.h>

void display(int arr[], int size)
{
    // traversing array || displaying array
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] : %d\n", i, arr[i]);
    }
    printf("\n");
}

int insertArray(int arr[], int size, int capacity, int index, int insert)
{
    // Inserting Element in array
    if (size >= capacity)
    {
        printf("=======Error ! No more capacity to insert=======\n");
        return -1;
    }

    for (int i = size; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = insert;
    return 0;
}

int main()
{
    int size, capacity = 100, index, insert;

    //Entering Capacity of Array
    printf("Enter the Capicity of Array : ");
    scanf("%d", &capacity);

    int arr[capacity];

    //Entering Size of Array
    printf("Enter the Size of Array : ");
    scanf("%d", &size);

    //Inserting Array Element
    for (int i = 0; i < size; i++)
    {
        printf("Enter the arr[%d] element : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n\nYour Array is -->\n");
    display(arr, size);

    //Entering Index Number
    printf("\nEnter the Index Number in which you want to put element : ");
    scanf("%d", &index);

    //Inserting Element
    printf("\nInsert the Number : ");
    scanf("%d", &insert);
    insertArray(arr, size, capacity, index, insert);
    size += 1;
    display(arr, size);
}

/* ---not a Dynamic method---
int main()
{
    int arr[100] = {3, 65, 2, 5, 6, 56};
    int size = 6, capacity = 100, index = 2, insert = 22;
    display(arr, size);
    insertArray(arr, size, capacity, index, insert);
    size += 1;
    display(arr, size);
}
*/