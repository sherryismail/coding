#include <iostream>
using namespace std;
struct {
    unsigned int age: 4;
    unsigned char gender: 1;
    unsigned int size: 2;
} child_t;
int main ()
{
    cout << "size " << sizeof(child_t);
    return 0;
}