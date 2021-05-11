#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, k, flag = 0;
        cin >> n >> x >> k;
        if (x % k == 0)
            flag = 1;
        if (!flag)
        {
            if (((n + 1) - x) % k == 0)
                flag = 1;
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}