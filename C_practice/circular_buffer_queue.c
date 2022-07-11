#include <stdio.h>
#include <stdlib.h>

/**
 * @brief
The circular queue is a linear data structure in which the operations are performed 
based on FIFO (First In First Out) principle and the last position is connected 
back to the first position to make a circle. It is also called "Ring Buffer".
One of the benefits of the circular queue is that we can make use of the 
spaces in front of the queue. In a normal queue, once the queue becomes 
full, we cannot insert the next element even if there is a space in front 
of the queue.
 * 
 */
typedef struct {
    int * data;
    int size;
    int head;
    int tail;
} MyCircularQueue;
typedef enum {
    false, true,
} bool;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue * obj = malloc(sizeof(MyCircularQueue));
    obj->data = malloc(sizeof(int) * k);
    obj->size = k;
    obj->head = -1;
    obj->tail = -1;//tricky, I initialised as 0
    return obj;
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->head == -1)//tricky
        return true;//dont check if head == tail. This done at de-queuing stage
    else
        return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
 if(obj->head == (obj->tail+1) % obj->size)
        return true;
    else
        return false;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))
        return false;//queue is already full
    if(myCircularQueueIsEmpty(obj))
        obj->head = 0;//tricky important
    obj->tail = (obj->tail + 1) % obj->size;
    obj->data[obj->tail] = value;
    return true;
  
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    
    if(myCircularQueueIsEmpty(obj))//queue is empty
        return false;
  obj->head = (++obj->head) % obj->size;
    if(obj->head == obj->tail)//check if Dequeue now lead to empty
    {
        obj->head = -1; //tricky
        obj->tail = -1;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->data[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
  if(myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->data[obj->tail];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4

failed test case:
CreateQueue(1)
enQueue(6)
Dequeue()
FindRear()
FindFront()
*/
int main()
{
    //Enter size of queue
    MyCircularQueue* obj = myCircularQueueCreate(1);
    int num = 1;
    if(myCircularQueueEnQueue(obj, num) == true)
        printf("%d is added\n", num);
    else printf("%d not added. Queue full\n", num);

    printf("Front of the queue is now %d\n", myCircularQueueFront(obj));
    printf("End of the queue is now %d\n", myCircularQueueRear(obj));
    num = 2;
    if(myCircularQueueEnQueue(obj, num) == true)
        printf("%d is added\n", num);
    else printf("%d not added. Queue full\n", num);
    num =3;
    if(myCircularQueueEnQueue(obj, num) == true)
        printf("%d is added\n", num);
    else printf("%d not added. Queue full\n", num);
     num =4;
    if(myCircularQueueEnQueue(obj, num) == true)
        printf("%d is added\n", num);
    else printf("%d not added. Queue full\n", num);

    if(myCircularQueueDeQueue(obj) == true)
        printf("Dequeuing successful. Top element out\n", num);
    else printf("Dequeuing failed. Queue is empty\n", num);
    
    printf("Front of the queue is now %d\n", myCircularQueueFront(obj));
    printf("End of the queue is now %d\n", myCircularQueueRear(obj));
    myCircularQueueIsEmpty(obj);
    myCircularQueueIsFull(obj);
    myCircularQueueFree(obj);
}