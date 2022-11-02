#include <stdio.h>
void algo_merge_sort(int val[], int counter1, int counter2);
void perfrom_merge(int val[], int counter11, int counter12, int counter22, int counter21);

//Indent Ctrl+K , Ctrl + F
int main()
{
    int val[100], count, i;
    printf("Please enter the total count of the elements that you want to sort: \n");
    scanf("%d", &count);
    printf("Please input the elements that has to be sorted:\n");
    for (i = 0; i < count; i++)
        scanf("%d", &val[i]);
    algo_merge_sort(val, 0, count - 1);
    printf("\n Output generated after using quick sort \n");
    for (i = 0; i < count; i++)
        printf("%d ", val[i]);
    return 0;
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void algo_merge_sort(int val[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        algo_merge_sort(val, low, mid);
        algo_merge_sort(val, mid + 1, high);
        //perfrom_merge(val, low, mid, mid + 1, high);
        merge(val, low, mid, high);
    }
}
void perfrom_merge(int val[], int lowest, int low, int high, int highest)
{
    int temp_val[50];
    int c1, c2, c3;
    c1 = lowest;
    c2 = high;
    c3 = 0;
    while (c1 <= low && c2 <= highest)
    {
        if (val[c1] < val[c2])
            temp_val[c3++] = val[c1++];//store from lower half
        else
            temp_val[c3++] = val[c2++];//store from upper half
    }
    while (c1 <= low)
        temp_val[c3++] = val[c1++];
    while (c2 <= highest)
        temp_val[c3++] = val[c2++];
    for (c1 = lowest, c2 = 0; c1 <= highest; c1++, c2++)
        val[c1] = temp_val[c2];
}