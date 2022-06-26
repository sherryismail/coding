#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    false=0,
    true=1,
} bool;

#define SIZE 3 //because test values are 1,2,3
typedef struct Node {
    int value;
    struct Node * next;
} Node;

typedef struct MyHashSet {
    int totalsize;
    struct Node ** buckets;
} MyHashSet;

int hashCode(MyHashSet * obj, int key) {
   return key % (obj->totalsize);
}
MyHashSet* myHashSetCreate() {
    MyHashSet * set = malloc(sizeof(MyHashSet));
    set->totalsize= SIZE;
    //is it necessary to create entire table now or malloc() when add is called?
    //yes create an array[] now and later collision happens so put linked list
    set->buckets = (Node **) malloc(sizeof(Node) * (set->totalsize));
    //initialise buckets to null
    for (int i=0; i < set->totalsize; i++)
    {
        set->buckets[i] = NULL;//[0=NULL][1=NULL]....[N=null] buckets
    }
    return set;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int i=0;
    int index = hashCode(obj, key);
    if(obj->buckets[index] == NULL)
        return false;
    Node * current = obj->buckets[index];
    while(current != NULL)
    {
        if(current->value == key)
            return true;
        current= current->next;
    }
    return false;
  
}

int myHashSetAdd(MyHashSet* set, int key) {
    int index = hashCode(set,key);
    if(set->buckets[index]==NULL)
    {
        set->buckets[index] = malloc(sizeof(Node));
        set->buckets[index]->value = key;
        set->buckets[index]->next = NULL;
        return 0;
    }
    //if collision occurs, create linked list at this point
    //if(myHashSetContains(set,key))
    {
        //  return -1 ;
        // OR create a Linked List at this index
        Node * current = set->buckets[index];
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = malloc(sizeof(Node));
        current->value = key;
        current->next->next = NULL; 
        return 2;
    }
  
}

void myHashSetRemove(MyHashSet* set, int key) {
    int index = hashCode(set,key);
    if(myHashSetContains(set, key) == false)
        return;
    //if start of LL
    Node * current = set->buckets[index];
    if(current->value == key)
    {
        Node * start = current->next;      
        set->buckets[index] = start;
        printf("Removed %d at index %d\n", key, index);
        free(current);
        return;
    }
    Node * prev = current;
    while(current->value != key)
    {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
   free(current);   
}

void myHashSetFree(MyHashSet* obj) {
    
}
//https://leetcode.com/explore/learn/card/hash-table/182/practical-applications/1139/discuss/2166950/C-solution
void main()
{
    MyHashSet* obj = myHashSetCreate();
    bool result;
    int res;
    int num = 1;
    printf("Adding %d\n", num);
    myHashSetAdd(obj, num);// set = [1]
    num = 2;
    printf("Adding %d\n", num);
    myHashSetAdd(obj, num); // set = [1, 2]

    num = 3;
    result= myHashSetContains(obj,num);
    if (result == true)
        printf("%d is present\n", num);
    else
        printf("%d was not found\n", num);
    
    num = 5;
    res = myHashSetAdd(obj, num);//set = [1]
    if(res == 0)
        printf("Adding %d\n", num);
    else if(res == -1)
        printf("%d is already present. Not adding again\n", num);
    else if (res == 2)
         printf("%d is added to the linked list\n", num);

    num=5;
    myHashSetRemove(obj, num);
    result = myHashSetContains(obj, num);// return False, (already removed)
    if (result == true)
        printf("%d is present\n", num);
    else
        printf("%d was not found\n", num);
    
    myHashSetFree(obj);

}