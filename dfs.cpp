///Implement Depth-First Search in a graph
/// MADE BY CHETAN KHANNA
#include <bits/stdc++.h>
using namespace std;

vector <int> adj[10];
bool visited[10];

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs(int s)
{
    visited[s] = true;
    cout<<s<<"  ";

    for(int i = 0; i < adj[s].size(); ++i)
    {
        if(visited[adj[s][i]] == false)
        {

            dfs(adj[s][i]);
        }
    }
}

void initialize()
{
    for(int i = 0; i < 10; ++i)
        visited[i] = false;
}

int main()
{
    int nodes, edges, x, y;
    cin >> nodes;
    cin >> edges;
   for(int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        addEdge(x,y); //Edge from vertex x to vertex y

    }

    int s = 0;

    cout<<"\n\nDFS : ";
    dfs(s);

    return 0;
}
  /*
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);
    initialize();
    */
    /// DFS : 0 1 2 3 4
