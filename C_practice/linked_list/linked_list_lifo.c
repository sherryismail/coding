//stack push pop implementation
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void push(struct Node ** head, int data)
{
    struct Node * new = malloc (sizeof(struct Node));
    printf("*head=%p,new=%p\t",*head,new);
    new->data = data;
    if (*head == NULL)
        new->next = NULL;
    else //new is where the list terminates
    new->next = *head;
    //new becomes the head
    *head = new;
}

void pop(struct Node ** head)
{
    printf("\npopping=%d", (*head)->data);
    *head=(*head)->next;
}
void display(struct Node * head)
{
    struct Node * local = head;//copy retains head value 
    printf("Your list is: "); 
    while(local != NULL)
    {
        printf("%d->", local->data);
        local= local->next;
    }
}
void removed(struct Node ** head, int data)
{
    struct Node ** this = head;
    struct Node * prev = *head;
    struct Node * temp;
    while((*this)!= NULL)//does not satisfy end of the list
    {
        if ( (*this)->data == data)
        {
             if(this == head)
            {
                temp = *head;
                *head=(*head)->next; //not head=&() because you are not advancing pointer, you get rid of the head
               //free((struct Node *)*head);
                this = head;
                //prev = *head;
            }
            else
            {
                prev->next = (*this)->next;
                //prev needs no upddating
                this = &((*this)->next);
                //free((struct Node *)(*this));
            }
            printf("Found it\n");
        }
        else
        {
            prev = *this;
            this = &((*this)->next);
        }
    }
}

void insert(struct Node ** head, int data, int position)
{
    struct Node ** this = head;
    struct Node * temp = NULL;
    int i=0;
    struct Node * new = malloc(sizeof(struct Node));
    new->data = data;
    while((*this)!= NULL)
    {
        if(i==position)
        {
            temp =  (*this)->next;
            (*this)->next = new;
            new->next = temp;
            printf("Inserted\n");
        }
        this = &(*this)->next;
        i++;
    }
}
int main()
{
    struct Node * head = NULL;

    int T,data;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&data);
        push(&head,data);
    } 
   // display(head); 
   // printf("\nEnter the value to remove: ");
   // scanf("%d",&data);
    //removed(&head,data);
   // display(head);
   // printf(" head=%p",head);//head is intact
    // pop(&head);
    //printf("\tstack top=%u",head->data);//head is intact
    insert(&head, 100,2);
    display(head);
    return 0;
}