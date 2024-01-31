#include <queue>
#include <iostream>
using namespace std;
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
        
    }
    
    int pop() { //reverse the sequence of elements
        if (empty())
            return -100;
        int s = q1.size();
        while (s > 1)//size-1 times
        {
            q2.push(q1.front());
            q1.pop();
            s--;
        }
        int val = q1.front();
        q1.pop(); //now its empty
        swap(q1,q2);
        return val;
    }
    
    int top() {
        if (empty())
            return -100;
        int s = q1.size();
        while (s > 1)//size-1 times
        {
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q2.push(q1.front());
        q1.pop(); //now its empty
        swap(q1,q2);
        return val;        
    }
    
    bool empty() {
        return q1.empty();
        
    }
};
int main()
{
    MyStack obj = MyStack();
    obj.push(1);
    obj.push(2);
    obj.push(3);
    cout << "top of stack is "<<obj.pop()<<endl;
    obj.push(4);
    cout << "Next top of stack is "<<obj.pop()<<endl;
    return 0;
}
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */