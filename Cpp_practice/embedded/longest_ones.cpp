/**
 * Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
https://leetcode.com/problems/max-consecutive-ones-iii/
Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/
#include <iostream>
#include <bitset>
using namespace std;
/*Given binary array, find count of maximum number of consecutive 1’s present in the array.
Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0]
Output: 4
*/
int count_most_ones(int a[], int size)
{
    int max = 0, counter=0;
    for(int i=0; i < size; i++)
    {
        if (a[i]>0){
            counter++;
            max = std::max(counter, max);
        }
            
        if (a[i] == 0){
            //max = std::max(counter, max);//does not work here
            counter = 0;
        }
    }
    return max;
    //time complexity O(n)
}
/* Find the total number of bits needed to be flipped to convert `x` to `y`
Input: x = 65 (01000001), y= 80 (01010000)
Output: The total number of bits to be flipped is 2 
Try bitwise operation
*/
int check_set_bits(int x, int y)
{
    // Brian Kernighan's algorithm is used to find the number of set bits in a number.
    // The idea is to take XOR of the given two integers. If both bits are same, then 0.
    // After calculating the XOR, the problem will reduce to counting set bits in the XOR output.
    int n = x ^ y;
    int count = 0;
    
    while (n)
    {
        std::bitset<8> X(n);
        cout << "num: "<< X << endl;
        n = n & (n - 1); // clear the least significant bit set
        count++;
    }
    return count;
}
int main ()
{
    int a[] = {1,1,0,0,0,1,1,1,1};
    int size = sizeof(a)/sizeof(a[0]);
    // how to intiialise vector from array?
    cout << "Most ones are "<<count_most_ones(a, size)<<" in the array"<<endl;
    cout << "The total number of bits to be flipped is "<< check_set_bits(0,80)<<endl;
    return 0;
}