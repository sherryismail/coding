#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
}Node ;

void push(Node ** head, int value)
{
    Node *new = malloc(sizeof(Node));
    new->data = value;
    if(*head == NULL)
        new->next = NULL;
    else
        new->next = *head;
    *head = new;
}

void display(Node * head)
{
    while(head !=NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
}

Node * middle(Node *head)
{//tortoise And Hare Approach
    Node * slow = head;
    Node * fast = head->next;
    while(slow->next != NULL && (fast!=NULL && fast->next != NULL))
    {
        slow= slow->next;//half jumps
        fast= fast->next->next;
    }
    return slow;
}

Node * merge(Node * a, Node * b)
{
    Node *merged, *final;
    //merged is equal to temp so in the end we have the top Node.
    final = merged;//its null initially
    //**********************************
    if(a->data <= b->data)
    {
        merged = a;
        a = a->next;
    }else{
        merged = b;
        b= b->next;
    }
    //**********************************
    //needed to initialise properly
   final = merged;
    while (a != NULL && b != NULL)
    {
        
        if (a->data <= b->data)
        {
            merged->next = a;
            a = a->next;
        }
        else
        {
            merged->next = b;
            b = b->next;
        }
        merged = merged->next;
        
    }
    
    // any remaining Node in a or b gets inserted in the temp List
    while (a != NULL)
    {
        merged->next= a;
        a = a->next;
        merged = merged->next;
       
    }
    while (b != NULL)
    {
        merged->next= b;
        b = b->next;
        merged = merged->next;
      
    }
    // return the head of the sorted list
    return final;
}

Node * mergesort(Node * head)
{
    if(head->next == NULL) {
        return head;
    }
   Node * sorted;
   Node * mid = middle(head);
   Node * head2 = mid->next;
   mid->next = NULL; //chop first half of LL
    //recursive
   sorted= merge(mergesort(head), mergesort(head2));
    return sorted;
}

void main ()
{
    printf("Enter nodes: ");
    int count=0, value;
    Node * head = NULL, *sortedHead;
    while(count < 6)
    {
        scanf("%d", &value);
        push(&head, value);
        // insert(value,&head);   //inserting in the list
        count++;
    }
    display(head);
    sortedHead= mergesort(head);
    printf("\nsorted array: ");
    display(sortedHead);
}