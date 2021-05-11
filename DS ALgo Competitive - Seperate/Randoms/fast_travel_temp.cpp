#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct city
{
    int y, x, s, ans;
    int distance(int x1, int y1)
    {
        ans = (std::abs(x - x1) + std::abs(y - y1));
        return ans;
    }
};
int main()
{
    int n;
    int t;
    cin >> n;
    cin >> t;
    city c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].s;
        cin >> c[i].x;
        cin >> c[i].y;
    }
    int nq;
    cin >> nq;
    for (int i = 0; i < nq; i++)
    {
        int c1;
        int c2;
        cin >> c1;
        cin >> c2;
        c1--;
        c2--;
        int d = c[c2].distance(c[c1].x, c[c1].y);
        int d1 = c[c2].distance(c[c1].x, c[c1].y);
        if (c[c1].s == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (c[i].s == 1)
                {
                    int dmin;
                    dmin = c[c1].distance(c[i].x, c[i].y);
                    if (d > dmin)
                        d = dmin;
                }
            }
        }

        if (c[c2].s == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (c[i].s == 1)
                {
                    int dmin;
                    dmin = c[c2].distance(c[i].x, c[i].y);
                    if (d1 > dmin)
                        d1 = dmin;
                }
            }
        }

        if ((c[c2].s == 1) & (c[c1].s == 1))
            cout << std::min(t, c[c2].distance(c[c1].x, c[c1].y)) << endl;
        if ((c[c2].s == 0) & (c[c1].s == 1))
            cout << std::min(d1 + t, c[c2].distance(c[c1].x, c[c1].y)) << endl;
        if ((c[c2].s == 0) & (c[c1].s == 0))
            cout << std::min(d + d1 + t, c[c2].distance(c[c1].x, c[c1].y)) << endl;
        if ((c[c2].s == 1) & (c[c1].s == 0))
            cout << std::min(d + t, c[c2].distance(c[c1].x, c[c1].y)) << endl;
    }

    return 0;
}