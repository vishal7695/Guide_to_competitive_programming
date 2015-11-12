//solution for problem light switching spoj using segment trees
//problem link http://www.spoj.com/problems/LITE/
//given a range, toggle all the lights in the range or count the no. of lights turned on in this range


#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <set>
#include <utility>


using namespace std;
/*========================================Templates=============================================*/
// datatypes
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;


#define in(a) scanf("%d",&a)
#define out(a) printf("%d",a)

#define pb push_back
#define len length()
#define sz size()

#define gc getchar_unlocked
#define pc putchar_unlocked
#define pn printf("\n")
#define ps printf(" ")

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repn(i,n) rep(i,0,n)

#define all(a) a.begin(),a.end()
#define repv(i,a) rep(i,all(a))
#define sortv(a) sort(all(a))
#define W(a) while(a--)

/*======================================Templates Ends========================*/
/* Main Code Starts from here */

void updateQuery(vi &st, vi &lazy, int l, int r, int low, int high, int root)
{
    int n=high-low+1;
    //getchar();

    //cout<<"uq l="<<l<<" r="<<r<<" low="<<low<<" high="<<high<<" root="<<root<<" st[root]="<<st[root]<<endl;

    //check updation status
    if(lazy[root]%2!=0)
    {
        n=high-low+1;
        st[root]=n-st[root];
        lazy[root]=0;

        if(low!=high)
        {
            //mark children for updation
            lazy[2*root+1]=(lazy[2*root+1]+1)%2;
            lazy[2*root+2]=(lazy[2*root+2]+1)%2;
        }
    }

    //if no overlap at all
    if(low>r || high<l)
        return ;



    //total overlap
    if(l<=low && r>=high)
    {
        //update the value here
        st[root]=n-st[root];
        //cout<<endl<<"st[root]="<<st[root]<<endl;

        if(low!=high)
        {
            lazy[2*root+1]=(lazy[2*root+1]+1)%2;
            lazy[2*root+2]=(lazy[2*root+2]+1)%2;
        }

        return ;
    }

    int mid=(low+high)/2;

    updateQuery(st,lazy, l,r, low, mid, 2*root+1);
    updateQuery(st,lazy, l,r, mid+1, high, 2*root+2);

    st[root]=st[2*root+1]+st[2*root+2];

}

int rangeQuery(vi &st, vi &lazy, int l, int r, int low, int high, int root)
{
    //no overlap
    if(low>r || high<l)
        return 0;

    //check updation status
    if(lazy[root]%2!=0)
    {
        int n=high-low+1;
        st[root]=n-st[root];
        lazy[root]=0;

        if(low!=high)
        {
            //mark children for updation
            lazy[2*root+1]=(lazy[2*root+1]+1)%2;
            lazy[2*root+2]=(lazy[2*root+2]+1)%2;
        }
    }


    //total overlap
    if(l<=low && r>=high)
        return st[root];

    int mid=(low+high)/2;

    int x=rangeQuery(st,lazy,l,r,low, mid,2*root+1);
    int y=rangeQuery(st,lazy,l,r,mid+1, high, 2*root+2);

    return x+y;
}

int main()
{
    int i,j,k,x,y,z,l,r;
    int t,n,m;

    in(n),in(m);
    vector<int> st(4*n,0),lazy(4*n,0);

    W(m)
    {
        in(x),in(l),in(r);

        if(x==0)
        {
            updateQuery(st,lazy,l-1,r-1,0,n-1,0);
        }

        else
        {
            out(rangeQuery(st,lazy,l-1,r-1,0,n-1,0));
            pn;
        }
/*
        cout<<endl<<"segment tree"<<endl;
        repn(i,4*n)
        cout<<"i="<<i<<" value="<<st[i]<<endl;

        cout<<endl<<"lazy tree"<<endl;
        repn(i,4*n)
        cout<<"i="<<i<<" value="<<lazy[i]<<endl; */
    }

    return 0;
}

