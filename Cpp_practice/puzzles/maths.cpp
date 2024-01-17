#include <iostream>
using namespace std;
#include <chrono>
#include <iostream>
#include <thread>
 
void independentThread() 
{
    std::cout << "Starting concurrent thread.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Exiting concurrent thread.\n";
}
 
void threadCaller() 
{
    std::cout << "Starting thread caller.\n";
    std::thread t(independentThread);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Exiting thread caller.\n";
}
 //g++ file -lpthread
int main() 
{
    threadCaller();
    std::this_thread::sleep_for(std::chrono::seconds(5));
      //square of hysteresis
      register int in, out;
      const int max_x= 10, min_x = -10, ceil = 10, floor=-10;
      if (in > max_x)
        out = ceil;
    if (in < min_x)
        out = floor;
        return 0;
}