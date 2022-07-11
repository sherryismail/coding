#include <stdio.h>
#include <string.h>
int main ()
{
    char str[31];//if INT_MAX is 2^31 = 2147...
    scanf("%s", str);
    int temp = 0;
    for (int i = 0; i < strlen(str); i++) {
        //only works if 6-digit number, not for 2/3/4 digits
        // Since ASCII value of character from '0'
        // to '9' are contiguous. So if we subtract
        // '0' from ASCII value of a digit, we get 
        // the integer value of the digit.
        temp = temp * 10 + (str[i] - '0');
    }
    printf("num is %d", temp);
    return 0;
}


/*Read a string, , and print its integer value; 
if  cannot be converted to an integer, print Bad String.
Note: You must use the String-to-Integer and exception handling constructs built into your submission language. If you attempt to use loops/conditional statements, you will get a  score.

Input Format
A single string, S.
Constraints
1 <= |S| <= 6, where |S| is the length of string S.
S is composed of either lowercase letters (a-z) or decimal digits (0-9).
Output Format
Print the parsed integer value of , or Bad String if  cannot be converted to an integer.

Sample Input 0
3
Sample Output 0
3
Sample Input 1
za
Sample Output 1
Bad String
Explanation

Sample Case 0 contains an integer, so it should not raise an exception 
when we attempt to convert it to an integer. 
Thus, we print the 3.
Sample Case 1 does not contain any integers, so an attempt to convert it 
to an integer will raise an exception. Thus, our exception handler 
prints Bad String. */