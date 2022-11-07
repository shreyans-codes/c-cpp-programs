#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, pepCount = 0, maxCount = 0;
    cin >> n;
    int a, l;
    vector<pair<int, int>> s;
    for (ll i = 0; i < n; i++)
    {
        cin >> a >> l;
        pair<int, int> arr = {a, 1};
        pair<int, int> leave = {l, -1};
        s.push_back(arr);
        s.push_back(leave);
    }
    sort(s.begin(), s.end());
    // for (ll i = 0; i < (2 * n); i++)
    // {
    //     cout << s[i].first << " - " << s[i].second << endl;
    // }

    for (ll i = 0; i < (2 * n); i++)
    {
        if (s[i].second == 1)
        {
            pepCount++;
        }
        else if (s[i].second == -1)
        {
            pepCount--;
        }
        maxCount = max(maxCount, pepCount);
    }
    cout << maxCount << endl;
    return 0;
}