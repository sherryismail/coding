#include <iostream>
#include <cstddef>
#include <string.h>
using namespace std;
//remove nth node from the front and nth node from the end of the list	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:
    Node* fifo_insert(Node *head,int data) {
        Node** current = &head; //not copying it for backup but use a **ptr that can be incremented
        while(*current != NULL) 
        {
            //like current = entry->next
            current = &((*current)->next);
        }
        //get to the last LL member *current == NULL
        //*current can point to a new LL member instead
        *current = new Node(data);
        return head;
    } 
    void RemoveNthFromStart(Node ** head, int val) //if Node * head is passed then error if Node_to_remove = first node
    {
        Node * prev = *head;
        Node ** current = head, * temp = nullptr;
        while (*current != nullptr)
        {
            if ((*current)->data == val)
            {
                cout << "Found "<< val << " to remove "<< endl;
                if(current == head)//special case: node to be deleted is the first one
                {
                    temp = *head;
                    *head = (*head)->next;//head = &(*head)->next  is wrong!!
                    temp->next = nullptr;//disconnect old head node
                    current = head;
                    prev = *current;
                }
                else{
                    //node found somewhere in the list. Or the end.
                    temp = *current;
                    prev->next = (*current)->next;
                    if( *current == nullptr)//no more processing needed, exit
                        return;//this avoids error if last node of the list is to be removed
                    current= &(*current)->next;//Important to put this here and not at while()'s generic condition
                    delete(temp);
                }
            }
            else //match not found. traverse to the next node
            {
                prev = *current;
                current= &((*current)->next);
            }
            //no typical current=current->next here
        }
    }
    void display(Node *head)
    {
        Node *start=head;
        while(start)
        {
            cout<<start->data<<" ";
            start=start->next;
        }
    }
    int length_recursive(Node * head)
    {
        Node * current = head;
        //base case
        if(current == nullptr)
            return 0;
        else//recursive
            return 1+ length_recursive(current->next);
    }
    // /https://www.linkedin.com/pulse/20141120061048-6976444-ace-the-coding-interview-every-time/
/**
 * @brief 
 * A Singly-linked list. time complexity is important but not space complexity
 * (So recursive solution may be ok also try iterative)
 * 
 */
//iterative method
    Node * RemoveNthFromEnd1(Node * head, int position)
    {
        //position from end is Length - position form the start
        Node * current = head;
        Node * prev = nullptr;
        
        int len = length_recursive(head);
        if(len < position) //out of range
            return head;
        if (len == position){//remove start of the list
            return head->next;
            /*why doesnt this work --> head = head->next; 
            return; and with void function()
             */
        }
        for (int i=0; i < len- position; i++)
        {
            prev = current;
            current = current->next;
        }
        Node * temp = current;
        prev->next = current->next;
        delete(current);
        return head;
    }
    //it can be void but you can also return the isolated node
    void RemoveNthFromEndr(Node ** current, int * counter, int position, Node * prev)
    {
        //base case
        if(current == nullptr)
            return ;

        if (*counter == position){//just a step before position. now how to deal with post=1
            cout << "Found "<< (*current)->data << " to remove "<< endl;
            if(prev == nullptr)
            {//this is the first element to remove, prev was initialised to null
                *current = (*current)->next;
            }
            else
                prev->next = (*current)->next;
            return;  
        }
        //recursive case
        *counter = *counter + 1;
        prev = *current;
        current = & (*current)->next;
        RemoveNthFromEndr(current, counter, position, prev);
        
    }
    //recursive method
    void  RemoveNthFromEnd2(Node ** head, int position)
    {
        /* if RemoveNthFromEnd2(head) is passed but not RemoveNthFromEnd2(&head),
         * then error would happen, if position= head of the node. 
         Outside display(head) will show head not removed form the list
         */
        int total = length_recursive(*head);
        int count = 0;
        Node * prev = nullptr;
        //pass pointer to the head so that if position=length, then head node is removed
        RemoveNthFromEndr(head,&count, position, prev);
    }
    Node * fifo_remove(Node ** head, int index)
    {
        Node ** current = head;
        Node * prev = *head;
        int i=1;
        while(i < index)
        {
            prev = *current;
            current = &(*current)->next;
            i++;
        }
        prev->next = (*current)->next;
        return *head;
    }
};


int main(int argc, char * argv[])
{
    // If /n is passed to the .exe, display numbered listing
    // of environment variables.
    if ( (argc >1) || strcmp(argv[1], "\n" ) == 0 )
         cout << "This program will remove nth node from the **END**. \nEnter total number of Nodes to enter: ";
    else
        cout << "This program will remove nth node from the **START**.\nEnter total number of Nodes to enter: ";
	Node* head=NULL;
  	Solution mylist;
    int T,data, remove;
    cin>>T;
    cout << "Enter all the node->data: ";
    while(T-->0){
        cin>>data;
        head=mylist.fifo_insert(head,data);
    }	
    
    cout << "Enter the data value to remove the corresponding node from the fifo: ";
    cin>>remove;
    mylist.RemoveNthFromStart(&head, remove);//if remove(head, remove) then error happens incase first node is to be removed
	mylist.display(head);
    cout <<std::endl<< "Length of the list: "<<mylist.length_recursive(head)<<endl;

    // cout << "To remove nth node from the end (iterative), Enter n: ";
    // cin>>remove;
    // head = mylist.RemoveNthFromEnd1(head,remove);
    // mylist.display(head);
    
    // cout <<endl<< "To remove nth node from the end (recursively), Enter n: ";
    // cin>>remove;
    // mylist.RemoveNthFromEnd2(&head,mylist.length_recursive(head) - remove);
    // mylist.display(head);

    cout <<endl<< "To remove nth node from the start, Enter index: ";
    cin>>remove;
    head=mylist.fifo_remove(&head,remove);
    mylist.display(head);
	
}