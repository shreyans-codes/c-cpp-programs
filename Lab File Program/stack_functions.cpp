#include <iostream>
using namespace std;
template <class T>
class stack
{
public:
    int a[10];
    T top;
    stack()
    {
        top = -1;
    }
    void push(T t)
    {
        top++;
        a[top] = t;
    }
    void display()
    {
        cout << "Stack : ";
        for (int i = 0; i <= top; i++)
        {
            cout << a[i] << " ";
        }
    }
    void pop()
    {
        top--;
    }
};
int main()
{
    stack<int> new_stack;
    new_stack.push(20);
    new_stack.push(30);
    new_stack.push(40);
    cout << "After pushing 3 elements (20, 30, 40)\n";
    new_stack.display();
    new_stack.pop();
    cout << "\n\nAfter poping an element\n";
    new_stack.display();
}