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
//* Link: https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
#include <stdio.h>

#define ll long long
#define ull unsigned long long
using namespace std;

vector<int> dice(1000000, 0);
int sum = 0;

ull calcCombinations(int value)
{
    if (dice[value] != 0)
    {
        return dice[value];
    }
    else
    {
        for (int i = 1; i <= 6; i++)
        {
            if (value - i >= 0)
            {
                dice[value] += calcCombinations(value - i);
                dice[value] %= 1000000007;
            }
        }
    }
    return dice[value];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    dice[0] = 1;
    ull ans = calcCombinations(n);
    // ans = ans % 1000000007;
    cout << ans << endl;
    return 0;
}
