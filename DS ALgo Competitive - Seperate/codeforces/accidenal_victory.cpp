//Link - https://codeforces.com/problemset/problem/1490/E
#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::sort;
using std::vector;

struct Token
{
    int index;
    int value;
};

int main()
{
    int T, temp;
    cin >> T;
    temp = T;
    vector<vector<int>> answer[(T*2)];
    while (T > 0)
    {
        int N;
        cin >> N;
        Token tokens[N];
        int count = 0, list[N] = {0};
        for (int i = 0; i < N; i++)
        {
            cin >> tokens[i].value;
            tokens[i].index = i;
        }
        sort(tokens, tokens + N, [](const Token &a, const Token &b) {
            return a.value < b.value;
        });
        for (int i = 0; i < N - 1; i++)
        {
            if (tokens[i].value < tokens[i + 1].value)
            {
                count = N - i;
                list[i] = 1;
                break;
            }
            else if (tokens[i].value == tokens[i + 1].value)
            {
                list[i] = 2;
            }
        }
        if (list[0] == 2 && list[N - 2] == 2)
        {
            answer[(T*2) - 1].push_back(N);
            answer[(T*2)].push_back(list);
            cout<<std::endl;
        }
        else
        {
            cout << count << std::endl;
            for (int i = 0; i < N; i++)
            {
                if (list[i] == 1)
                    continue;
                cout << i + 1 << " ";
            }
            cout<<std::endl;
        }
        T--;
    }
    return 0;
}
/*
1
5
3
5 4 7
5
4 7 8 7 5
*/