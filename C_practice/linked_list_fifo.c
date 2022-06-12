#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node * next;
};
struct Node * insert(struct Node *head, int data)
{
    struct Node ** this = &head;
    struct Node * new = (struct Node *) malloc (sizeof(struct Node));
    printf("head=%p,this=%p\t",head,this);
    //the advantage of **Node is that you need nto check the first NULL condition
    while(*this != NULL)
    {
        this = &((*this)->next);
    }
    //printf("head=%p,this=%p, new=%p\n",head,this,new);
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
    struct Node * temp;//free(head) will not work. 
    while((*this)!= NULL)
    {           
        if ( (*this)->data == data)
        {
            if(*this == head)
            {
                temp = head;
                head = head->next;
               free((struct Node *)temp);
            }
            else
            {
                
                temp = *this;
                free((struct Node *)temp);//not working
                prev->next = (*this)->next;
            }
            printf("Found it\n");
            //there may be multiple repeated 'data'
        }
        else
        {
            prev = *this;
            
        }
        this = &((*this)->next);
    }
    return head;
}
void reverse (struct Node ** head)
{
    struct Node * current;
    struct Node * prev, *temp;
    current = *head;
    prev = NULL;

    while(current != NULL)
    {
        //store forward node
        temp = current->next;
        //reverse current pointer, overwrite
        current->next = prev;
        //move one node ahead for prev and cuurent
        prev = current;
        current = temp;
    }
    *head = prev;//edit the head only in the end
    //while-loop exited so current=NULL. Do not assign it to *head

}
int main()
{
    struct Node * head = NULL;

    int T,data;
    printf("Enter number of nodes: ");
    scanf("%d",&T);
    printf("Enter values of nodes: ");
    while(T-->0){
        scanf("%d",&data);
        head=insert(head,data);
    } 
    display(head); 
    printf("Reversing array:\n");
    reverse(&head);
    display(head);

    printf("\nEnter the value to remove: ");
    scanf("%d",&data);
    head = removed(head,data);
    display(head);
    printf(" head=%p",head);//head is intact
    return 0;
}

