#include <iostream>
#include <vector>
using namespace std;

void dfs(int child, int parent, bool *visit, vector<vector<int>> &adj)
{
    visit[child] = true;
    for (auto i : adj[child])
    {
        if (visit[i] == false)
        {
            dfs(i, child, visit, adj);
        }
    }
    cout << child << " ";
}

int main()
{
    int N, E;
    cin >> N >> E;
    vector<vector<int>> adj(N);
    int u, v;
    bool visit[N];
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Tree as stored :" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " - ";
        }
        cout << endl;
    }

    dfs(0, -1, visit, adj);
}