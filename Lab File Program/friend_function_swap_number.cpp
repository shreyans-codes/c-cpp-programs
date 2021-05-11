#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//* Forward Declaration of class B
class B;

class A
{
private:
    int num;

public:
    A(int a)
    {
        num = a;
    }
    void print()
    {
        cout << "\nValue = " << num;
    }
    //* Friend Function declared
    friend void swap(A &a, B &b);
};
class B
{
private:
    int num2;

public:
    B(int a) { num2 = a; }
    void print() { cout << "\nValue = " << num2; }
    friend void swap(A &a, B &b);
};

//* Friend Function to swap two numbers defined
void swap(A &a, B &b)
{
    int temp = a.num;
    a.num = b.num2;
    b.num2 = temp;
}
int main()
{
    A x(15);
    B y(37);
    //* Swap Friend Function called
    swap(x, y);
    x.print();
    y.print();
}