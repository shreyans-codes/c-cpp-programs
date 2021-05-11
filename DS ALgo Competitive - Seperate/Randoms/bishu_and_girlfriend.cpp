//Link - https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/description/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int i, height = 0, minimum = INT32_MAX, current = INT32_MAX;
vector<int> visit(1e7, 0);
vector<int> girls(1e7, INT32_MAX);


void dfs(int child,vector<vector<int>> &roads, int Q, int *countries)
{
    height++;
    visit[child] == 0 ? visit[child] = height : height = visit[child];
    for (int j = 0; j < Q; j++)
    {
        if (child == countries[j])
        {
            if(height<minimum){
                minimum = height;
                current = child;
            } else if(height==minimum) {
                current > child ? current = child : current = current;
            }
            break;
        }
    }

    for (int k = 0; k < roads[child].size(); k++)
    {
        i = roads[child][k];
        if (visit[i] == 0)
        {
            dfs(i, roads ,Q, countries);
        }
    }
    cout<<current<<endl;
}

int main()
{
    int v, u, N, Q;
    cin >> N;
    vector<vector<int>> roads(N);
     for(int i=0;i<N-1;i++)
          {
            cin>>v>>u;
            v--;
            u--;
            roads[v].push_back(u);
            roads[u].push_back(v);
          }
    cin >> Q;
    int countries[Q];
    for (int i = 0; i < Q; i++)
        cin >> countries[i];
    return 0;
}