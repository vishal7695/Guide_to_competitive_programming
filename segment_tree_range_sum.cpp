//segment tree for sum of range query

#include<iostream>
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

    segment[root]=segment[2*root+1] + segment[2*root+2];

}

//low and high are the index of elements in the original array which are present under the root node
int rangeSumQuery(vector<int> &segment, int l, int r, int low, int high, int root)
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
        return 0;
    }

    //partial overlap

    int mid=(low+high)/2;

    return rangeSumQuery(segment, l, r, low, mid, 2*root+1) + rangeSumQuery(segment, l, r, mid+1, high, 2*root+2);
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

    segment[root]=segment[2*root+1]+segment[2*root+2];

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
                cout<<l<<","<<r<<"- "<<rangeSumQuery(segment,l,r,0,n-1,0)<<endl;
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
0,8- 13
1,7- 12
0,0- -5
8,8- 6
0,1- -5
7,8- -3
3,6- 18
5,8- 10
0,7- 7
1,8- 18
4,6- 11
1,4- 8
3,3- 7
4,4- -2

updation(0,8,4)
0,8- 36
1,7- 28
0,0- 4
8,8- 4
0,1- 8
7,8- 8
3,6- 16
5,8- 16
0,7- 32
1,8- 32
4,6- 12
1,4- 16
3,3- 4
4,4- 4

updation(0,7,3)
0,8- 28
1,7- 21
0,0- 3
8,8- 4
0,1- 6
7,8- 7
3,6- 12
5,8- 13
0,7- 24
1,8- 25
4,6- 9
1,4- 12
3,3- 3
4,4- 3

updation(1,8,6)
0,8- 51
1,7- 42
0,0- 3
8,8- 6
0,1- 9
7,8- 12
3,6- 24
5,8- 24
0,7- 45
1,8- 48
4,6- 18
1,4- 24
3,3- 6
4,4- 6

updation(1,7,5)
0,8- 44
1,7- 35
0,0- 3
8,8- 6
0,1- 8
7,8- 11
3,6- 20
5,8- 21
0,7- 38
1,8- 41
4,6- 15
1,4- 20
3,3- 5
4,4- 5

updation(2,6,-4)
0,8- -1
1,7- -10
0,0- 3
8,8- 6
0,1- 8
7,8- 11
3,6- -16
5,8- 3
0,7- -7
1,8- -4
4,6- -12
1,4- -7
3,3- -4
4,4- -4

updation(0,0,-6)
0,8- -10
1,7- -10
0,0- -6
8,8- 6
0,1- -1
7,8- 11
3,6- -16
5,8- 3
0,7- -16
1,8- -4
4,6- -12
1,4- -7
3,3- -4
4,4- -4

updation(8,8,9)
0,8- -7
1,7- -10
0,0- -6
8,8- 9
0,1- -1
7,8- 14
3,6- -16
5,8- 6
0,7- -16
1,8- -1
4,6- -12
1,4- -7
3,3- -4
4,4- -4

updation(3,3,1)
0,8- -2
1,7- -5
0,0- -6
8,8- 9
0,1- -1
7,8- 14
3,6- -11
5,8- 6
0,7- -11
1,8- 4
4,6- -12
1,4- -2
3,3- 1
4,4- -4

updation(5,5,5)
0,8- 7
1,7- 4
0,0- -6
8,8- 9
0,1- -1
7,8- 14
3,6- -2
5,8- 15
0,7- -2
1,8- 13
4,6- -3
1,4- -2
3,3- 1
4,4- -4

updation(4,8,7)
0,8- 31
1,7- 30
0,0- -6
8,8- 7
0,1- -1
7,8- 14
3,6- 22
5,8- 28
0,7- 24
1,8- 37
4,6- 21
1,4- 9
3,3- 1
4,4- 7

updation(0,3,6)
0,8- 59
1,7- 46
0,0- 6
8,8- 7
0,1- 12
7,8- 14
3,6- 27
5,8- 28
0,7- 52
1,8- 53
4,6- 21
1,4- 25
3,3- 6
4,4- 7

updation(2,5,-5)
0,8- 13
1,7- 0
0,0- 6
8,8- 7
0,1- 12
7,8- 14
3,6- -8
5,8- 16
0,7- 6
1,8- 7
4,6- -3
1,4- -9
3,3- -5
4,4- -5

updation(5,5,3)


*/
