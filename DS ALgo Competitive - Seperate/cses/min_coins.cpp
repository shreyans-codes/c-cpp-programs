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

ll s[1000001] = {0}, max_n = 101;
ll arr[101];
ll minCoins(ll rem)
{
    if (rem < 0)
        return -1;
    if (rem == 0)
        return 0;
    for (ll i = 0; i < max_n; i++)
    {
        if (arr[i] > rem)
            break;
        s[rem - arr[i]] = minCoins(rem - arr[i]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, sum, nearest = 0;
    cin >> n >> sum;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s[arr[i]] = 1;
    }

    return 0;
}
