//Floyd warshall algorithm

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int n,e;
    int s,d,w;

    cout<<"Enter the number of vertices ";
    cin>>n;

    //adjacency matrix
    //initialized to infinity
    vector<vector<int> > distMat(n,vector<int>(n,INT_MAX));

    for(i=0;i<n;i++)
    {
        //distance of verter i from itself is always zero
        distMat[i][i]=0;
    }

    cout<<"Enter the number of edges ";
    cin>>e;

    cout<<"Enter the src, dest and weight of each edge"<<endl;
    for(i=0;i<e;i++)
    {
        cin>>s>>d>>w;

        //add to the adjacency list
        
        distMat[s-1][d-1]=w;
    }

    //now, we have the adjacency matrix
    //we will create n matrices from this considering a vertex as an intermediate vertex
    
    //intermediate
    for(k=0;k<n;k++)
    {
        //source
        for(i=0;i<n;i++)
        {
            //destination
            for(j=0;j<n;j++)
            {
                if(distMat[i][k]!=INT_MAX && 
                   distMat[k][j]!=INT_MAX &&
                   distMat[i][k]+distMat[k][j]<distMat[i][j])
                {
                    distMat[i][j]=distMat[i][k]+distMat[k][j];
                }

            }
        }
    }

    cout<<"The all pairs shortest distance matrix is "<<endl;

    cout<<"       ";

    for(i=0;i<n;i++)
    {
        printf("%6d",i+1);
    }

    cout<<endl;

    for(i=0;i<6*n;i++)
    {
        cout<<"_";
    }

    cout<<"_______"<<endl;

    for(i=0;i<n;i++)
    {
        printf("%5d |",i+1);
        for(j=0;j<n;j++)
        {
            printf("%6d",distMat[i][j]);
            //cout<<distMat[i][j]<<"   ";
        }

        cout<<endl;
    }

    return 0;
}

/*
 
$ g++ test5.cpp
$ ./a.out
Enter the number of vertices 5
Enter the number of edges 9
Enter the src, dest and weight of each edge
1 2 3
1 3 8
1 5 -4
2 4 1
2 5 7
3 2 4
4 1 2
4 3 -5
5 4 6
The all pairs shortest distance matrix is 
            1     2     3     4     5
_____________________________________
    1 |     0     1    -3     2    -4
    2 |     3     0    -4     1    -1
    3 |     7     4     0     5     3
    4 |     2    -1    -5     0    -2
    5 |     8     5     1     6     0
 */
