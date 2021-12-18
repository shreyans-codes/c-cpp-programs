#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        //? Why do we need the i variable here
        //*My guess: To ensure duplication of values in the set
        s.insert(make_pair(a, i));
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        // Returns the location of first occurance of a value >= t+1
        auto it = s.lower_bound(make_pair(t + 1, 0));
        if (it == s.begin())
            cout << -1 << endl;
        else
        {
            --it;
            cout << (*it).first << endl;
            s.erase(it);
        }
    }
    return 0;
}