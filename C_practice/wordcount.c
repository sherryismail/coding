#include <stdio.h>
#include <ctype.h>
#define MAX 50
int main (void)
{
    char show[MAX];// = "Hello world \nHello world\n";
    char c;
    // ^ caret operator is to ignore a particular char
   scanf("%49[^\n]", show);// %* is suppression char. ignore leading 'e's
   printf("%s\n", show);
    short i = 0, chars = 0, words = 0, lines = 0, newword = 0;
    while(show[i] != '\0')
    {  
        if ((show[i] == ' ' || show[i]=='\t') && newword)
        {
            words++;
            newword = 0;
        }
        else if (show[i] == '\n')
        {
            lines++;
        }
        else if (isalnum(show[i])){
            chars++;
            newword = 1; //word starts with a valid char
        }
        i++; 
    }
    printf("chars %3d, words %3d lines %3d\n", chars, words, lines);

    return 0;
}