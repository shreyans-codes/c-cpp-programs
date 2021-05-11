//Link - https://atcoder.jp/contests/dp/tasks/dp_c
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int activites[n][3];
    for (int i = 0; i < n; i++)
    {
        cin >> activites[i][0];
        cin >> activites[i][1];
        cin >> activites[i][2];
    }
    int max_happiness_a = 0, max_happiness_b = 0, max_happiness_c = 0, temp_a = 0, temp_b = 0, temp_c = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            max_happiness_a = activites[i][0];
            max_happiness_b = activites[i][1];
            max_happiness_c = activites[i][2];
            temp_a = max_happiness_a;
            temp_b = max_happiness_b;
            temp_c = max_happiness_c;
            continue;
        }
        max_happiness_a = activites[i][0] + max(temp_b, temp_c);
        max_happiness_b = activites[i][1] + max(temp_a, temp_c);
        max_happiness_c = activites[i][2] + max(temp_b, temp_a);
        temp_a = max_happiness_a;
        temp_b = max_happiness_b;
        temp_c = max_happiness_c;
    }
    int answer;
    if (max_happiness_a > max_happiness_b && max_happiness_a > max_happiness_c)
        answer = max_happiness_a;
    else if(max_happiness_b > max_happiness_c)
        answer = max_happiness_b;
    else
        answer = max_happiness_c;    
    cout << answer << endl;
}