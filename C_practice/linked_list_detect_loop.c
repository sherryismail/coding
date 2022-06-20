#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
} Node;

void push(struct Node ** head, int data)
{
    struct Node * new = malloc (sizeof(struct Node));
    new->data = data;
    if (*head == NULL)
        new->next = NULL;
    else //new is where the list terminates
    new->next = *head;
    //new becomes the head
    *head = new;
}

int loopSize(Node *head)
{
    int counter = 0;
    Node *temp = head;
    while (temp->next != head)//IMPORTANT its not "while temp!=head"
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

int detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        /* If slow_p and fast_p meet at some point
           then there is a loop */
        if (slow == fast)
        {
            return loopSize(head);
        }
    }
}

void main()
{
    /*
    On emethod is to have additional flag=0 in struct. Initialise =0;
    Then traverse and set flags =1. 
    If first you encounter flag==1, then repetition happened.
    */
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
 
    if (detectLoop(head))
        printf("Loop found");
    else
        printf("No Loop");
}