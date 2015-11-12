//segment tree for minimum range query

#include <iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<climits>
using namespace std;

//construction of segment tree for minimum range query
void constructST(vector<int> &a, vector<int> &segment, int low, int high, int root)
{
    if(low==high)
    {
        segment[root]=a[low];
        return ;
    }

    int mid=(low+high)/2;

    constructST(a, segment, low, mid, 2*root+1);
    constructST(a, segment, mid+1,high, 2*root+2);

    segment[root]=min(segment[2*root+1], segment[2*root+2]);

}

//low and high are the index of elements in the original array which are present under the root node
int rangeMinQuery(vector<int> &segment, int l, int r, int low, int high, int root)
{
    if(l<=low && r>=high)
    {
        //total overlap
        return segment[root];
    }

    if(l>high || r<low)
    {
        //no overlap
        //no solution from here
        return INT_MAX;
    }

    //partial overlap

    int mid=(low+high)/2;

    return min(rangeMinQuery(segment, l, r, low, mid, 2*root+1), rangeMinQuery(segment, l, r, mid+1, high, 2*root+2));
}

//update the value of elements in the range to be value
void updateQuery(vector<int> &segment, int l, int r, int value, int low, int high, int root)
{
    //no overlap
    if(low>r || high<l)
    {
        return ;
    }

    //leaf node
    if(low==high)
    {
        //leaf node
        segment[root]=value;
        return ;
    }

    int mid=(low+high)/2;

    updateQuery(segment,l,r,value,low, mid,2*root+1);
    updateQuery(segment,l,r,value,mid+1,high,2*root+2);

    segment[root]=min(segment[2*root+1],segment[2*root+2]);

}

int main()
{
    //freopen("in.in", "r", stdin);
    //freopen("out.out","w",stdout);

    int n,m,l,r,m2,j,value;
    //no. of elements in the array
    cin>>n;

    vector<int>a(n), segment(4*n);
    //length of segment tree is taken as 4*n

    for(int i=0;i<n;i++)
        cin>>a[i];

    constructST(a,segment,0,n-1,0);

    //m2 range sum queries
    cin>>m2;

    //m update queries
    cin>>m;

    for(int i=1;i<=m;i++)
    {

        for(j=1;j<=m2;j++)
        {
                //range for the query
                cin>>l>>r;
                cout<<l<<","<<r<<"- "<<rangeMinQuery(segment,l,r,0,n-1,0)<<endl;
        }

        //range for the update query
        cin>>l>>r;

        //value to update in the specified range
        cin>>value;

        cout<<endl<<"updation("<<l<<","<<r<<","<<value<<")"<<endl;

        updateQuery(segment,l,r,value,0,n-1,0);
    }

    return 0;
}


