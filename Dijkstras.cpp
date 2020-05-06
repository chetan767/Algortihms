#include<bits/stdc++.h>

using namespace std;

template<typename T>
class graph
{
public :
    map<T,list<pair<T,int> > > h;
    void addEdge(T u,T v,int dist,bool bidir=true)
    {
        h[u].push_back({v,dist});
        if(bidir)
        {
            h[v].push_back({u,dist});
        }
    }
    void Print()
    {
        for(auto node:h)
        {
            cout<<node.first<<"-->";
            for(auto children:node.second)
            {
                cout<<"("<<children.first<<","<<children.second<<") ";
            }
            cout<<endl;
        }
    }
void printPath(unordered_map<T,T> &parent, int j,int src)
{

    // Base Case : If j is source
    if (j == src)
    {
     cout<<src;
        return;
}

    cout<<j<<" <-- ";
    printPath(parent, parent[j],src);

}
    void ssp(T src)
    {
        map<T,int> dist;
        unordered_map<T,T> path;
        for(auto node : h)
        {
            dist[node.first] = INT_MAX;
        }
        dist[src]=0;
        path[src]=src;
        set<pair<int,T> > s;
        s.insert({0,src});

        while(!s.empty())
        {
            auto p = *(s.begin());
            s.erase(s.begin());
            T parent  = p.second;
            int p arentdist = p.first;
            for(auto children:h[parent])
            {
                if(dist[children.first]>parentdist+children.second)
                {
                  auto f = s.find({dist[children.first],children.first});
                if(f!=s.end()){

						s.erase(f);

					}
                    path[children.first]= parent;
					dist[children.first] = parentdist + children.second;
					s.insert({dist[children.first],children.first});
				}
			}
		}
		for(auto node:dist){
			cout<<"Distance of "<<node.first<<" from "<<src<<" is "<<node.second<<endl;
			printPath(path,node.first,src);
			cout<<"\n";
		}

		}
    };

    int main()
    {

        graph<int> g;

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.Print();
    cout<<"\n\n\n";
    g.ssp(0);
    }
