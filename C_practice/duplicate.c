/* method 1
nested for loop
Time complexity O(N^2)

method 2
sort the array -> O(N log N)
one for loop to check if
    if(num[i] == num[i+1])
    Time complexity -> O(N)

method 3
    use frequency method if arr[i] <= N
    one for loop to populate freq[arr[i]]
    second to check if freq[i] > 1. 
    time complexity is O(2*N) => O(N)
    */

//in the array all numbers have duplicate. They repeat twice except one, find that number.
//Use XOR of numbers
int singleNumber(int* nums, int numsSize){
    int sum = 0;
    for(int i=0; i < numsSize; i++)
    {
        sum ^= nums[i];
    }
    return sum;
    }

/*Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Example 1:

Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1
*/
#include <string.h>
#include <stdio.h>
#define     ALPHABET 26
int findUniqueCharacter(char * s)
{
   
    char alphabet[ALPHABET] = 0;
    char * start = &alphabet[0];
    memset(start, 0, sizeof(char) * ALPHABET);
    for(int i=0; i <strlen(s);i++)
    {
        alphabet[s[i] -'a']++;
    }
    for(int i=0; i < ALPHABET; i++)
    {
        if(alphabet[i] > 1)
            return i;
    }
    return -1;
}
void main(void)
{
    
}
