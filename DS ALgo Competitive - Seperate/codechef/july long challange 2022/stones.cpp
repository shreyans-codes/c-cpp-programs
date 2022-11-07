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
        ll n;
        cin >> n;
        ll temp, sum = 0;
        string ans = "CHEFINA";
        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp == 1)
                ans = "CHEF";
            sum += temp;
        }
        if (ans == "CHEF")
        {
            cout << ans << endl;
            continue;
        }
        sum = sum - (n * 2);
        if (sum % 2 == 0)
            ans = "CHEFINA";
        else
            ans = "CHEF";
        cout << ans << endl;
    }

    return 0;
}
