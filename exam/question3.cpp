#include <iostream>
#include <string.h>

using namespace std;

// Class declared and defined
class ComplexNumber
{
private:
    int real;
    int imaginary;

public:
    // Contructor to give values to read and imaginary as soon as an object is created
    ComplexNumber(int r, int i) : real(r), imaginary(i)
    {
    }
    // Friend function 
    friend ComplexNumber operator-(const ComplexNumber &num);
    // Function to print the complex number
    void print()
    {
        cout << real << " " << imaginary << "i" << endl;
    }
};

//Unary operator overloading defined
ComplexNumber operator-(const ComplexNumber &num)
{
    return ComplexNumber(-(num.real), -(num.imaginary));
}

int main()
{
    //Object created with default values
    ComplexNumber c1(2, 8);
    cout << "c1 = ";
    c1.print();
    //Copy object created but with the overloaded unary - operator
    ComplexNumber c2 = -c1;
    cout << "c2 = ";
    c2.print();
    return 0;
}