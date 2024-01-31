#include <iostream>
#include <bits/stdc++.h> //unordered_set
#include <map>
#include "../sort/sort_practice.cpp"
using namespace std;
//Find whether an array is subset of another array
void isSubeset(int a[], int b[], int m, int n)
{
    //hashset_method: This method works if repeated elemets are counted as one
    //O(m+n*logm)
    unordered_set<int> database;
    for (int i=0; i < m; i++)
        database.insert(a[i]);
    int size = database.size();
    for (int i=0; i < n; i++)
    {
        database.insert(b[i]);
    }
    if (database.size() == size) //some new values are added
        cout << "b is a subset of a" << endl;
    else
        cout << "b is not a subset of a"<< endl;
    // for(const string &text : texts)
    //     cout << "value of text: " << text << endl;

}
//mthod 2: Sorting and merging
//O(mLog(m) + nLog(n))

//method 3: Sorting and Binary search
//O(mLog(m)) for sorting and O(nlog(m)) binary search
//in worst case its O(m^2)
int binarysearch(vector<int> &arr, int low, int high, int search)
{
    if (low <= high)//important: if() = recursive, while (iterative)
    {
        int mid = (low + high)/2;
        //base case
        if (arr[mid] == search)
        {
            cout << "arr[" <<mid<<"]= "<<search <<" found"<<endl;
            return mid;//return the index
        }
        else if(arr[mid] > search)
        {
            //value is too low so revise higher boundary
            high = mid -1; 
            cout << mid << " too low "<<endl;
            binarysearch(arr,low,high,search);
        }
        else if(arr[mid] < search)
        {
            //value is too high so revise the lower boundary
            low = mid + 1; 
            cout << mid<< " too high "<<endl;
            binarysearch(arr,low,high,search);
        }
    }
    else //problem: it works but return from non-void func warning
    {
        cout << "nothing found for "<<search<<endl;
        return -1;
    }

}
bool sort_and_binary_search(int a[], int b[], int m, int n)
{
    //when a[] is passed by reference, it is not by value. so size should be passed
    //convert array to vector
    vector<int> arr(a, a+m);
    class Sort msort;
    msort.quick_sort(arr, 0, m-1);
    for(int i=0; i < n; i++)
    {
        if (binarysearch(arr,0,m-1, b[i]) == -1)
        {
            cout << "b is a not a subset of a"<<endl;
            return false;
        }
    }
    //If we reach here then all elements of a[] are present in b[]
    cout << "b is a subset of a"<<endl;
    return true;
}

//mthod 4: freq method
//limitation: all the elements in value are no larger than the size of 'm'
void freq(int a[], int b[], int m, int n)
{

    map<int,int> frequency;
    int notfound = 0;
    for (int i=0; i < m ; i++)
    {
        frequency[a[i]]++;
    }
    for (int i=0; i <n; i++)
    {
        if (frequency[b[i]]> 0)//if b's element was already couted in upper loop
            frequency[b[i]]--;
        else
        {
            //this element of b di dnot exist in a
            cout << "Element "<< b[i] << " not found"<<endl;
            notfound = 1;
        }
    }
    if (notfound == 0) cout << "Freq method: b is a subset of a" << endl;
}

int main()
{
    int a[]={1,2,3,4,5,6};
    int b[]= {2,3,4};
    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);
    // cout << "Hash set method: ";
    // isSubeset(a,b,m,n);
    // cout << "Freq method: ";
    // freq(a,b,m,n);
    cout << "Sort and binary search method:";
    bool ret = sort_and_binary_search(a,b,m,n);
    return ret;
}