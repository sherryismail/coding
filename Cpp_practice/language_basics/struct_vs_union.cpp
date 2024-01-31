#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
using namespace std;
struct child_t {
    unsigned int age: 1;//is it number of bits?
    unsigned char gender: 1;
    unsigned int size: 4;
};

struct uninit_unpacked {
    unsigned int age;
    unsigned char gender;
    unsigned int size;
} uninit_unpacked;

#pragma pack(push, 1)
struct uninit_packed {
    unsigned int age;
    unsigned char gender;
    unsigned int size;
} uninit_packed;
 
int main ()
{
    struct child_t foo;
    cout << "size init " << sizeof(child_t)<<endl; //4
    cout << "size object init " << sizeof(foo)<<endl; //4
    cout << "size uninit packed " << sizeof(uninit_packed)<<endl; //13
    cout << "size uninit unpacked " << sizeof(uninit_unpacked)<<endl; //13
    return 0;
}