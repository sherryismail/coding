#include <iostream>
#include <string>
using namespace std;
//------------example 1---------------
/* How can you make sure a C++ function can be called as e.g. void foo(int, int) but not as any other type like void foo(long, long)?
 */
void foo(int a, int b) {
    cout << "Accepted func type"<<endl;
}
//Function template
/*
template <typename T>
T functionName(T x, T y, ...) {
    // code
}
*/
template <typename T1, typename T2> void foo(T1 a, T2 b) = delete;
//T1 and T2 are template argument that accept diff data types, typename is a keyword

//------------example 2---------------
//we want a different behaviour of a function/class template for a particular data type
template <class T> 
T max (T &a, T &b) 
{
    cout << "template generic ";  
    return (a > b)? a : b; 
} 
template <> 
int max <int>(int &a, int &b) //add <int> in call and defn to be picked
{ 
    cout << "template specialisation "; 
    return (a > b)? a : b; 
} 
//------------example 3---------------
template<class T, class U> //T and U are arg and a data type
class A  { 
    T x; 
    U y; 
    static int count; 
    //now create A<int,int> A <char,int>
}; 
//------------example 4---------------
template <class T> 
class Test 
{ 
private: 
    T val; 
public: 
    static int count; 
    Test()  {   count++;   } 
}; 
//Defining a Class Member Outside the Class Template
template<class T> 
int Test<T>::count = 0; 
  

int main()
{
    foo(2,3);

    int x=10, y=20;
    cout << max<int>(x,y)<<endl;

    A<char, char> a; 
    A<int, int> b; 
    A<int, char> c;
    cout << sizeof(a) << endl; //static variable not counted in sizeof()
    cout << sizeof(b) << endl; 
    cout << sizeof(c) << endl << endl; 

    Test<int> p; 
    Test<int> q; 
    Test<double> r; 
    cout << Test<int>::count   << endl; 
    cout << Test<double>::count << endl; 
    return 0;
};

