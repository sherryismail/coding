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
    int i=0,j=0, k = 0;
    scanf("%d", &number_of_cases);
    while ((j=getchar()) != EOF && j != '\n');//added
    
    assert(number_of_cases >= 1);
    assert(number_of_cases <= 10);
    char str[number_of_cases][10];//declare 10 uninitialised strings
    for (i = 0; i < number_of_cases; i++)
    {
        fgets(str[i],10,stdin);
        str[i][strlen(str[i])-1] = '\0';
    }
    
    char * c;
    char onechar;
    char even[EVEN_LEN], odd[EVEN_LEN];
    even[0]= '\0';odd[0] = '\0';//clear the first buffer
    for (i = 0; i < number_of_cases; i++)
    {
        c = (char *)&str[i][0];
        j=0;
        while (*c != '\0')
        {
            onechar = *c;
            if (j%2==0)
                strncat(&even[0], &onechar, 1);
            else
                strncat(&odd[0], &onechar, 1);
            ++c;
            j++;
        }
        even[j]='\0';
        odd[j]='\0';
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