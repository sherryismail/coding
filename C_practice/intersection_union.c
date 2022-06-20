#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//Given two sorted arrays, find their union and intersection.
void intersection_1(int * arr1, int size1, int * arr2, int size2)
{
    int i,size3=size1+size2;
    int freq[size3];//assume freq table to be sum
    //size3 can be a maxima of N,M
    for(i=0;i<size3; i++)
    {
        freq[i]=0;
    }
    for(i=0;i<size1; i++)
    {
        freq[arr1[i]]++;
    }
    for(i=0;i<size2; i++)
    {
        if(freq[i]>0)
        printf("%d ", i);
    }
}

void union_method1(int * arr1, int size1, int * arr2, int size2)
{
    
    int i,size3=size1+size2;
    int freq[size3];//assume freq table to be sum
    //size3 can be a maxima of N,M
    for(i=0;i<size3; i++)
    {
        freq[i]=0;
    }
    for(i=0;i<size1; i++)
    {
        freq[arr1[i]]++;
    }
    for(i=0;i<size2; i++)
    {
        freq[arr2[i]]++;
    }
    for(i=0;i<size3; i++)
    {
        if(freq[i] > 0)//ignore duplicates
        printf("%d ",i);
    }
    printf("\nIntersection\n");
    intersection_1(arr1,size1,arr2,size2);
}

void union_method2(int * arr1, int size1, int * arr2, int size2)
{
    //duplicates not avoided. Use a do-while loop to 
    /* do {
        ++i;
    }while(a[i] == a[i+1]);
    */
    int i=0,j=0;
    printf("\nUnion is\n");
    while(i<size1 && j< size2)
    {//assume sorted arrays
        if(arr1[i] < arr2[j] )
        printf("%d ",arr1[i++]);
        else if (arr1[i] > arr2[j])
        printf("%d ",arr2[j++]);
        else//equal-->Intersection print
        {
            printf("%d ", arr1[i]);
            i++;j++;
        } 
    }
    while(i<size1)
    printf("%d ",arr1[i++]);
     while(j<size2)
    printf("%d ",arr2[j++]);
}

void main()
{
    int size1,size2;
    printf("\nEnter array1 size:");
    scanf("%d", &size1);
    int * arr1 = (int *)malloc(size1* sizeof(int));
    for(int i=0; i < size1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("\nEnter array2 size:");
    scanf("%d", &size2);
    int * arr2 = malloc(size2 * sizeof(int));
    for(int i=0; i < size2; i++)
    {
        scanf("%d", (arr2+i));
    }
    intersection_1(arr1,size2,arr2,size2);
    printf("\nUnion\n");
    union_method1(arr1,size2,arr2,size2);
    union_method2(arr1,size2,arr2,size2);
}