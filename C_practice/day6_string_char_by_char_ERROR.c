#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#define LENGTH_OF_S 10050
#define EVEN_LEN   LENGTH_OF_S/2 +1 
#define ODD_LEN     LENGTH_OF_S/2 + 1
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int number_of_cases;
    scanf("%d", &number_of_cases);
    int i=0,j=0, size = 0;
    char * str=malloc(number_of_cases * LENGTH_OF_S) ;
    assert(number_of_cases >= 1);
    assert(number_of_cases <= 10);
    for (i = 0; i < number_of_cases; i++)
    {
        scanf("%ms", &str[i]);
        if(strlen(str[i]) > LENGTH_OF_S)
        {
            number_of_cases = i;
            break;
        }
    }
    
    char * c = str[0];
    char onechar;
    char even[EVEN_LEN], odd[EVEN_LEN];
    for (i = 0; i < number_of_cases; i++)
    {
        c = str[i];
        j=0;
        while (*c != '\0')
        {
            onechar = *c;
            if (j%2==0)
                strncat(&even[0],c, 1);
            else
                strncat(&odd[0], c, 1);
            ++onechar;
            j++;
        }
        printf("%s %s\n",&even[0], &odd[0]);
        even[0]= '\0';//empty the string, for strncat()
        odd[0] = '\0'; //put null char at the start
    }
    return 0;
}

/*Sample Input

2
Hacker
Rank
Sample Output

Hce akr
Rn ak */