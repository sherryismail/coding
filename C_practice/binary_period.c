

#include <stdio.h>
#include <stdint.h>
#include <string.h>

int solution(int n) {
    int d[30];
    int l = 0;
    int p;
    while (n > 0) {
        d[l] = n % 2;
        n /= 2;
        l++;
    }
    /*
for (c = 31; c >= 0; c--)
    {
        k = n >> c;
        if (k & 1)
            printf("1");
        else
            printf("0");
        }
    } 

    */

   //start from centre
    for (p = 1; p < (1 + l)/2; ++p) {
        int ok = 1;
        int i;
        for (i = 0; i < l - p; ++i) {//start from offet from end
             //printf("inner loop d[i]=%d, d[i+p]=%d\n", d[i],d[i+p]);
            if (d[i] != d[i + p]) {
                ok = 0;//not periodic
                break;
            }
        }
        if (ok) {
            return p;
        }
    }
    return -1;
}

int main() {
  
  /* Put any tests here. */
  printf("%d", solution(1651));//955
  return 0;
}