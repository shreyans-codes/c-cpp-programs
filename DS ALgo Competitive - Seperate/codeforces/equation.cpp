    #include <bits/stdc++.h>
    #include <math.h>
    using namespace std;
     
    long long sumOfDigits(long long n)
    {
        long long sum = 0, temp = 0;
        while (n != 0)
        {
            temp = n % 10;
            sum += temp;
            n /= 10;
        }
        return sum;
    }
     
    int main()
    {
        long long n;
        cin >> n;
        if (n == 2)
        {
            cout << 1 << endl;
            return 0;
        }
        else if (n == 1)
        {
            cout << -1 << endl;
            return 0;
        }
        long long ans, temp2, sum;
        long long temp, rTemp;
        double rootHolder;
        for (int i = 1; i <= 90; i++)
        {
            temp = pow(i, 2) + (4 * n);
            // cout << "D = " << temp << endl;
            rootHolder = sqrt(temp);
            // cout << "Root of D = " << rootHolder << endl;
            ans = rootHolder;
            temp2 = ceil(abs(ans - rootHolder));
            if (temp2 == 0)
            {
                ans = (i - rootHolder) / 2;
                ans = abs(ans);
                sum = sumOfDigits(ans);
                rTemp = (pow(ans, 2) + (i * ans)) - n;
                // cout << pow(ans, 2) << " + " << i << " * " << abs(ans) << " - " << n << " = " << rTemp << endl;
                if (rTemp == 0 && i == sum)
                {
                    cout << abs(ans) << endl;
                    break;
                }
                else
                {
                    // cout << "Here" << endl;
                    ans = (i + rootHolder) / 2;
                    ans = abs(ans);
                    sum = sumOfDigits(ans);
                    rTemp = (pow(ans, 2) + (i * ans)) - n;
                    // cout << pow(ans, 2) << " + " << i << " * " << abs(ans) << " - " << n << " = " << rTemp << endl;
                    if (rTemp == 0 && i == sum)
                    {
                        cout << abs(ans) << endl;
                        break;
                    }
                }
            }
            ans = -1;
        }
        if (ans == -1)
            cout << -1 << endl;
    }