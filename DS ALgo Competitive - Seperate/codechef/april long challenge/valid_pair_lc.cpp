//Link - https://www.codechef.com/APRIL21C/problems/SOCKS1
#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::string;

int main() {
    int socks[3];
    for (int i = 0; i < 3; i++)
        cin>>socks[i];
    string output = "NO";
    if(socks[0] == socks[1] || socks[0] == socks[2])
        output = "YES";
    else if(socks[1] == socks[2])
        output = "YES";
    cout<<output<<std::endl;
    
}