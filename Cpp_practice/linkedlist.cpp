#include <iostream>
#include <cstddef>
using namespace std;	
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
    Node* insert(Node *head,int data) {
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
    void remove(Node * head, int val)
    {
        Node ** prev = &head;
        Node * entry = head;
        while (entry != NULL)
        {
            if (entry->data == val)
            {
                //forget this.entry and point to next
                *prev = entry->next;
                cout << "Found "<< val << " to remove "<< endl;
            }
            //like prev = entry
            prev = &(entry->next);
            entry= entry->next;
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
};
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
    mylist.display(head);
    mylist.remove(head, 2);
	mylist.display(head);
		
}