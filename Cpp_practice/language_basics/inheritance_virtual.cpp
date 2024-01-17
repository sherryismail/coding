#include <iostream>
using namespace std;
class Base {
    virtual void method() {std::cout << "from Base";}
public:
    virtual ~Base() {method();} //destructor should be virtual if you use 'delete' next
    void baseMethod() {method();}
};

class A : public Base {
    void method() {std::cout << "from derived";}
public:
    ~A() {method();}
};

int main(void) {
    cout << "first line: ";
    Base* base = new A;//from A
    cout << endl << "second line: ";
    base->baseMethod();
    cout << endl << "begin delete: ";
    delete base; /* *The important thing to note here is the order of destruction of classes and how Base’s method reverts back to its own implementation once A has been destroyed
    The first to be constructed is the last to be destructed.*/
    return 0;
}
