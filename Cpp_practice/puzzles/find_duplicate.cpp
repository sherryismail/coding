#include <bits/stdc++.h>
using namespace std;
// C++ program to print all elements that
// appear more than once.
#include <iostream>
using namespace std;

// function to find repeating elements
void printRepeating(int arr[], int n)
{
    // First check all the values that are
    // present in an array then go to that
    // values as indexes and increment by
    // the size of array
    for (int i = 0; i < n; i++) 
    {
        int index = arr[i] % n;
        arr[index] += n;//go to index and increase value
    }
    /* clarifying Question 1: is the value of all elements of the array 
     in range 0 < auto &i < size(array)
     clarifying Question 2: can I use data structure ? No
     clarifying Question 3: should the check be done in place? yes
    */
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;
    // Now check which value exists more
    // than once by dividing with the size
    // of array
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] / n) >= 2)
            cout << i << " "<<"because val is " << (arr[i] / n) << "\n";
    }
}

// Driver code
int main()
{
    int arr[] = {1,4,5,6,7,8,8,8, 4};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "The repeating elements are: "<<arr_size << "\n";

    // Function call
    printRepeating(arr, arr_size);
    return 0;
}
