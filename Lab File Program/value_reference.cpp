#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//Function that just takes value as parameters
void callByValue(int x, int y, int output) {
    output = x + y;
    cout<<"Inside Function = "<<output<<endl;
}
//Function that takes reference as parameters
void callByReference(int &x, int &y, int &output) {
    output = x + y;
    cout<<"Inside Function = "<<output<<endl;
}

int main()
{
    int a, b, sum = 0;
    cout<<"For Call By Value"<<endl;
    cout<<"Enter Two Numbers: "<<endl;
    cin>>a>>b;
    //This does not change the values of the actual variables
    callByValue(a, b, sum);
    cout<<"Outside Function = "<<sum<<endl;
    cout<<"For Call By Refernce"<<endl;
    //This changes the value of the variables passed into it
    callByReference(a, b, sum);
    cout<<"Outside Function = "<<sum<<endl;
    return 0;
}