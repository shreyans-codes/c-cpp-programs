#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, e; //No of nodes, edges
    cin>>n>>e;
    vector <int> adj[n]; //Adjacency List
    int visit[n] = {0}, u, v, current;
    for (int i = 0; i < e; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(0); //This will be the source
    visit[0] = 1;
    while (q.size()!=0)
    {
        current = q.front();
        q.pop();
        for (auto i : adj[current])
        {
            if(visit[i] == 0) {
                cout<<i<<endl;
                q.push(i);
                visit[i] = 1;
            }
        }
        
    }
    
}