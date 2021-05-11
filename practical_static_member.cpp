#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Football
{
private:
    string comapany;

public:
    static string shape; //* Static variable declared
    Football()
    {
        comapany = "New Balance";
    }
    //* function to display data
    void displayData()
    {
        cout << endl;
        cout << "Company of the football - " <<Football::comapany << endl;
        cout << "Shape - " << shape << endl;
    }
    //* Static member function
    static void printMessage(){
        cout<<"\nThank You!"<<endl;
    }
    ~Football()
    {
        cout << "Destructor Called" << endl;
    }
};
string Football::shape = "Circle"; //* Static variable initialized
/*
  * The shape field is static because the shape of a football will always be the same i.e. Circle
  * so there is no need to allot memory to this with every object; 
  * This can be same across all objects of the football class; 
*/

int main()
{
    cout << "\nThe shape of the football is - " << Football::shape << endl; //* We do not even need to create an object to access static variables
    Football newBall;
    newBall.displayData();
    Football::printMessage();//* Member function called without any object
    return 0;
}