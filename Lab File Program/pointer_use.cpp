#include <iostream>
using namespace std;
//? The test class
class Test
{
    int x;

public:
    void set(int *x)
    {
        this->x = *x;
    }
    void print()
    {
        cout << "Set value of X : " << x;
    }
};
int main()
{
    Test t;
    int x;
    cout << "Enter the value of X : ";
    cin >> x;
    t.set(&x);
    t.print();
}