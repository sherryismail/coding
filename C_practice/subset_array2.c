#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
//sort array1 O(nlogn)
//then binary search O(mlogm)

void swap(int*x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y= temp;

}
void print_elements(int number[], int count)
{
   int k=0;
   for (k=0; k<count;k++)
    printf("%d ",number[k]);
   printf(".");
}
int partition(int arr[], int low, int high)
{
    int pivot = high;
    int j, i= low-1;
    for(j=low;j<=high-1;j++)
    {
        if(arr[j] < arr[pivot])
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
        //else keep 'i' in its position
    }
    swap(&arr[i+1], &arr[pivot]);
    return (i+1);
}
void quicksort(int arr[], int low, int high)
{
    int pivot;
    if(low< high)
    {
        pivot = partition(arr,low,high);
        quicksort(arr, low, pivot-1);
        quicksort(arr,pivot+1, high);
    }
}
int binarysearch(int arr[], int low, int high, int value)
{
    int mid;
    if(low <= high)
    {
        mid = (low+high)/2;
        if(value == arr[mid] || mid==0)//(mid == 0 || (value == arr[mid] && value > arr[mid-1]))
        return mid;
        else if (value > arr[mid])
            binarysearch(arr,mid+1,high,value);
        else
            binarysearch(arr,low,mid-1,value);
    }
    else
    return -1;

}
void main()
{
    int x[4] = {1,4,9};
    int y[7] = {1,2,4,9,3,8,6};
    int found = 0, i=0;
    int M= sizeof(x)/4;
    int N= sizeof(y)/4;
    quicksort(y,0,N-1);
    print_elements(y,N);
    for (i=0; i < M; i++)
    {
        if(binarysearch(y,0,N-1,x[i]) > -1)
            {
                found = 1;
            }
            else
            {
                found = 0; break;
            }
    }
     if (found == 1)
         printf("yes subset\n");
    else
        printf("not a subset\n");

}