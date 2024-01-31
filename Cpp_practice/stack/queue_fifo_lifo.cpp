#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
#define SIZE_LIMIT  100
class Queue{
    public:
    int head, tail, MaxSize;
    bool full;
    int lifo[SIZE_LIMIT];//because cant initialise int array with a non-const dimension that can't be calculated at compile time 
    Queue(int size) {
        head = 0, tail = 0;
        MaxSize = size; //circular buffer check
        full = false;
    }
    ~Queue() {}
    bool isempty()
    {
        if (head == tail)//dont check if head == tail. This done at de-queuing stage
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (tail == (head+1 % MaxSize) || full)
            return true;
        else
            return false;

    }
    bool enqueue(int val)
    {
        if (isFull())
            return false;
        else{
            lifo[head] = val;
            if ((head+1)%MaxSize == tail)//check ahead
                full = true;
            else
                head = (head+1) % MaxSize;
            return true;
        }
    }
    bool dequeue(int * val)
    {
        if(isempty())
            return false;
        *val = lifo[tail];
        tail = (tail+1) % MaxSize;
        full = false;
        if(head == tail)//check if Dequeue now lead to empty
        {
           head = tail = 0;
        } 
        return true;
    }
    int getQueueSize()
    {
        return abs(abs(head) - abs(tail));
    }
};
class Stack {
    public:
    int head, tail, MaxSize;
    bool full;
    int fifo[SIZE_LIMIT];//becuase cant initialise int array with a non-const dimension that can't be calculated at compile time 
    Stack(int size) {
        head = 0, tail = 0;
        MaxSize = size; //circular buffer check
        full = false;
    }
    ~Stack() {}
    bool isempty()
    {
        if(head == 0)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (head == MaxSize)
            return true;
        else
            return false;
    }
    bool push(int val)
    {
        if (isFull())
            return false;
        else
        {
            fifo[head] = val;
            head++;
        }
        return true;
    }
    bool pop(int * val)
    {
        if (isempty())
            return false;
        else
        {
            head--;//important to decrement before fetching
            *val = fifo[head];
            return true;
        }
    }

};
int main (void)
{
    class Queue q(3);
    bool ret;
    int i=1, retval=0;
    while (i <= 5)
    {
        ret = q.enqueue(i);
        if (ret == true)
            cout << "Val=" << i <<" accepted. h="<<q.head<<",t="<<q.tail<< endl;
        else
             cout << "Val=" << i <<" Not accepted. h="<<q.head<<",t="<<q.tail<< endl;
        i++;
    }
    cout << "d.isFull()? " << q.isFull() << endl;
    q.dequeue(&retval);
    cout << "de-queued val= " << retval <<endl;
    ret = q.enqueue(i);
    if (ret == true)
            cout << "Val=" << i <<" accepted. h="<<q.head<<",t="<<q.tail<< endl;
        else
            cout << "Val=" << i <<" Not accepted. h="<<q.head<<",t="<<q.tail<< endl;
    q.dequeue(&retval);
    cout << "de-queued val= " << retval <<endl;

    class Stack s(3);
    i=1;
    while (i <= 5)
    {
        ret = s.push(i);
        if (ret == true)
            cout << "Val=" << i <<" accepted. h="<<s.head<< endl;
        else
             cout << "Val=" << i <<" Not accepted. h="<<s.head<< endl;
        i++;
    }
    cout << "stack.isFull()? " << s.isFull() << endl;
    retval = 0;
    s.pop(&retval);
    cout << "stack pop val= " << retval <<endl;
    ret = s.push(i);
    if (ret == true)
            cout << "Val=" << i <<" accepted. h="<<s.head<< endl;
        else
            cout << "Val=" << i <<" Not accepted. h="<<s.head<< endl;
    s.pop(&retval);
    cout << "stack pop val= " << retval <<endl;
    return 0;
}