#include <iostream>
#include <cstddef>
#include <string.h>
using namespace std;
class Node{
    public:
    int data;
    class Node * next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node * fifo_insert(class Node * head, int data)
{
    class Node **current = &head;
    while (*current != NULL)//first element
    {
        current = &((*current)->next);
    }
    *current = new Node(data);
    return head;
}
void fifo_remove(class Node ** head, int x)
{
    Node ** current = head;
    Node * prev = *head;
    Node * temp;
    while (*current != NULL)
    {
        if((*current)->data == x)
        {
            if (current == head)
            {
                temp = *current;
                *head = (*head)->next;
                current = head;
                prev = *current;
            }
            else{
                prev->next = (*current)->next;
                temp = *current;
                delete(temp);
                current = &(*current)->next; 
            }
           
        }
        else
        {
            prev = *current;
            current = &(*current)->next; 
        }
        
    }
}

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
        head=mylist.insert(head,data);
    }	
    
    cout << "Enter the data value to remove the corresponding node from the fifo: ";
    cin>>remove;
    mylist.RemoveNthFromStart(&head, remove);//if remove(head, remove) then error happens incase first node is to be removed
	mylist.display(head);
    cout <<std::endl<< "Length of the list: "<<mylist.length_recursive(head)<<endl;

    cout << "To remove nth node from the end (iterative), Enter n: ";
    cin>>remove;
    head = mylist.RemoveNthFromEnd1(head,remove);
    mylist.display(head);
    
    cout <<endl<< "To remove nth node from the end (recursively), Enter n: ";
    cin>>remove;
    mylist.RemoveNthFromEnd2(&head,mylist.length_recursive(head) - remove);
    mylist.display(head);
	
}