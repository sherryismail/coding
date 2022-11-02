#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
/* Time complexity O(n*log(n)). Worst case: O(n2)*/
void swap(int *x, int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}
int partition_first(vector<int> &arr, int first, int last)
{
    int i,j,pivot;
    if(first < last)
    {
    pivot=first;
    cout <<"Pivot "<< arr[pivot]<< " . ";
    i=first;
    j=last;
    while(i< j)
    {
        while(arr[i]<=arr[pivot] && i<last)//numbers on LHS 
            i++;//stop if are not less than num[pivot]. swap needed here
        while(arr[j]>arr[pivot])//numbers on RHS 
            j--;//stop if numbers are not greater than num[pivot]. swap needed here
        if(i<j)
        {
            cout <<"Swap "<< arr[i] << " <-> "<< arr[j]<< "; ";
            swap(&arr[i],&arr[j]);
        }
    }
    //swap the pivot with jth element so pivot is the largest number from first,....pivot
    //swap with the final element on the right that stops being bigger than pivot=low
    //newest arr[j] is smaller than pivot so pivot should be inserted in the middle
    cout <<"Final Swap  "<< arr[i] << " <-> "<< arr[pivot]<<endl;
        swap(&arr[j],&arr[pivot]);
       
        return j;
    }else
        return -1;
}
void quick_sort_first(vector<int> &arr, int first, int last)
{
    //base case
    if(first >= last)
        return;
    int partition = partition_first(arr,first,last);
    if(partition != -1)
    {
    quick_sort_first(arr,first,partition-1);
    quick_sort_first(arr,partition+1,last);
    }
    
}
int main (void)
{
    int x = 6;
    cout <<"The size of array: ";
    cin >>x;
    const int size = x; 
    //dynamic memory allocation. Based on size by user entry. Use delete later
    int * arr1 = new int[size];
    //vector resizes itself as we push elements
    vector<int> arr(size);
    cout <<"Enter vector elemnents separated by space: ";
    for (auto &i : arr) {
        cin >> i;
        //i = rand() %10 + 1;
    }
    cout <<endl<<"Sorted array is:";
    quick_sort_first(arr, 0, size-1);
    for (auto &i : arr) {
        cout<<i<<" ";
    }
    
}
