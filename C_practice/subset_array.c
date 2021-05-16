#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int main()
{
      int x[4] = {1,4,5,3};
    int y[7] = {1,2,3,4,5,6,7};
    int i,j, found = 0;
    for (i=0; i < sizeof(x)/4; i++)
    {
        found = 0;
        for (j=0; j < sizeof(y)/4; j++)
        {
            if (x[i] == y[j])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            //printf("element x[%d]=%u not found ", i, x[i]);
            //break;
        }
        if(found == 1)
        {
            continue;
        }
    }
    if ((found == 1))
         printf("yes subset");
    else
        printf("not a subset");
    return 0;
}