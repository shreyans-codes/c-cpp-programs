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
        int n;
        cin >> n;
        string inp, check, op;
        cin >> inp;
        int i = 0, j = 1, len = 0;
        while (j <= n)
        {
            if (i > 0 && inp.substr(0, j) == inp.substr(j, (j * 2)))
            {
                check += check;
                j += j;
                i = 2;
                continue;
            }
            if (i % 2 == 0)
            {
                check += inp[j - 1];
                j += j;
            }
            else
            {
                check += check;
                j++;
            }
            i++;
        }
        if (check == inp)
            op = "YES";
        else
            op = "NO";
        cout << op << endl;
    }

    return 0;
}
