//Link - https://www.codechef.com/APRIL21C/problems/SDICE
#include <iostream>

using namespace std;

long long findSidesBlocked(long long N)
{
    long long sum = 0, temp;
    long long rem = N % 4, q = N / 4;
    if (rem == 0)
        sum = 60 + (44 * (q - 1));
    else if (N > 3 && rem != 0)
    {
        q > 1 ? temp = 60 + (44 * (q - 1)) : temp = 60;
        temp -= rem * 4;
        if (rem == 1)
            sum = temp + 20;
        else if (rem == 2)
            sum = temp + 36;
        else
            sum = temp + 51;
    }
    else
    {
        if (rem == 1)
            sum = 20;
        else if (rem == 2)
            sum = 36;
        else
            sum = 51;
    }
    return sum;
}

/*
long long findSidesBlocked(long long N)
{
    long long retVal = 0, temp, sum = 0;
    long long rem = N % 4, q = N / 4;
    if (rem == 0)
        retVal = (12 * N) + ((N - 1) * 4);
    else if (N > 1 && rem != 0)
    {
        temp = (12 * N) + ((N - 1) * 4);
        
        if (rem == 1)
            retVal = temp + 2;
        else if (rem == 2)
            retVal = temp + 6;
        else
            retVal = temp + 10;
    }
    else
    {
        if (rem == 1)
            retVal = 1;
        else if (rem == 2)
            retVal = 4;
        else
            retVal = 7;
    }
    return retVal;
}
*/

int main()
{
    long long t;
    cin >> t;
    while (t != 0)
    {
        long long N, sum;
        cin >> N;
        sum = findSidesBlocked(N);
        cout << sum << std::endl;
        t--;
    }
    return 0;
}