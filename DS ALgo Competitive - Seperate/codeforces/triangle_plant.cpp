#include <iostream>
#include <math.h>
using namespace std;

int power(long long x, unsigned long long y, int p)
{
    int res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// unsigned long long power(int base, unsigned long long pow) {
//     if (!pow)
//         return 1;
//     int result = 1;
//     while (pow) {
//         if (pow & 1) {
//             result *= base;
//             //pow--; // not necessary
//         }
//         pow >>= 1;
//         base *= base;
//     }
//     return result;
// }

// int main()
// {
//     unsigned long long n, ans1, ans2;
//     cin >> n;
//     ans1 = power(4, n, 1000000007);
//     ans2 = power(2, n, 1000000007);
//     //cout << "Total Triangles = " << ans1 << endl;
//     //cout << ans1 + ans1 / 2 << " + " << ans1 / 2 << " = ";
//     ans1 = (ans1 + ans2) / 2;
//     //cout << "Before XOR = " << ans1 << endl;
//     ans1 %= 1000000007;
//     cout << ans1 << endl;
//     return 0;
// }
int main()
{
    unsigned long long n, ans;
    cin >> n;
    ans = power(2, n, 1000000007);
    cout<<ans<<endl;
    //cout << "After power = " << ans << endl;
    cout << ans * ans;
    ans = (ans * ans / 2) + ans / 2;
    //cout << "Before XOR = " << ans << endl;
    ans = ans % 1000000007;
    cout << ans << endl;
    return 0;
}