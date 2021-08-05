#include <iostream>
using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    cout << n << " ";
    while (n != 1)
    {
        n % 2 == 0 ? n /= 2 : n = (n * 3) + 1;
        cout << n << " ";
    }

    return 0;
}