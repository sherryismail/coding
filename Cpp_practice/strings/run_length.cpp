#include <iostream>
#include <string>
using namespace std;
/*Run Length Encoding is a very simple form of lossless data compression 
in which repeated or runs of data are stored as a single data value and count.

consider a code: COOODDDEEEESPEEDDDDDDDYYYYYYYYY
C1O3D3E4S1P1E2D7Y9
aabbbccc
*/

int main(void){
    string output="", input = "COOODDDEEEESPEEDDDDDDDYYYYYYYYY";
    int counter=1;
    for(int i=1; i <= input.length(); i++)
    {
        if (input[i] == input[i-1])
            counter++;
        else {
            output.append(1,input[i-1]);
            output.append(to_string(counter));   
            counter=1;
        }

    }
    cout << output;
    return 0;
}
