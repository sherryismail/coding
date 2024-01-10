/*Given an integer array, find the contiguous subarray
 (containing at least one number) with the largest sum 
 or in other words the maximum sum contiguous subarray and print its sum.*/
#include <bits/stdc++.h>
using namespace std;
//method 1 : brute force
int largest_subarray(vector<int> &arr)
{
    int n = sizeof(arr)/sizeof(arr[0]);
	vector<int>v1;
	//To choose the starting point of subarray
	for(int i=0;i<n;i++)
	{
        //To choose the end point of subarray
        for(int j=i;j<n;j++)
    	{
        	int temp_sum= 0;
            //Finding the sum of the subarray
            for(int k=i;k<=j;k++)
        	{
        	    temp_sum = temp_sum + arr[k];
            }
            v1.push_back(temp_sum);// storing sum in a vector
    	}
	}
	//To print the individual subarray sum..
    cout << "Sum of individual Subarray: ";
    for (int i = 0; i < v1.size(); i++)
            cout << v1[i] << " ";
    cout << endl;
	//To print the maximum sum contiguous subarray
    int max =  *max_element(v1.begin(), v1.end());
	cout << "Maximum Sum Contiguous Subarray = "<< max;
    return max;
}
//kadane's algorithm
int find_max_sum_sub_array(int A[], int n) {
  if (n < 1) {
    return 0;
  }
  
  int curr_max = A[0];
  int global_max = A[0];
  for (int i = 1; i < n; ++i) {
    if (curr_max < 0) {//like A[i] < curr_max + A[i]
        /* if maximum sum is negative, 
        set it to current element (which represents an empty sub-array) */
      curr_max = A[i];
    } else {
        /* update maximum sum of subarray "ending" at index i 
        (by adding the current element to maximum sum ending 
        at previous index i-1) */
      curr_max += A[i];
    }
//update result if current subarray sum is found to be greater
    if (global_max < curr_max) {
      global_max = curr_max;
    }
  }
	cout << endl<<"Kadanes: Maximum Sum Contiguous Subarray = "<< global_max;

  return global_max;
}
int main()
{
	// int a[] = {-2, 3, 4, -1, 2, 1, 5, -3};
    int a[] = {2, 3, 4, 1, 2, 1, 5, 3};
    int size = sizeof(a)/sizeof(int);
    // how to intiialise vector from array?
    vector<int> arr(a, a+size);
    int max = largest_subarray(arr);
	find_max_sum_sub_array(a,size);
    return 0;
}