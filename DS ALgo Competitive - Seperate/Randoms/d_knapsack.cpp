//Link - https://atcoder.jp/contests/dp/tasks/dp_d
#include <iostream>
#include <algorithm>
#define MAX_N 101

using std::cin;
using std::cout;
using std::sort;
using std::max;

int memo[MAX_N] = {0};
int max_profit = 0;
    
int findMaxValue(int *w, int *v, int W, int curr) {
    if(w[curr] > W)
        return 0;
    if(memo[curr] != 0)
        return memo[curr];
    memo[curr] = v[curr] + max(findMaxValue(w, v, W - w[curr], curr++), findMaxValue(w, v, W, curr++));
    memo[curr] > max_profit ? max_profit = memo[curr] : max_profit = max_profit;
    return max_profit;
}

int main()
{
    int N, W;
    cin >> N >> W;
    int weight[N];
    int value[N];
    for (int i = 0; i < N; i++)
        cin >> weight[i] >> value[i];
    int answer = findMaxValue(weight, value, W, 0);
    cout<<max_profit;
}