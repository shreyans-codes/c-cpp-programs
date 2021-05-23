#include <iostream>
#include <math.h>
using namespace std;

int sumOfDigits(int n)
{
    int sum = 0, temp = 0;
    while (n != 0)
    {
        temp = n % 10;
        sum += temp;
        n /= 10;
    }
    return sum;
}

int main()
{
    long long n;
    cin >> n;
    if (n == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    int nearestRoot, ans, temp2;
    long long temp;
    nearestRoot = floor(sqrt(n));
    for (int i = 2; i <= 90 / 2; i++)
    {
        //temp = (pow(i, 2) + (sumOfDigits(i) * i)) - n;
        temp = pow(i, 2) + (4 * n);
        cout << "D = " << temp << endl;
        temp = sqrt(temp);
        cout << "Root of D = " << temp<<endl;
        temp2 = temp;
        cout << "Temp = " << temp << " Temp 2 = " << temp2 << endl;
        if (temp2 == temp)
        {
            temp = (i - temp) / 2;
            temp = (pow(temp, 2) + (i * temp)) - n;
            if (temp == 0)
                cout << temp2 << endl;
            else
            {
                temp = temp2;
                temp = (i + temp) / 2;
                temp = (pow(temp, 2) + (i * temp)) - n;
                if (temp == 0)
                    cout << temp2 << endl;
            }
            break;
        }
        cout << "Nroot = " << i << endl;
        cout << pow(i, 2) << " + " << sumOfDigits(i) << " * " << i << " - " << n << " = " << temp << endl;
        // if (temp == 0)
        // {
        //     cout << i << endl;
        //     break;
        // }
    }
    if (temp2 != temp)
        cout << -1 << endl;
}