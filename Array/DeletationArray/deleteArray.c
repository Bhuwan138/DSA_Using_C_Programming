/*
    * Name  : Bhuwan Raj Pandey
    * Date  : Tuesday , July , 06 , 2021
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

void deleteArray(int arr[], int size, int index)
{
    //code for deletation
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}
int main()
{
    int arr[100];
    int size, index = 0;

    //Entering Size of Array
    printf("Enter the Size of Array : ");
    scanf("%d", &size);

    //Inserting Array Element
    for (int i = 0; i < size; i++)
    {
        printf("Enter the arr[%d] element : ", i);
        scanf("%d", &arr[i]);
    }

    //Displaying Array
    printf("\n\nYour Array is -->\n");
    display(arr, size);

    //Entering Index Number
    printf("\nEnter the Index Number in which you want to delete element : ");
    scanf("%d", &index);

    deleteArray(arr, size, index);

    size -= 1;

    //Displaying Array
    printf("\n\nYour Array is -->\n");
    display(arr, size);
}