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
    ll n, sum;
    cin >> n >> sum;
    vector<pair<int, int>> s;
    for (ll i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push_back({x, i});
    }
    sort(s.begin(), s.end());
    int xPos = 0, yPos = 0, lMin = 0, lMax = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        lMin = 0, lMax = n - 1;
        j = lMin + (lMax - lMin) / 2;
        while (lMin <= lMax && j != i)
        {
            // cout << lMin << " " << lMax << " " << j << endl;
            if (s[j].first + s[i].first == sum)
            {
                xPos = min(s[j].second + 1, s[i].second + 1);
                yPos = max(s[j].second + 1, s[i].second + 1);
                // cout << "Here j = " << j << " i = " << i << endl;
                break;
            }
            else if (s[j].first + s[i].first > sum)
                lMax = j - 1;
            else
                lMin = j + 1;
            j = lMin + (lMax - lMin) / 2;
        }

        if (xPos != 0 || yPos != 0)
            break;
        // if (s[n - 1].first + s[i].first == sum)
        // {
        //     xPos = min(s[j].second + 1, s[i].second + 1);
        //     yPos = max(s[j].second + 1, s[i].second + 1);
        //     break;
        // }
    }
    if (xPos == 0 && yPos == 0)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << xPos << " " << yPos << endl;
    return 0;
}
