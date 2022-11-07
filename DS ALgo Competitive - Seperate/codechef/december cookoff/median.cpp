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

// ll findDivisors(ll n)
// {
//     vector<int> v;
//     for (int i = 1; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {

//             // check if divisors are equal
//             if (n / i == i)
//                 v.push_back(i);
//             else
//             {
//                 v.push_back(i);

//                 // push the second divisor in the vector
//                 v.push_back(n / i);
//             }
//         }
//     }
//     return v.size();
// }

int main()
{
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll n, ans;
        cin >> n;
        ll arr[n];
        for (ll j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        sort(arr, arr + n);
        ans = abs(arr[n / 2] - arr[(n / 2) - 1]);
        cout << ans << endl;
    }

    return 0;
}