/*

input
9
-5 0 3 7 -2 5 8 -9 6
14 13

0 8
1 7
0 0
8 8
0 1
7 8
3 6
5 8
0 7
1 8
4 6
1 4
3 3
4 4

0 8 4

0 8
1 7
0 0
8 8
0 1
7 8
3 6
5 8
0 7
1 8
4 6
1 4
3 3
4 4

0 7 3

0 8
1 7
0 0
8 8
0 1
7 8
3 6
5 8
0 7
1 8
4 6
1 4
3 3
4 4

1 8 6

0 8
1 7
0 0
8 8
0 1
7 8
3 6
5 8
0 7
1 8
4 6
1 4
3 3
4 4

1 7 5

0 8
1 7
0 0
8 8
0 1
7 8
3 6
5 8
0 7
1 8
4 6
1 4
3 3
4 4

2 6 -4

0 8
1 7
0 0
8 8
0 1
7 8
3 6
5 8
0 7
1 8
4 6
1 4
3 3
4 4

0 0 -6

0 8
1 7
0 0
8 8
0 1
7 8
3 6
5 8
0 7
1 8
4 6
1 4
3 3
4 4

8 8 9

0 8
1 7
0 0
8 8
0 1
7 8
3 6
5 8
0 7
1 8
4 6
1 4
3 3
4 4

3 3 1

0 8
1 7
0 0
8 8
0 1
7 8
3 6
5 8
0 7
1 8
4 6
1 4
3 3
4 4

5 5 5

0 8
1 7
0 0
8 8
0 1
7 8
3 6
5 8
0 7
1 8
4 6
1 4
3 3
4 4

4 8 7

0 8
1 7
0 0
8 8
0 1
7 8
3 6
5 8
0 7
1 8
4 6
1 4
3 3
4 4

0 3 6

0 8
1 7
0 0
8 8
0 1
7 8
3 6
5 8
0 7
1 8
4 6
1 4
3 3
4 4

2 5 -5

0 8
1 7
0 0
8 8
0 1
7 8
3 6
5 8
0 7
1 8
4 6
1 4
3 3
4 4

5 5 3



correct output
0,8- -9
1,7- -9
0,0- -5
8,8- 6
0,1- -5
7,8- -9
3,6- -2
5,8- -9
0,7- -9
1,8- -9
4,6- -2
1,4- -2
3,3- 7
4,4- -2

updation(0,8,4)
0,8- 4
1,7- 4
0,0- 4
8,8- 4
0,1- 4
7,8- 4
3,6- 4
5,8- 4
0,7- 4
1,8- 4
4,6- 4
1,4- 4
3,3- 4
4,4- 4

updation(0,7,3)
0,8- 3
1,7- 3
0,0- 3
8,8- 4
0,1- 3
7,8- 3
3,6- 3
5,8- 3
0,7- 3
1,8- 3
4,6- 3
1,4- 3
3,3- 3
4,4- 3

updation(1,8,6)
0,8- 3
1,7- 6
0,0- 3
8,8- 6
0,1- 3
7,8- 6
3,6- 6
5,8- 6
0,7- 3
1,8- 6
4,6- 6
1,4- 6
3,3- 6
4,4- 6

updation(1,7,5)
0,8- 3
1,7- 5
0,0- 3
8,8- 6
0,1- 3
7,8- 5
3,6- 5
5,8- 5
0,7- 3
1,8- 5
4,6- 5
1,4- 5
3,3- 5
4,4- 5

updation(2,6,-4)
0,8- -4
1,7- -4
0,0- 3
8,8- 6
0,1- 3
7,8- 5
3,6- -4
5,8- -4
0,7- -4
1,8- -4
4,6- -4
1,4- -4
3,3- -4
4,4- -4

updation(0,0,-6)
0,8- -6
1,7- -4
0,0- -6
8,8- 6
0,1- -6
7,8- 5
3,6- -4
5,8- -4
0,7- -6
1,8- -4
4,6- -4
1,4- -4
3,3- -4
4,4- -4

updation(8,8,9)
0,8- -6
1,7- -4
0,0- -6
8,8- 9
0,1- -6
7,8- 5
3,6- -4
5,8- -4
0,7- -6
1,8- -4
4,6- -4
1,4- -4
3,3- -4
4,4- -4

updation(3,3,1)
0,8- -6
1,7- -4
0,0- -6
8,8- 9
0,1- -6
7,8- 5
3,6- -4
5,8- -4
0,7- -6
1,8- -4
4,6- -4
1,4- -4
3,3- 1
4,4- -4

updation(5,5,5)
0,8- -6
1,7- -4
0,0- -6
8,8- 9
0,1- -6
7,8- 5
3,6- -4
5,8- -4
0,7- -6
1,8- -4
4,6- -4
1,4- -4
3,3- 1
4,4- -4

updation(4,8,7)
0,8- -6
1,7- -4
0,0- -6
8,8- 7
0,1- -6
7,8- 7
3,6- 1
5,8- 7
0,7- -6
1,8- -4
4,6- 7
1,4- -4
3,3- 1
4,4- 7

updation(0,3,6)
0,8- 6
1,7- 6
0,0- 6
8,8- 7
0,1- 6
7,8- 7
3,6- 6
5,8- 7
0,7- 6
1,8- 6
4,6- 7
1,4- 6
3,3- 6
4,4- 7

updation(2,5,-5)
0,8- -5
1,7- -5
0,0- 6
8,8- 7
0,1- 6
7,8- 7
3,6- -5
5,8- -5
0,7- -5
1,8- -5
4,6- -5
1,4- -5
3,3- -5
4,4- -5

updation(5,5,3)



*/
