/* Flow control and debugging by eye? */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
int main ()
{
char buf[4] = {1,2,3,'\0'};
char * rd = &buf[0];
int count = 0;

printf("---------------Before memcpy--------\n");
while (count < 4) {
    printf("%d ", *rd);
    rd++;
    count++;
}
memcpy(buf, buf+4, 4);
printf("\n---------------After memcpy--------\n");
rd = &buf[0];
count = 0;
while (count<4) {
    printf("%d ", *rd);
    rd++;
    count++;
}
}