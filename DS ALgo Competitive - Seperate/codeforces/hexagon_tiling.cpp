#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b, c, sum = 7, flag = 0;
    cin >> a >> b >> c;
    if ((a - 2) > 0)
    {
        sum += (abs(a - 2) * 2);
    }
    if ((b - 2) > 0)
    {
        sum += (abs(b - 2) * c) + 1;
        flag = 1;
    }
    if ((c - 2) > 0)
    {
        flag == 1 ? sum += abs(c - 2) *b : sum += (abs(c - 2) * b) + 1;
    }
    cout << sum << endl;

    return 0;
}