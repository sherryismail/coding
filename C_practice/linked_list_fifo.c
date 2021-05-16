#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node * next;
};
struct Node * insert(struct Node *head, int data)
{
    struct Node ** this = &head;
    struct Node * new = malloc (sizeof(struct Node));
    printf("head=%p,this=%p\t",head,this);
    //the advantage of **Node is that you need nto check the first NULL condition
    while(*this != NULL)
    {
        this = &((*this)->next);
    }
    printf("head=%p,this=%p, new=%p\n",head,this,new);
    //at the end of while(), *this always ends up pointing to 'next' field of last element,hence NULL
    //put location of newest element at this location --> *this
    *this = new; //this = &new; WON'T WORK
    //add new data
    new->data = data;
    new->next = NULL;
    printf("*this=%p,this=%p\n",*this,this); //*this will be same as 
    return head;//head untouched
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
struct Node * removed(struct Node * head, int data)
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
        else
        {
            prev = *this;
        }
        this = &((*this)->next);
    }
    return head;
}
int main()
{
    struct Node * head = NULL;

    int T,data;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&data);
        head=insert(head,data);
    } 
    display(head); 
    printf("\nEnter the value to remove: ");
    scanf("%d",&data);
    head = removed(head,data);
    display(head);
    printf(" head=%p",head);//head is intact
    return 0;
}