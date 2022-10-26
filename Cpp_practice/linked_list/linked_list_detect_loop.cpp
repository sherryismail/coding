#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;

//method 1: Floyd algorithm: find time complexity
//method 2: Hashmap
//method 3: modify LL structure by putting a flag

//https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/

class Node
{
    public:
    int data;
    int flag;
    Node * next;
    Node(int x)
    {
        data=x;
        next=nullptr;
        flag=0;
    }
    friend class DetectLoopInAList;
};
class DetectLoopInAList
{
    public:
    DetectLoopInAList()
    {
       std::cout << "Contructor in an object"<<endl;
    }
    //insert FIFO
    Node * insert (Node * head, int data)
    {
        Node ** current = &head; //not copying it for backup but use a **ptr that can be incremented
        while( *current != nullptr)
        {
            current = &((*current)->next);
        }
        //get to the last LL member *current == NULL
        //*current can point to a new LL member instead
        *current = new Node(data); 
        return head;
    }

    void display(Node * head)
    {
        Node * current = head;
        while(current != nullptr)
        {
            cout << current->data<< " ";
            current = current->next;
        }
        cout <<endl;
    }

    void methodFloyd(Node * head)
    {
        Node * fast, *slow;
        fast = slow = head;
        while (fast && slow && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            /* If slow_p and fast_p meet at some point
           then there is a loop */
            if(fast == slow){
                cout << "Loop detected at "<< fast->data;
                return;
            }
        }
        cout << "No loop detected";
        /*time complexity: O(N)
        if no cycle, then fast pointer takes M/2 times to reach the end. if N=size
        if cycles=yes, fast pointer needs M times to catch up with the slow pointer, M=size of loop
        M<=N, so O(M+N) ===> O(N)
        */
    }
    Node * StartOfTheLoop(Node * head)
    {
        unordered_set<Node *> LLdatabase;
        Node * current = head;
        while(current != nullptr)//what to do if here is a loop and this never hits nullptr?
        {
            if(LLdatabase.find(current) == LLdatabase.end())
                LLdatabase.insert(current);
            else
                return current;
            current = current->next;
        }
        return nullptr;
         /*time complexity: O(N)*/
    }
    //return true if a loop is detected otherwise return false
    bool FindLoopStart (Node * head)
    {
        Node * current = head;
        while (current!= nullptr)
        {
            if(current->flag==1)
                return true;
            current->flag++;
            current=current->next;
        }
        return false;
    }

    /* Function to remove duplicates from unsorted linked list */
    void removeDuplicates(struct Node* start)
    {
    // Hash to store seen values
    unordered_set<int> seen;

    /* Pick elements one by one */
    struct Node* curr = start;
    struct Node* prev = nullptr;
    while (curr != nullptr) {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete (curr);
        }
        else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }

    while (curr != nullptr)
    {
        if(seen.find(curr->data) == seen.end())
        {
            seen.insert(curr->data);
            prev = curr;
        }
        else{
            prev->next = curr->next;
            delete(curr);
        }
        curr=prev->next;
    }
    }

};
int main (void)
{
    Node * head = nullptr;
    DetectLoopInAList mylist;
    head = mylist.insert(head,1);
    head = mylist.insert(head,2);
    head = mylist.insert(head,3);
    head = mylist.insert(head,3);
    head = mylist.insert(head,4);
    head = mylist.insert(head,5);
    head = mylist.insert(head,1);
    mylist.display(head);

    cout <<"After removing duplicates";
    mylist.removeDuplicates(head);

    cout <<endl;
    mylist.display(head);

    /* Create a loop for testing */
    struct Node * turn_back = head->next;
    head->next->next->next->next->next = turn_back;
    mylist.methodFloyd(head);

    Node * result = mylist.StartOfTheLoop(head);
    cout << endl<< "Start of the loop at "<< result->data <<endl;

    bool isitALoop = mylist.FindLoopStart(head);
    if (isitALoop == true)
        cout << "Yes there is a loop in LL";
    else
        cout << "No loop in the LL";

    return 0;
}
    