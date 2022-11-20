#include <stdio.h>
#include <string.h>
int count = 0;
int palindrome (char str[], int first, int last);
int palindrome (char str[], int first, int last)
{
    if (first == last)//start with simplest case of 'h'
        return 1;
    if(str[first] != str[last]) //simpel case, != gaem over and exit
        return 0;
    if (first < last + 1)
        return  palindrome(str,first+1, last-1);
    
}

int main()
{
    char str[] = "radar1";
    int result;

    result = palindrome(str,0, strlen(str)-1);
    if (result)
        printf("yes");
        else
        printf("no");
}