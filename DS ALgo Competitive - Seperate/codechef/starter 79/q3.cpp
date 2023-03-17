#include <iostream>
#include <bits/stdc++.h>
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
        int arr[n];
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
        while (next_permutation(arr, arr + (n / 2)))
        {
            int sums[n / 2];
            int count = 0;
            for (int i = 0; i < n / 2; i++)
                sums[i] = arr[i] + arr[n - i - 1];
            sort(sums, sums + (n / 2));
            for (int i = 0; i < (n / 2) - 1; i++)
            {
                if (sums[i] == sums[i + 1])
                {
                    break;
                }
                count++;
            }
            if (count == (n / 2) - 1)
                break;
        }
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
