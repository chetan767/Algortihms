///Write a program  to determine the minimum spanning tree of a graph
/// MADE BY CHETAN KHANNA
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union_mst(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal_mst(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        if(root(x) != root(y))   // Check if the selected edge is creating a cycle or not
        {
            minimumCost += cost;
            union_mst(x, y);
            cout<<x<<" -> "<<y<<"  weight = "<<p[i].first<<endl;
        }
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    cout<<"\n\nMST :\n\n";
    minimumCost = kruskal_mst(p);
    cout <<"\n\nMINIMUM COST  = "<<minimumCost << endl;
    return 0;
}
