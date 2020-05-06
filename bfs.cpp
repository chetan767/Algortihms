///Implement Breadth-First Search in a graph
/// MADE BY CHETAN KHANNA
#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int> >adj;

void add_edge(int x, int y)
{
    adj[x].push_back(y);
}

void bfs(int s)
{
    queue<int> q;

    q.push(s);
    visited[s] = true;

    while (!q.empty()) {

        int j = q.front();
        q.pop();

        cout << j << " ";
          for (auto i = adj[j].begin(); i != adj[j].end(); i++) {
            if (!visited[*i]) {
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    visited.assign(n, false);
    adj.assign(n, vector<int>());

    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        add_edge(a, b);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            bfs(i);
    }

    return 0;
}
/*
Input:
8 10
0 1
0 2
0 3
0 4
1 5
2 5
3 6
4 6
5 7
6 7

Output:
0 1 2 3 4 5 6 7
*/
