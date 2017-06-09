//Bellman Ford Algorithm
#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int s,d,w;
};

int bellmanFord(int n, int e, vector<edge> &edge, vector<int> &dist)
{
    int i,j,k;
    int s,d,w;

    cout<<"Enter the source vertex ";
    cin>>i;

    dist[i-1]=0;

    for(i=1;i<n;i++)
    {
        //for each edge
        for(j=0;j<e;j++)
        {
            s=edge[j].s;
            d=edge[j].d;
            w=edge[j].w;

            if(dist[s]!=INT_MAX && dist[s]+w<dist[d])
            {
                dist[d]=dist[s]+w;
            }
        }
    }

    //this loop is to detect a negative loop
    for(j=0;j<e;j++)
    {
        s=edge[i].s;
        d=edge[i].d;
        w=edge[i].w;

        if(dist[s]!=INT_MAX && dist[s]+w<dist[d])
        {
            //we have caught a negative loop
            return 0;
        }
    }

    //all okay signal
    //indicating no negative loop
    return 1;
}

int main()
{
    int i;
    int n,e;
    int s,d,w;

    cout<<"Enter the number of vertices ";
    cin>>n;

    cout<<"Enter the number of edges ";
    cin>>e;

    vector<edge> edge(e);

    cout<<"Enter the src, dest and weight of each edge"<<endl;
    for(i=0;i<e;i++)
    {
        cin>>s>>d>>edge[i].w;
        edge[i].s=s-1;
        edge[i].d=d-1;
    }


    //create a vector of size n(for n vertices) and initialize the value of each element to infinity
    vector<int> dist(n,INT_MAX);

    i=bellmanFord(n,e,edge,dist);
   
    if(i)
    {
        cout<<"vectex      distance from source"<<endl;
        for(i=0;i<n;i++)
        {
            cout<<i+1<<"         "<<dist[i]<<endl;
        }
    }

    else
    {
        //negative loop
        cout<<"There is a negative weight loop in the graph "<<endl;
    }

    return 0;
}

/*
 output
 $ g++ test6.cpp
 $ ./a.out
 Enter the number of vertices 5
 Enter the number of edges 7
 Enter the src, dest and weight of each edge
 1 2 17
 2 3 25
 3 4 1
 4 2 -24
 2 5 15
 1 4 40
 5 3 9
 Enter the source vertex 1
 vectex      distance from source
 1         0
 2         16
 3         40
 4         40
 5         31

 */
