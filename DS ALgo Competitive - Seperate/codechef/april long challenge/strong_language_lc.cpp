//Link - https://www.codechef.com/APRIL21C/problems/SSCRIPT
#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::string;

int main()
{
    int T;
    cin >> T;
    while (T != 0)
    {
        int K, N, count = 0, flag = 0;
        cin >> N >> K;
        char input[N];
        string answer = "NO";
        for (int i = 0; i < N; i++)
        {
            cin >> input[i];
            input[i] == '*' ? count++ : count = 0;
            count >= K ? flag = 1 : count = count;
        }
        flag == 1 ? answer = "YES" : "NO";
        cout << answer << std::endl;
        T--;
    }
}