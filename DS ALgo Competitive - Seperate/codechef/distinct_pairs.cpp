#include <iostream>
using namespace std;

int main() {
    long long N, M;
    cin>>N>>M;
    long long n_items[N];
    long long m_items[M];
    long long sum[(N+M)-1][3];
    for (long long i = 0; i < N; i++)
    {
        cin>>n_items[i];
    }
    for (long long i = 0; i < M; i++)
    {
        cin>>m_items[i];
    }
    for (long long i = 0; i < ((N+M)-1); i++)
    {
        long long num, sum = 0;
        i > N ? num = m_items[N-i] : num = n_items[i];
        for (long long j = 0; i < M; i++)
        {
            sum = num + m_items[i];
        }
        
    }
    
    return 0;
}