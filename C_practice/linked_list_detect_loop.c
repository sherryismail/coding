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
        /*time comeplxity: O(N)
        if no cycle, then fast pointer takes M/2 times to reach the end. if N=size
        if cycles=yes, fast pointer needs M times to catch up with the slow pointer, M=size of loop
        M<=N, so O(M+N) ===> O(N)
        */
    }
}
Node * detect_start_of_loop(Node * head)
{
     struct Node * slow = head, *fast = head;
    struct Node * result = NULL;
    int i=0,j=0;
    while(slow && fast && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            result = slow;//stop at this
            break;//Floyds algo will stop it at a special point
        }
    }
   i=0;
    while(head != result && result)//2nd check if result==NULL for single linked list Node
    {
        result = result->next;
        head = head->next;
        i++;
    }
    printf("%d is the start of the loop",i);
    //if any NULL object that means cycle does not exist
    return result;
    //test case [1]
    //test case [3,2,0,-4, 2, 0, -4]
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
    push(&head, 8);
 
    /* Create a loop for testing */
    struct Node * turn_back = head->next;
    head->next->next->next->next->next = head->next;
 
    if (detectLoop(head))
        printf("Loop found");
    else
        printf("No Loop");
    detect_start_of_loop(head);
}