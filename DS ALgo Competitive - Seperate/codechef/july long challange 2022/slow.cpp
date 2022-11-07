/*
    * कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    * मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

    ! Karmanye vadhikaraste Ma Phaleshu Kadachana,
    ! Ma Karmaphalaheturbhurma Te Sangostvakarmani,

    ? The meaning of the verse is :—
    ? You have the right to work only but never to its fruits.
    ? Let not the fruits of action be your motive, nor let your attachment be to
    ? inaction
*/
#include <bits/stdc++.h>
#include <stdio.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        ll mT, mN, sN;
        ll ans;
        cin >> mT >> mN >> sN;
        ll itMul = sN / mN, rem = sN % mN;
        rem > 0 ? itMul++ : itMul = itMul;
        if (itMul > mT)
        {
            ans = (mN * mN) * mT;
            cout << ans << endl;
            continue;
        }
        else
        {
            rem > 0 ? itMul-- : itMul = itMul;
            ans = (mN * mN) * itMul + (rem * rem);
            cout << ans << endl;
            continue;
        }
    }

    return 0;
}
