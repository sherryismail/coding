#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
int main (void)
{
    char show[MAX] = "Hello world \nHello world\n";
    char c;
    scanf("%[^\n]s", &show);
    int i = 0, words = 0, lines = 0;
    while(show[i] != '\0')
    {  
        if (show[i] == ' ' || show[i]=='\t')
            words++;
        else if (show[i] == '\n')
        {
            lines++;
        }
        else if (show[i] < 32 && show[i] > 122)
            continue;
        //if it is \n or ' ', it is still a char
        else
            i++;
    }
    printf("chars %d, words %d lines %d\n", i, words, lines);

    return 0;
}