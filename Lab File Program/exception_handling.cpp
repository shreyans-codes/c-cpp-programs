#include <iostream>
using namespace std;
int main()
{
    string s = "Hello";
    try
    {
        throw "This is an Example to throw Exceptions.";
    }
    catch (exception e)
    {
        cout << e.what();
    }
}