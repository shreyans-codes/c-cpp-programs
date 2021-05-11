//Link - https://atcoder.jp/contests/dp/tasks/dp_b
//* Completed but not submitted because no account on the site
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;

void findLeastCost(int *arr, int N, int K) {
    int costFromLocation[N], temp1, temp2;
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i; j < K; j++)
        {

        }
        
    }
    cout<<costFromLocation[0]<<std::endl;
}

int main() {
    int N, K;
    cin>>N>>K;
    int h[N];
    for (int i = 0; i < N; i++)
        cin>>h[i];
    findLeastCost(h, N, K);
    return 0;
}