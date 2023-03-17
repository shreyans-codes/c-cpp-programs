#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
        ll n, a;
        cin >> n;
        ll maxEl = 0;
        map<ll, int> store;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (store[a])
            {
                store[a]++;
            }
            else
                store[a] = 1;
            maxEl = max(maxEl, a);
        }
        int limit = 0, j = 0;
        vector<ll> reps;
        for (ll i = 1; i <= maxEl; i++)
        {
            if (store[i])
            {
                limit++;
                if (store[i] > 1)
                {
                    reps.push_back(i);
                    j++;
                }
            }
            else
            {
                break;
            }
        }
        ll ans = limit;
        if (reps.size() != 0)
            ans += ((limit - reps[0]) + 1);
        for (int i = 1; i < reps.size(); i++)
        {
            ll diff = (limit - reps[i]) + 1;
            ll rCount = diff * store[reps[i]];
            ans += rCount;
        }
        if (reps.size() > 1)
            ans += (reps.size() - 1);
        ans = ans % 1000000007;
        cout << ans << endl;
    }
    return 0;
}
