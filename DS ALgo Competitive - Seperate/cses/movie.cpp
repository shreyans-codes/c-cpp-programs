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
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    int x, y, movCount = 1, track;
    vector<pair<int, int>> s;
    for (ll i = 0; i < n; i++)
    {
        cin >> x >> y;
        s.push_back({y, x});
    }
    sort(s.begin(), s.end());
    track = s[0].first;
    //* Idea: Calc movie distance and sort on that basis
    for (ll i = 1; i < n; i++)
    {
        if (s[i].second < track)
            continue;
        track = s[i].first;
        movCount++;
    }
    cout << movCount << endl;
    return 0;
}
