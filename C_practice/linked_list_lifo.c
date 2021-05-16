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
    //new is where the list terminates
    new->next = *head;
    //new becomes the head
    *head = new;
    printf("head=%p\t",*head);
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
void removed(struct Node * head, int data)
{
    struct Node ** this = &head;
    struct Node * prev = head;
    while((*this)!= NULL)
    {
        if ( (*this)->data == data)
        {
            prev->next = (*this)->next;
            free((struct Node *)(this));
            printf("Found it\n");
        }
        this = &((*this)->next);
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
    display(head); 
    printf("\nEnter the value to remove: ");
    scanf("%d",&data);
    removed(head,data);
    display(head);
    printf(" head=%p",head);//head is intact
    return 0;
}