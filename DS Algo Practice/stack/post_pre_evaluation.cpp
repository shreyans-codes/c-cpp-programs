#include <bits/stdc++.h>
using namespace std;

int evaluate(string exp)
{
    stack<int> st;
    int count = 0;
    while (count < exp.length())
    {
        char c = exp[count];
        if (c == '*' || c == '/' || c == '+' || c == '-' || c == '^')
        {
            int o1 = st.top();
            cout << o1 << " " << c << " ";
            st.pop();
            int o2 = st.top();
            st.pop();
            cout << o2 << " "
                 << " = ";
            int value;
            switch (c)
            {
            case '*':
                value = o1 * o2;
                break;
            case '/':
                value = o1 / o2;
                break;
            case '+':
                value = o1 + o2;
                break;
            case '-':
                value = o1 - o2;
                break;
            case '^':
                value = o1 ^ o2;
                break;
            default:
                break;
            }
            cout << value << endl;
            st.push(value);
        }
        else
        {
            st.push(c - '0');
        }
        count++;
    }
    return st.top();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // postfix evaluation
    string exp = "536*13*++";
    int ans = evaluate(exp);
    cout << "Postfix: " << ans << endl;
    // prefix evaluation
    string exp2 = "++5*36*13";
    reverse(exp2.begin(), exp2.end());
    ans = evaluate(exp2);
    cout << "Prefix: " << ans << endl;
    return 0;
}