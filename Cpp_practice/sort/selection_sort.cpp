#include <bits/stdc++.h>

using namespace std;
void swap(int * x, int * y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
int main()
{
    int x = 6, index;
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
    cout <<endl<<"Sorted array is: "<<INT16_MIN<<endl;
    int smallest = INT16_MIN;
    for(int i=0; i < arr.size(); i++)
    {
        smallest = arr[i];
        index = i; //this is new
        for (int j=i+1; j < arr.size();j++)
        {
            if(arr[j] < smallest)
            {
                smallest = arr[j];
                index = j;
            }

        }
        swap(&arr[index],&arr[i]);
    }


    for (auto &i : arr) {
        cout<<i<<" ";
    }
}