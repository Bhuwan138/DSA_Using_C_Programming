 #include<stdio.h>
void Merge_sort(int [],int , int );
void merge(int  [],int ,int , int );



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
    


    printf("\nBefore Sort : \n\n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    } 
    int left = 0;
    int right = n-1;

    Merge_sort(arr,left,right);

    printf("\nAfter Sort : \n\n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    } 
    return 0;
}

void Merge_sort(int arr[],int left, int right ){
    if(left < right){
        int mid = (left + right)/2;
        Merge_sort(arr,left,mid);
        Merge_sort(arr,mid + 1,right);
        merge(arr,left,mid,right);
    }
}

void merge(int arr [],int left,int mid, int right){
    int b[20];

    int i=left;
    int j = mid+1;
    int k = left;

    while(i <= mid && j<= right){
        if(arr[i]< arr[j]){
            b[k] = arr[i];
            i++;
        }
        else{
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    if(i > mid){
        while(j <= right){
            b[k] = arr[j];
            j++;
            k++; 
        }
    }
    else
    {
        while(i<= mid){
            b[k] = arr[i];
            i++;
            k++;
        }
    }

    for ( i = left; i <= right ; i++)
    {
        arr[i] = b[i];
    }
    
}
