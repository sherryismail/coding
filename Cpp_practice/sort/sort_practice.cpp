#include <iostream>
#include <vector>
using namespace std;

class Sort
{
    public:
    Sort(){}
    ~Sort(){}
    void swap(int *a, int *b)
    {
        int temp = *b;
        *b = *a;
        *a = temp;
    }
    int partition(vector<int>& arr, int low, int high)
    {
        int i=low, j=high;
        int pivot = low;
        if (low < high)
        {
            while (i <j)
            {
                while(arr[i] <= arr[pivot] && i < high)
                    i++;
                while (arr[j] > arr[pivot])
                    j--;
                if (i<j)
                    swap(&arr[i], &arr[j]);
            }
            swap(&arr[j],&arr[pivot]);
            return j;
        }else
            return -1;
    }
    void quick_sort(vector<int>& arr, int low, int high)
    {
        
        if (low < high)
        {
            int part = partition(arr,low,high);
            if (part != -1){
                quick_sort(arr,low,part-1);
                quick_sort(arr,part+1,high);
            }
           
        }else
        return;

    }
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        int n = mid - low + 1;
        int m = high - mid;
        vector<int> L,R;
        L.resize(n);
        R.resize(m);
        for (int i = 0; i < n; i++)
            L.at(i) = arr.at(low+i);
        for (int i=0; i < m; i++)
            R.at(i) = arr.at(mid + i + 1);

        int x=0, y=0, k=low;
        while (x < n && y < m)
        {
            if (L[x] < R[y])
            {
                arr[k] = L[x];
                x++;
            }else
            {
                arr[k] = R[y];
                y++;
            }
            k++;
        }
        for (; x < n; x++, k++)
            arr[k] = L[x];
        for (; y< m; y++, k++)
            arr[k] = R[y];
    }
    void merge_sort(vector<int>&arr, int low, int high)
    {
         //base case
        if(arr.size() <= 1)
        return;
        //rescursive
        if (low < high)
        {
            int mid = (low+high)/2;
            merge_sort(arr,low,mid);
            merge_sort(arr,mid+1,high);
            merge(arr,low,mid,high);
        }else //base case
            return;
    }
};
#ifdef ANOTHER_APP_USE
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
    vector<int> arr2;
    cout <<"Enter vector elemnents separated by space: ";
    for (auto &i : arr) {
        cin >> i;
        arr2.push_back(i);
        //i = rand() %10 + 1;
    }
    class Sort msort;
    cout <<endl<<"Quick sort result is: ";
    msort.quick_sort(arr, 0, size-1);
    for (auto &i : arr) {
        cout<<i<<" ";
    }
    cout <<endl<<"Merge sort is: ";
    msort.merge_sort(arr2, 0, size-1);
    for (auto &i : arr2) {
        cout<<i<<" ";
    }
}
#endif
