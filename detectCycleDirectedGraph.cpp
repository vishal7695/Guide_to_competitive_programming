//detect cycle in a directed graph

#include<bits/stdc++.h>
using namespace std;

bool hasCycleDFS(int u, vector<bool> &visited, vector<bool> &beingVisited, vector<vector<int> > &adjList)
{
    beingVisited[u]=true;

    for(int i=0;i<adjList[u].size();i++)
    {
        int v=adjList[u][i];

        if(!visited[v])
        {
            if(beingVisited[v])
            {
                //we got a cycle
                return true;
            }

            else
            {
                //recursive call
                if(hasCycleDFS(v,visited,beingVisited,adjList))
                    return true;
            }
        }
    }
   
    beingVisited[u]=false;
    visited[u]=true;

    return false;
}

int main() 
{
    int i,j,k,l;
    int u,v;
    int n,e;

    cout<<"Enter the number of vertices ";
    cin>>n;

    cout<<"Enter the number of edges ";
    cin>>e;

    vector<vector<int> > adjList(n);

    cout<<"Enter the source and destination of every edge "<<endl;
    for(i=0;i<e;i++)
    {
        cin>>u>>v;

        adjList[u].push_back(v);
    }

    vector<bool> visited(n,false), beingVisited(n, false);

    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(hasCycleDFS(i,visited,beingVisited,adjList))
            {
                cout<<"Cycle found"<<endl;
                return 0;
            }

        }
    }


    cout<<"No Cycle found"<<endl;


    return 0;
}
