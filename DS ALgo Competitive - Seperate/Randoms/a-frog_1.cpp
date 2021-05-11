//Link - https://atcoder.jp/contests/dp/tasks/dp_a
//* Completed but not submitted because no account on the site
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;

void findLeastCost(int *arr, int N) {
    int costFromLocation[N], temp1, temp2;
    for (int i = N - 1; i >= 0; i--)
    {
        if (i == (N - 1))
            costFromLocation[i] = 0;
        else if (i == (N - 2))
            costFromLocation[i] = abs(arr[N - 1] - arr[i]);
        else {
            temp1 = abs(arr[i] - arr[i+1]) + costFromLocation[i+1];
            temp2 = abs(arr[i] - arr[i+2]) + costFromLocation[i+2];
            temp1 >= temp2 ? costFromLocation[i] = temp2 : costFromLocation[i] = temp1;
        }
    }
    cout<<costFromLocation[0]<<std::endl;
}

int main() {
    int N;
    cin>>N;
    int h[N];
    for (int i = 0; i < N; i++)
        cin>>h[i];
    findLeastCost(h, N);
    return 0;
}