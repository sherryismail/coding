#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 * 
 * 
 * There is a string,s , of lowercase English letters that is repeated infinitely many times. 
 * Given an integer, , find and print the number of letter a's in the first  
 * letters of the infinite string.
Example s= "abcac", n=10. There are 4 occurances of 'a' in that substring
The substring we consider is , the first  characters of the infinite string. There are  occurrences of a in the substring.
 */

long repeatedString(char* s, long n) {
    long count=0, size = strlen(s);
    int ca=0;
    int remaining = n % size;
    long factor = (n-remaining)/size;

  for (int i = 0; i<size;i++) {
    if (s[i] == 'a')
      ++count;
  }
  count =  count * factor;
  //another for loop to check for i->rem sub-section
  //of the string, id 'a' is there. 'aba'
  //n=10, rem=10%3=1, factor is 3. 
  //There is extra 'a' to add when 'aba' is fitted 3 times in 
  //a total size of 10
  for (int i = 0; i<remaining;i++) {
    if (s[i] == 'a')
      ++count;
  }
    return count;// + ca;
}

int main()
{
    char str[100]; int n;
    printf("Enter aba string: ");
    scanf("%s", &str);
    printf("Enter Total number: ");
    scanf("%d", &n);
    long result = repeatedString(str, n);
    printf("'a' is repeated %d times", result);
    return 0;
}