
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct Node{
    int val;
    struct Node * next;
}Node;

typedef struct {
    int count;//mistake: Incase  AddAtIndex means AddTail, count can be used outside while(!=)
    struct Node * head;
} MyLinkedList;
MyLinkedList * myLinkedListCreate();
void myLinkedListaddAtHead(MyLinkedList * obj, int);
void myLinkedListaddAtTail(MyLinkedList * obj, int);
void myLinkedListAddAtIndex(MyLinkedList * obj, int, int); 
int myLinkedListGet(MyLinkedList * obj,int ); 
void myLinkedListDeleteAtIndex(MyLinkedList * obj,int);



MyLinkedList* myLinkedListCreate() {
    MyLinkedList * list = (MyLinkedList *) malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->count = 0;
    return list;   
}

void display(MyLinkedList * obj)
{
    struct Node * local = obj->head;//copy retains head value 
    printf("Your list is: ");
    while(local != NULL)
    {
        printf("%d->", local->val);
        local= local->next;
    }
    printf("\n");
}
int myLinkedListGet(MyLinkedList* obj, int index) {
    int i = 0;
    // if(index == 0 && obj->head)
    // {
    //     return obj->head->val;
    // }
    if(index > obj->count)
        return -1;
    Node * current = obj->head;
    while(current!= NULL){
        if(i==index)
        {
            return current->val;
        }
        current = current->next;
        i++;
    }
  return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    
    Node * new = malloc(sizeof(Node));
    new->val = val;
    if(obj->head ==NULL)
    {
        obj->head = new;
        new->next = NULL;
    }
    else
    {
        Node * temp = obj->head;
        new->next = temp;//move head to 2nd position
        obj->head = new;//new head mistake
    }  
    obj->count++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if(!obj->head){//mistake
        myLinkedListAddAtHead(obj,val);
        return;
    }
    Node * current = obj->head;
    while(current->next != NULL)//get to the last node
        current = current->next;
    Node * newNode  = malloc(sizeof(Node));
    current->next = newNode;
    newNode->val = val;
    newNode->next = NULL;//terminate LL  
    obj->count++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    
    if(index == 0)
    {
        myLinkedListAddAtHead(obj,val);
        return;
    }
    Node * current = obj->head;
    Node * prev = NULL;
    int i=0;
    //enter somewhere in between
    while(current != NULL)
    {
        if(i== index)
        {
            Node * temp = current;
            prev->next = (Node *)malloc(sizeof(Node));//create new
            //my mistake was to put curent->next = malloc()
            current = prev->next;//move to this new Node
            current->val = val;
            current->next = temp;
            display(obj);
            obj->count++;
            return;
            
        }
        else{
            prev = current;
            current = current->next;
            i++;
        }
    }
    if(i== obj->count)
        myLinkedListAddAtTail(obj,val);

}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    //if index == 0, update head;
    if(index == 0)
    {
        if(obj->head->next == NULL)
        {
            obj->head = NULL;
            obj->count=0;
            return;//empty LL
        }
        else
        {
            Node * temp = obj->head;
            Node * del = temp;
            obj->head = temp->next;
            free(del);
            obj->count--;
            return ;
        }
    }
    Node * current = obj->head;
    Node * prev = NULL;
    int i=0;
    while(current != NULL)//my mistake was current->next != NULL
    {
        if(i==index)
        {
            // Node * temp = current;//free(current) works fine
            prev->next  = current->next;
            free(current);
            obj->count--;
            return;
            
        }else
        {
            prev = current;
            current = current->next;
            i++;
        }
    }
  
}

void myLinkedListFree(MyLinkedList* obj){
    int i=0;
    Node * current = obj->head;
    Node * temp = obj->head;
    for(i=0; i <obj->count;i++)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(obj);
}

void testcase1()
{
       /* Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]*/

MyLinkedList * obj = myLinkedListCreate();
myLinkedListAddAtHead(obj, 1);
display(obj);
myLinkedListAddAtTail(obj, 3);
display(obj);
myLinkedListAddAtIndex(obj, 1, 2);    // linked list becomes 1->2->3
display(obj);
printf("%d\n",myLinkedListGet(obj,1));              // return 2
myLinkedListDeleteAtIndex(obj,1);    // now the linked list is 1->3
display(obj);
printf("%d\n", myLinkedListGet(obj,1));              // return 3
}
void testcase2()
{
    /*["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
[[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
Expected: [null,null,null,null,null,null,null,null,4,null,null,null]
*/
MyLinkedList * obj = myLinkedListCreate();
myLinkedListAddAtHead(obj, 7);
myLinkedListAddAtHead(obj, 2);//2->7
myLinkedListAddAtHead(obj, 1);//1->2->7
myLinkedListAddAtIndex(obj, 3, 0);//1->2->7->0  
display(obj);
myLinkedListDeleteAtIndex(obj,2);//1->2->0  
myLinkedListAddAtHead(obj, 6);//6->1->2->0
myLinkedListAddAtTail(obj, 4);//6->1->2->0->4
printf("%d\n", myLinkedListGet(obj,4)); //expect 4
myLinkedListAddAtHead(obj, 4);//4->6->1->2->0->4
myLinkedListAddAtIndex(obj, 5, 0);  //6->1->2->0->4->0
display(obj);
myLinkedListAddAtHead(obj, 6);//6->6->1->2->0->4->0
}

void testcase3()
{
    MyLinkedList * obj = myLinkedListCreate();
    myLinkedListAddAtTail(obj, 1);
    display(obj);
    printf("%d\n", myLinkedListGet(obj,0)); //expect 1

    obj = myLinkedListCreate();
    myLinkedListAddAtIndex(obj, 1, 0);
    printf("%d\n", myLinkedListGet(obj,0)); //expect -1 CODE ERROR TODO
}

void main()
{
   //testcase1();
    //testcase2();//this test case was not passing because of absence of obj->count.
    //AddAtIndex did not cater the edge case when we add to the tail of linked list
    testcase3();
}