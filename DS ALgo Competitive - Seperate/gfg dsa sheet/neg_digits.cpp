//* Link -https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
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
    ll n;
    cin >> n;
    ll arr[n], b[n], p1 = 0, p2 = n - 1;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        cout << arr[i] << endl;
    }
    for (ll j = 0; j < n; j++)
    {
        if (arr[j] < 0)
        {
            b[p1] = arr[j];
            p1++;
            cout << "B at " << p1 << " is " << b[p1] << endl;
        }
        else
        {
            b[p2] = arr[j];
            p2--;
            cout << "B at " << p2 << " is " << b[p2] << endl;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }

    return 0;
}
