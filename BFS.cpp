#include<bits/stdc++.h>
using namespace std;

template<typename t>
class graph
{
public :
    map<t,list<t> > adjlist;
    void addEdge(t u,t v,bool bidir=true)
    {
        adjlist[u].push_back(v);
        if(bidir)
        {
            adjlist[v].push_back(u);
        }
    }
    void print()
    {

        for(auto node : adjlist)
        {
            cout<<node.first<<" --> ";
            for(auto adj : node.second)
            {
                cout<<adj<<"  ";
            }
            cout<<"\n";
        }
    }

    void bfs(t src)
    {
        unordered_map<t,bool> visited;
        queue<t>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            t node = q.front();
            q.pop();
            cout<<node<<"   ";
            for(auto adj : adjlist[node])
            {
                if(!visited[adj])
                {
                    visited[adj]=true;
                    q.push(adj);
                }
            }
        }
    }

    void dfs_helper(t src,unordered_map<t,bool> &visited)
    {
        visited[src]=true;
        cout<<src<<"   ";
        for(auto node : adjlist[src])
        {
            if(!visited[node])
            {
                dfs_helper(node,visited);
            }
        }

    }

    void dfs(t src)
    {
    unordered_map<t,bool> visited;
    dfs_helper(src,visited);
    }



};

int main()
{
    graph<int> g;
    g.addEdge(1,2);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(0,4);
    g.print();
    cout<<"\nBFS : ";
    g.bfs(0);
    cout<<"\n\nDFS : ";
    g.dfs(0);
}

