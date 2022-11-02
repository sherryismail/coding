#include <iostream>
#include <string.h>
#include <vector>
using namespace std;//No, use std::cout instead <-- Good practice
//In C++ it is more normal to put the & with the type in the declaration.
/* Time complexity O(n*log(n)). Also Worst case: O(n*log(n))*/
void merge(vector<int>& arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int i=0, j=0;
     /* create temp arrays */
    vector<int> L;
    vector<int> R;
    L.resize(n1); // size left vector
    R.resize(n2); // size right vector

    for (i = 0; i < n1; i++) {
        L.at(i) = arr.at(low + i); // populate left vector
    }
    for (j = 0; j < n2; j++) {
        R.at(j) = arr.at(mid + j + 1);       // populate right vector
    }

    int x = 0, y = 0, k= low;

while (x < n1 && y < n2)
{
    if (L.at(x) <= R.at(y))
    {
        arr.at(k) = L.at(x);          // merge left vector into v
            x++;
    }
    else
    {
        arr.at(k) = R.at(y);          // merge right vector into v
        y++;
    }
    k++;
}
/* Copy the remaining elements of L[], if there
    are any */
    while (x < n1) {
        arr[k] = L[x];
        x++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (y < n2) {
        arr[k] = R[y];
        y++;
        k++;
    }
}
void merge_sort(vector<int>& arr, int low, int high)
{
    //base case
    if(arr.size() <= 1)
    return;
    //recusrive case
    if ( low < high)//if this bound is not present then loops infinitely
    {
        int mid = (low + high)/2;
        cout << "mid at "<< mid << endl;
        merge_sort(arr, low, mid);    // divide vectors
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main(int argc, char * argv[])
{
    int x = 6;
    cout <<"Enter the size of array: ";
    cin >>x;
    const int size = x; 
    //dynamic memory allocation. Based on size by user entry. Use delete later
    int * arr1 = new int[size];
    //vector resizes itself as we push elements
    vector<int> arr(size);
    cout <<"Enter vector elemnents separated by space: ";
    for (auto &i : arr) {
        //cin >> i;
        i = rand() %10 + 1;
        cout << i << " ";
    }
    cout <<endl<<"Sorted array is: "<<arr.size();
    merge_sort(arr, 0, arr.size()-1);
    for (auto &i : arr) {
        cout<<i<<" ";
    }
}