// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)
    {
        int num = n + m;
        if (n > m)
        {
            sort(a, a + n);
            for (int i = 0; i < m; i++)
            {
                int mid = n / 2, l = 0, h = n - 1;
                while (l <= h)
                {
                    mid = l + (h - l) / 2;
                    if (a[mid] == b[i])
                    {
                        num--;
                        break;
                    }
                    else if (a[mid] > b[i])
                    {
                        h = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
            }
        }
        else
        {
            sort(b, b + m);
            for (int i = 0; i < n; i++)
            {
                int mid = m / 2, l = 0, h = m - 1;
                while (l <= h)
                {
                    mid = l + (h - l) / 2;
                    if (b[mid] == a[i])
                    {
                        num--;
                        break;
                    }
                    else if (b[mid] > a[i])
                    {
                        h = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
            }
        }
        return num;
    }
};

// { Driver Code Starts.

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

        int n, m;
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.doUnion(a, n, b, m) << endl;
    }

    return 0;
} // } Driver Code Ends