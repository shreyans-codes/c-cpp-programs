#include <iostream>
using namespace std;

int main() {
    unsigned long long n;
    cin>>n;
    unsigned long long arr[n], tArr[n+1];
    for (unsigned long long i = 0; i < n - 1; i++)
    {
        cin>>arr[i];
        tArr[arr[i]] = 1;
    }
    for (unsigned long long i = 1; i <= n; i++)
    {
        if(tArr[i] != 1) {
            cout<<i;
            break;
        }
    }
    return 0;
}