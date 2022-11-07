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
        int x1, y1, x2, y2, diff;
        cin >> x1 >> y1 >> x2 >> y2;
        diff = (x1 - x2) + (y1 - y2);
        if (diff % 2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
