#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin >> n;
    pair<ll, ll> arr[n];
    vector<ll> noOfPeople;
    ll maxim = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        for (ll j = arr[i].first; j < arr[i].second; j++)
        {
            noOfPeople[j] > 0 ? noOfPeople[j]++ : noOfPeople[j] = 1;
            if (maxim <= noOfPeople[j])
                maxim = noOfPeople[j];
        }
    }
    cout << maxim;

    return 0;
}