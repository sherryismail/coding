#include <stdio.h>
#include <stdint.h>
#include <string.h>
int func1(void);
int func2(void);
int func1(void) {
    // printf("\e[1;1H\e[2J");
    printf("This is %s\n", __func__);
    
}
/*
    gcc -c -fanalyser cyclomatic_redirect.c
    only gcc 10+ allow -fanalyser
*/
int func2(void) {
    printf("This is %s\n", __func__);
}
int main ()
{
    int x = 0;
    setbuf(stdout, NULL); 
    while(1){
        printf("\nEnter a number: ");
        scanf("%d", &x);
       fflush(stdout);
        if (x>0)
            func1();
        else
            func2();
    }
}