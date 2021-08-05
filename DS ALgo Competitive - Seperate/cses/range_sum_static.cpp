#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll n, q;
    cin >> n >> q;
    ll arr[n], sum[n];
    ll a, b, ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i == 0)
            sum[i] = arr[i];
        else
            sum[i] = sum[i - 1] + arr[i];
    }
    for (ll i = 0; i < q; i++)
    {
        cin >> a >> b;
        if (a == 1)
            ans = sum[b - 1];
        else
            ans = sum[b - 1] - sum[a - 2];
        cout << ans << endl;
    }

    return 0;
}