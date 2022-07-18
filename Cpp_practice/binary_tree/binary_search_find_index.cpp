#include <vector>
#include <iostream>
using namespace std;

//mnethod 1
int find_low_index(vector<int>& arr, int key) {

  int low = 0;
  int high = arr.size() -1;
  int mid = high/2;
  while(low <= high)
  {
    if(arr[mid] < key)
      low = mid+1;
    else if(arr[mid] >= key)
      high = mid-1;
    mid = low + (high-low)/2;//tricky
  }
  if (low < arr.size() && arr[low] == key)
    return low;
  return -1;
}
//method 2
int find_high_index(vector<int>& arr, int key) {

    int high=-1, found =0;
  for(int i=0; i < arr.size() -1; i++)
  {
    if(arr[i] == key)
    {
      if(i >high)
        high =i;
        found =1;
    }
  }
  if(found)
    return high;
  return -1;
}
/*
1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 6, 6
*/