//Link - https://www.codechef.com/problems/UWCOI21D
#include <iostream>
using namespace std;

/*
We need to find which horizontal road we can turn into a highway. The way we do that is we see the delivery routes and increment the flag of
all the y between starting y and the destination y.
*/
struct Point
{
    int x;
    int y;
}

int
main()
{
    int N, M, K;
    cin >> N >> M >> K;
    Point start[K], destination[K];
    int highway[M] = {0}, maximum = 0, flag;
    for (int i = 0; i < K; i++)
    {
        cin >> start[i].x >> start[i].y;
        cin >> destination[i].x >> destination[i].y;
        for (int j = min(start[i].y, destination[i].y); j < max(start[i].y, destination[i].y); j++)
        {
            highway[j]++;
        }
    }
    for (int i = 0; i < M; i++)
    {
        if (highway[i] > maximum)
        {
            maximum = highway[i];
            flag = i;
        }
    }
    
    return 0;
}