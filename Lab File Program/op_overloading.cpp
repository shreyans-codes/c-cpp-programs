#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

//? The complex number class declared
class ComplexNumber
{
private:
    //? Private data members
    int real, imagCoEff;
    string imaginary;
public:
    //* Increment operator overloading
    void operator++() {
        real++;
        imagCoEff++;
    }
    //* Decrement operator overloading
    void operator--() {
        real--;
        imagCoEff--;
    }
    //* Subtraction operator overloading
    void operator-(ComplexNumber a) {
        real -= a.real;
        imagCoEff -= a.imagCoEff;
    }
    //* Addition operator overloading
    void operator+(ComplexNumber a) {
        real += a.real;
        imagCoEff += a.imagCoEff;
    }
    //* Function to print the Complex Number
    void printNumber() const {
        cout<<endl;
        cout<<"Real = "<<real<<endl;
        cout<<"Imaginary = "<<imaginary<<endl;
    }
    //* Parameterized Constructor
    ComplexNumber(int a, int b) {
        real = a;
        imagCoEff = b;
        imaginary = to_string(b) + "i";
    }
    //* Destructor
    ~ComplexNumber() {}
};

int main() {
    
    //* Two complex number object created
    ComplexNumber number1(10, 3);
    ComplexNumber number2(20, 1);

    //* Incremented number 1
    ++number1;
    number1.printNumber();

    //* Decremented number 2
    --number2;
    number2.printNumber();

    //* Subtracted number 2 from number 1 and printed number 1
    number1 - number2;
    number1.printNumber();

    //* Added number 1 to number 2 and printed number 2
    number2 + number1;
    number2.printNumber();

    return 0;
}