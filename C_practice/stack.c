#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int ssize = 100;
typedef struct MinStack{
    int * data;
    int * min;//custom stack because getMin is called so often
    int top;
    int size;
} MinStack;


MinStack* minStackCreate(){
    MinStack * stack = malloc(sizeof(MinStack));
    stack->data = malloc(sizeof(int) * ssize);
    stack->min = malloc(sizeof(int) * ssize);//<--Leetcode issue overflow
    //min is an array that stores as many as data number of elements.
    //at least with each pop(), the top of stack->min is correct
    *stack->min = INT_MAX;
    stack->top = -1;
    stack->size = 0;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
  obj->top++;
  obj->data[obj->top] = val;
  
    
    if(obj->size==0)
    {
        *(obj->min) = val;
    }else
    {//compare with pre-existing values
        if(val < *(obj->min-1) )
            *(obj->min) = val;
        else//same value as old one is now minimum
            *(obj->min) = *(obj->min -1);
    }
    obj->min++;
    obj->size++;
}

void minStackPop(MinStack* obj) {
  --obj->top;
    --obj->size;
    --obj->min;
    //what if popped was a minimum?
    //This is why make min[] just as big as data[] and add min for every corresponding index
    if(obj->size == 0)
    {
        obj->top = -1;
        *(obj->min) = INT_MAX;
    }
}

int minStackTop(MinStack* obj) {
  return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return *(obj->min -1);//fine tuning
}

void minStackFree(MinStack* obj) {
    
}
void main()
{
    MinStack* obj = minStackCreate(4);
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);
    printf("Min number in that stack is %d \n", minStackGetMin(obj));
    minStackPop(obj);//error: should give 2
    printf("Top of the stack is: %d\n", minStackTop(obj));
    printf("Min number in that stack is %d \n ", minStackGetMin(obj));
    minStackFree(obj);
}