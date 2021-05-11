#include <iostream>

using std::cin;
using std::cout;
using std::endl;

static void printDetails(){
    static int count = 0;
    cout<<count<<endl;
    count++;
}

int main(){
    for (int i = 0; i < 5; i++)
    {
        printDetails();
    }
    return 0;
}