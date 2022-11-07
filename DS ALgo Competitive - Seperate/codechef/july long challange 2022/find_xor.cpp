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
        int n, flag = 0, a, b, c, count = 0;
        cin >> n;
        int vals[n + 1];
        for (int i = 0; i <= n; i++)
            cin >> vals[i];

        int i = 0, j = 0, k = 0;
        do
        {
            do
            {
                do
                {
                    if (i > n || j > n || (vals[0] - i - j) > n)
                        break;
                    int ans = (k ^ i) + (k ^ j) + (k ^ (vals[0] - i - j));
                    if (ans == vals[k])
                        count++;
                    if (count == (n + 1))
                    {
                        flag = 1;
                        a = i;
                        b = j;
                        c = vals[0] - i - j;
                    }
                    k++;
                } while (k <= n);
                count = 0;
                k = 0;
                if (flag)
                    break;
                j += 2;
            } while (j <= (vals[0] / 2));
            if (flag)
                break;
            i += 2;
            j = i;
        } while (i <= (vals[0] / 2));
        cout << a << " " << b << " " << c << " " << endl;
    }

    return 0;
}
