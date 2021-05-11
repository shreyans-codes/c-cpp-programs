#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class A;
class B{
    private:
    int b = 10;
    public:
    friend void multiply(A &a, B &b);
};
class A{
    private:
    int a = 5;
    public:
    friend void multiply(A &a, B &b);
};

void multiply(A &a, B &b){
    cout<<endl<<"Result: "<<a.a * b.b<<endl;
}

int main(){
    A a;
    B b;
    multiply(a, b);
    return 0;
}