/*
    * कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    * मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

    * Karmanye vadhikaraste Ma Phaleshu Kadachana,
    * Ma Karmaphalaheturbhurma Te Sangostvakarmani,

    * The meaning of the verse is :—
    * You have the right to work only but never to its fruits.
    * Let not the fruits of action be your motive, nor let your attachment be to
    * inaction
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
// CPP program for finding number of divisor
#include <bits/stdc++.h>

using namespace std;

// program for finding no. of divisors
int divCount(int n)
{
    // sieve method for prime calculation
}

// driver program
int main()
{
    int n = 24;
    cout << divCount(n);
    return 0;
}

*/

ll findDivisors(ll n)
{
    bool hash[n + 1];
    memset(hash, true, sizeof(hash));
    for (ll p = 2; p * p < n; p++)
        if (hash[p] == true)
            for (ll i = p * 2; i < n; i += p)
                hash[i] = false;

    // Traversing through all prime numbers
    ll total = 1;
    for (ll p = 2; p <= n; p++)
    {
        if (hash[p])
        {

            // calculate number of divisor
            // with formula total div =
            // (p1+1) * (p2+1) *.....* (pn+1)
            // where n = (a1^p1)*(a2^p2)....
            // *(an^pn) ai being prime divisor
            // for n and pi are their respective
            // power in factorization
            ll count = 0;
            if (n % p == 0)
            {
                while (n % p == 0)
                {
                    n = n / p;
                    count++;
                }
                total = total * (count + 1);
            }
        }
    }
    return total;
}

int main()
{
    ll n, num = 2;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 2)
        {
            cout << 1 << endl;
            continue;
        }
        num = findDivisors(arr[i] - 1);
        cout << num << endl;
        num = 2;
    }

    return 0;
}