#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
int Nested_loop(int x[], int M, int y[], int N)
{
     int i,j, found = 0;
     printf("Nested loop:\n");
 for (i=0; i < M; i++)
    {
        found = 0;
        for (j=0; j <N; j++)
        {
            if (x[i] == y[j])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            printf("element x[%d]=%u not found\n", i, x[i]);
            break;
        }
        if(found == 1)
        {
            continue;
        }
    }
    if ((found == 1))
         printf("yes subset\n");
    else
        printf("not a subset\n");
}
void method_frequency(int sub[], int M, int arr[], int N)
{
    //If assumption is that values are [0,N] for N sized array
    printf("Frequency  method:\n");
int i=0, found=0;
int frequency[N];
for(i=0;i<N;i++)
	frequency[i] = 0;
for(i=0; i < N;i++)
{
	frequency[arr[i]]++;
}
for (i=0;i<M;i++)
{
	if(frequency[sub[i]] > 0)
	{
		frequency[sub[i]]--;
		found = 1;
	}
	else {
		found= 0;
        printf("element sub[%d]=%u not found\n", i, sub[i]);
		break;
	}
}
 if (found == 1)
         printf("yes subset\n");
    else
        printf("not a subset\n");
}

void main()
{
      int x[4] = {1,4,9,8};
    int y[7] = {1,2,4,5,3,8,6};
   
    int M= sizeof(x)/4;
    int N=  sizeof(y)/4;
  Nested_loop(x,M,y,N);
   method_frequency(x,M,y,N);

}