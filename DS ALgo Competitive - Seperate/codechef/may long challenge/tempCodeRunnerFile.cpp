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
        for (int i = 0; i <= (n + 1); i += k)
        {
            if (i == x)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            for (int i = (n + 1); i >= 0; i -= k)
            {
                if (i == x)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}