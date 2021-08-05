#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    ll n, mW, total = 0, count = 0;
    cin >> n >> mW;
    ll weights[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    sort(weights, weights + n);
    for (ll i = (n - 1); i >= 0; i--)
    {
        if (weights[i] == -1)
            continue;
        if (weights[i] == mW)
        {
            total++;
            continue;
        }
        ll temp = weights[i], j = count;
        while (j <= i)
        {
            if(weights[j] == -1) {
                j++;
                continue;
            }
            if ((weights[j] + temp) <= mW)
            { 
                weights[j] = -1;
                weights[i] = -1;
                count++;
                total++;
                break;
            }
            else
            {
                total++;
                break;
            }
        }
    }
    cout << total << endl;
    return 0;
}