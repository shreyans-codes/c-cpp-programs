/*
    * कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    * मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

    ! Karmanye vadhikaraste Ma Phaleshu Kadachana,
    ! Ma Karmaphalaheturbhurma Te Sangostvakarmani,

    ? The meaning of the verse is :—
    ? You have the right only to work but never to its fruits.
    ? Let not the fruits of action be your motive, nor let your attachment be to
    ? inaction
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //* no of edges, no of vertices
    int nE, nV;
    cin >> nE >> nV;
    //* With adjacency matrix
    int adj_matrix[nV][nV] = {0};
    //* With adjacency list
    map<int, list<int>> adj_list;
    for (int i = 0; i < nE; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_matrix[a - 1][b - 1] = 1;
        adj_matrix[b - 1][a - 1] = 1;
        //* Pushing to both ends since it is an undirected graph
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    cout << "With adjacency matrix" << endl;
    for (int i = 0; i < nV; i++)
    {
        cout << i + 1 << " is conntected to: ";
        for (int j = 0; j < nV; j++)
        {
            if (adj_matrix[i][j] == 1)
                cout << j + 1 << " ";
        }
        cout << endl;
    }
    cout << "With adjacency list" << endl;
    for (auto i : adj_list)
    {
        cout << i.first << " is connected to: ";
        for (auto j : i.second)
            cout << " " << j;
        cout << endl;
    }
    return 0;
}
/*
Sample input:
5 5
1 2
2 4
4 5
2 3
5 3
*/