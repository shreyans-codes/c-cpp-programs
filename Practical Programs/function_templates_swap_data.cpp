#include <iostream>

using namespace std;

template <class T>
void Swap(T &var1, T &var2)
{
    T temp = var1;
    var1 = var2;
    var2 = temp;
}

int main()
{
    int var1 = 4, var2 = 7;
    float var3 = 4.5, var4 = 7.5;

    cout << "Before Swap: ";
    cout << "\nVar1 = " << var1 << "\nVar2 = " << var2;
    cout << "\n\nVar3 = " << var3 << "\nVar4 = " << var4;

    Swap(var1, var2);
    Swap(var3, var4);

    cout << "\n\nAfter Swap:";
     cout << "\nVar1 = " << var1 << "\nVar2=" << var2;
    cout << "\n\nVar3=" << var3 << "\nVar4=" << var4;

    return 0;
}