#include <iostream>
#include <algorithm>
#include <math.h>
#define ll long long
using namespace std;

int main()
{
    ll n, m, d, total = 0, j = 0;
    cin >> n >> m >> d;
    ll desApp[n], appSize[m];
    for (ll i = 0; i < n; i++)
    {
        cin >> desApp[i];
    }
    sort(desApp, desApp + n);
    for (ll i = 0; i < m; i++)
    {
        cin >> appSize[i];
    }
    sort(appSize, appSize + m);
    for (ll i = 0; i < n; i++)
    {
        while (j < m && appSize[j] < desApp[i] - d)
            ++j;
        if(j < m && appSize[j] <= desApp[i] + d)
            ++total, ++j;
    }
    cout<<total<<endl;
    return 0;
}