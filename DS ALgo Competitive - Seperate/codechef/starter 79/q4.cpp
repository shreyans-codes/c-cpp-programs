#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;

    cin >> t;

    while (t--)
    {
        ll n, y;
        cin >> n >> y;
        ll c = 2;
        if (n % 2 == 0)
        {
            if ((y - n) % 2 == 0)
                cout << (y - n) / 2 << endl;
            else
                cout << ((y - n) / 2) + 1 << endl;
        }
        else
        {
            ll x = n;
            while (x > 1)
            {
                if (x % c == 0)
                {
                    x /= c;
                    break;
                }
                else
                    c++;
            }
            n += c;
            if ((y - n) % 2 == 0)
                cout << ((y - n) / 2) + 1 << endl;
            else
                cout << ((y - n) / 2) + 2 << endl;
        }
    }

    return 0;
}