/*
    * Name  : Bhuwan Raj Pandey
    * Date  : Thursday , April , 29 , 2021
*/
#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of Array : ");
    scanf("%d",&n);


    int a[n],i;

    //Input the array value
    for ( i = 0; i < n; i++)
    {
        printf("Enter the value of a[%d] : ",i+1);
        scanf("%d",&a[i]);
    }

    //Run loop in reverse order and print the output
    for ( i = n-1; i >=0; i--)
    {
        printf("%d\t",a[i]);
    }
    

    return 0;
}


//Uning Temp variable
/*
    int temp;
    for ( i = 0; i < n; i++)
    {
        for ( int j = 0; j < i; j++)
        {
            
        
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        }
    }*/


//Uning Temp variable another method
/*
    int temp;
    for ( i = 0; i < n-1; i++)
    {
        for ( int j = i+1; j < n; j++)
        {
            
        
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        }
    }*/