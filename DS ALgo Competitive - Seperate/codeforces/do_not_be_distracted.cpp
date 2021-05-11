//* Link - https://codeforces.com/contest/1520/problem/A
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        int n, flag = 0; //? 0 = Same alphabet before
        cin >> n;
        char questions[n];
        int ans = 0; //? 0 = NO
        for (int i = 0; i < n; i++)
        {
            cin >> questions[i];
            if (i == 0)
                continue;
            if (questions[i] == questions[i - 1])
                continue;
            else
            {
                for (int j = 0; j < i; j++)
                {
                    questions[j] == questions[i] ? flag++ : flag = flag;
                }
            }
        }
        flag > 0 ? cout << "NO" << endl : cout << "YES" << endl;
        t--;
    }

    return 0;
}