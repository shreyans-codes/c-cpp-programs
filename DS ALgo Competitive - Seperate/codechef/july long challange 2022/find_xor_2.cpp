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

bool isPowerOf2(ll n)
{
    if (n > 0)
    {
        while (n % 2 == 0)
            n /= 2;
        if (n == 1)
            return true;
        return false;
    }
    return false;
}

int hPowerOf2(int n)
{
    int res = 0;
    for (int i = n; i >= 1; i--)
    {
        if ((i & (i - 1)) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}

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
        long n;
        cin >> n;
        long vals[n + 1];
        for (int i = 0; i <= n; i++)
            cin >> vals[i];
        long ans[3] = {0, 0, 0};
        for (int i = hPowerOf2(n); i > 0; i /= 2)
        {
            long diff = vals[i] - vals[0];
            if (diff < 0)
            {
                diff *= -1;
                int ct = diff / i;
                if (ct == 1)
                {
                    ct = 2;
                    if ((ans[0] ^ i) <= n)
                    {
                        ans[0] ^= i;
                        ct--;
                    }
                    if (ct && ((ans[1] ^ i) <= n))
                    {
                        ans[1] ^= i;
                        ct--;
                    }
                    if (ct > 0 && ((ans[2] ^ i) <= n))
                    {
                        ans[2] ^= i;
                    }
                }
                else if (ct == 3)
                {
                    ans[0] ^= i;
                    ans[1] ^= i;
                    ans[2] ^= i;
                }
            }
            else
            {
                int ct = diff / i;
                if (ct == 1)
                {
                    if ((ans[0] ^ i) <= n)
                        ans[0] ^= i;
                    else if ((ans[1] ^ i) <= n)
                        ans[1] ^= i;
                    else
                        ans[2] ^= i;
                }
            }
        }
        sort(ans, ans + 3);
        cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << endl;
    }

    return 0;
}
