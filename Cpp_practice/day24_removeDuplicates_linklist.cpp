#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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

          Node* removeDuplicates(Node *head)
          {
            //Write your code here
            Node ** current = &head;
            Node * prev = head;
            int curr_data, prev_data, i=0;
            // advance by one step otherwise prev == current always true 
            current = & (*current)->next;
            while ((*current) != NULL)
            {   
                curr_data = (*current)->data;
                prev_data = prev->data;
                if (curr_data == prev_data)
                {
                    //break the chain
                    prev->next = (*current)->next;
                    *current = prev->next;
                }
                else 
                {
                    prev = prev->next;
                    current = & (*current)->next;
                }
                i++;
            }
            return head;            
          }

          Node* insert(Node *head,int data)
          {
               Node* p=new Node(data);
               if(head==NULL){
                   head=p;  

               }
               else if(head->next==NULL){
                   head->next=p;

               }
               else{
                   Node *start=head;
                   while(start->next!=NULL){
                       start=start->next;
                   }
                   start->next=p;   

               }
                    return head;
                
            
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
    head=mylist.removeDuplicates(head);

	mylist.display(head);
		
}
/*
Constraints:
The data elements of the linked list argument will always be in non-decreasing order. 
*/