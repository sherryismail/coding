/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
#include <iostream>
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
    friend class MergeSortLL;
};
class MergeSortLL {
    public:
    MergeSortLL()
    {
       std::cout << "Contructor in an object"<<std::endl;
    }
    void display(Node * head)
    {
        Node * current = head;
        while(current != nullptr)
        {
            std::cout << current->data<< " ";
            current = current->next;
        }
        std::cout <<std::endl;
    }
    Node * insert(Node * head, int data)
    {
        if(head == nullptr){
            head = new Node(data);
            return head;
        }
        Node ** current = &head;
        while((*current)->next != nullptr)
        {
            current = &((*current)->next);
        }
        (*current)->next = new Node(data);
        return head;
    }
    int length(Node * head)
    {
        int counter = 0;
        Node * current = head;
        while (current != nullptr)
        {
            current = current->next;
            counter++;
        }
        return counter;
    }
    /*Use tortoise and hare approach
     Split the nodes of the given list into front and back halves,
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    */
    void FrontBackSplit(Node ** head, Node ** a, Node ** b){
        Node * fast = (*head)->next, * slow = *head;
        while (fast != nullptr)
        {
            fast = fast->next;
            if(fast!= nullptr)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        //slow is just before the mid of the array, split here
        *a = *head;
        *b = slow->next;
        slow->next = nullptr;//terminate front half of linked list
    }
    Node * sorted_merge(Node *a, Node * b)
    {//IMPORTANT
        /* Base cases */
        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);
        Node* result = NULL;
        /* Pick either a or b, and recur */
        if (a->data <= b->data) {
            result = a;
            result->next = sorted_merge(a->next, b);
        }
        else {
            result = b;
            result->next = sorted_merge(a, b->next);
        }
        return (result);
    }

    void merge_sort(Node ** head)
    {
        //base case 
        if(*head == nullptr || (*head)->next == nullptr)
            return;
        //else recursive case
        Node * a;
        Node * b;
        //find midpoint and split the linked list into two
        FrontBackSplit(head, &a, &b);
        merge_sort(&a);//call recursive
        merge_sort(&b);
        *head = sorted_merge(a,b);//merge the organised LLs into one
    }
};
int main(void)
{
    Node * head = nullptr;
    MergeSortLL mylist;
    head = mylist.insert(head,1);
    head = mylist.insert(head,5);
    head = mylist.insert(head,3);
    head = mylist.insert(head,7);
    head = mylist.insert(head,4);
    head = mylist.insert(head,5);
    head = mylist.insert(head,1);
    head = mylist.insert(head,2);
    mylist.display(head);
    std::cout << "Merge sort on Linked List gives:"<<std::endl;
    mylist.merge_sort(&head);
    mylist.display(head);

}

 