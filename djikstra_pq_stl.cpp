#include<bits/stdc++.h>
using namespace std;
 
#define pii pair< int, int >
#define pb(x) push_back(x)
 
struct comp 
{
    bool operator() (const pii &a, const pii &b) 
    {
        return a.second > b.second;
    }
};
 
 
int main() 
{
    int i, u, v, w, sz, nodes, edges, starting,t,dest;
    int INF=INT_MAX;

    cin>>nodes>>edges;
    
    priority_queue< pii, vector< pii >, comp > Q;
    vector<vector< pii > > AdjList(nodes+1);
    vector<int> dist(nodes+1,INF);
    vector<bool> visited(nodes+1,false);

    // create graph
    for(i=0; i<edges; i++) 
    {
        cin>>u>>v>>w;

        AdjList[u].pb(pii(v, w));

        //for undirected
        //AdjList[v].pb(pii(u, w));  
    }

    cin>>starting;
 
    dist[starting] = 0;
    Q.push(pii(starting, 0));

 
    // dijkstra
    while(!Q.empty()) 
    {
        u = Q.top().first;
        Q.pop();
  
        //if this is not already visited
        if(!visited[u]) 
        {
            visited[u]=true;
            sz = AdjList[u].size();
           
            //for all adjacent nodes of u
            for(i=0; i<sz; i++) 
            {
                v = AdjList[u][i].first;
                w = AdjList[u][i].second;

                //v should be unvisited and should result into lesser distance value
                if(!visited[v] && dist[u]+w < dist[v]) 
                {
                    dist[v] = dist[u] + w;
                    Q.push(pii(v, dist[v]));
                }
            }
        }

    }

    // result
    for(i=0; i<=nodes; i++) 
        printf("Node %d, min weight = %d\n", i, dist[i]);

    return 0;
}
