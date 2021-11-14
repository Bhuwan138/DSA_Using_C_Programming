#include<stdio.h>
int linear_search(int [], int , int );
int binary_search(int [], int , int );


int main(){
    int n,x;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the value of array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the number which you want to search :  ");
    scanf("%d",&x);
    if(binary_search(arr,n,x) == -1)
        printf("Element not found !!!");
    else
        printf("Element found at %d location",linear_search(arr,n,x));

    return 0;
}
int linear_search(int arr[], int n , int x ){
    for (int i = 0; i < n; i++)
    {
        if(x == arr[i]){
            return i;
        }
    }
    return -1;
    
}

int binary_search(int arr[], int n , int x ){
    int low=0, mid, high = n-1;
    while(low <= high){

        mid = (low + high)/2;

        if(x == arr[mid])
            return mid;
        
        if(x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;

}