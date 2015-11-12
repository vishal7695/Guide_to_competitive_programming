//solution for problem gss1 spoj using segment trees
//problem link http://www.spoj.com/problems/GSS1/
//You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows: 
//Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }. 

#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

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
typedef vector<pair<int, int> > vii;
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


struct st
{
    int value, left, right,sum;
};

st nll;

void constructST(vector<int> &input,vector<st> &segment,int low, int high, int root)
{
    int j;
    //cout<<endl<<"cst("<<low<<","<<high<<","<<root<<")  ";

    if(low==high)
    {
        //cout<<input[low];

        segment[root].value=input[low];
        segment[root].left=segment[root].right=segment[root].sum=input[low];
        return ;
    }

    int mid=(low+high)/2;

    constructST(input,segment,low,mid,2*root+1);
    constructST(input,segment,mid+1,high,2*root+2);
/*
    int sm1=input[mid],sm2=input[mid+1];
    int brdr1=sm1, brdr2=sm2;

    //calculate brdr1,brdr2
    for(j=mid-1;j>=low;j--)
    {
        sm1+=input[j];
        if(sm1>brdr1)
            brdr1=sm1;
    }

    for(j=mid+2;j<=high;j++)
    {
        sm2+=input[j];
        if(sm2>brdr2)
            brdr2=sm2;
    }
*/
    segment[root].sum=segment[2*root+1].sum+segment[2*root+2].sum;
    segment[root].left=max(segment[2*root+1].left,segment[2*root+1].sum+segment[2*root+2].left);
    segment[root].right=max(segment[2*root+2].right,segment[2*root+2].sum+segment[2*root+1].right);

    segment[root].value=max(max(segment[2*root+1].value,segment[2*root+2].value),segment[2*root+1].right+segment[2*root+2].left);
}

st query(vector<st> &segment,vector<int> &input, int l, int r, int low, int high, int root)
{
    //cout<<endl<<"query("<<l<<","<<r<<","<<low<<","<<high<<","<<root<<")  ";
    int j;

    //no overlap
    if(low>r || high<l)
    {
      //  cout<<"-infinity";
        return nll;
    }

    //total overlap
    if(low>=l && high<=r)
    {
        //cout<<segment[root].sum<<","<<segment[root].left<<","<<segment[root].right<<","<<segment[root].value<<" total\n";
        return segment[root];
    }

    int mid=(low+high)/2;

    st q1=query(segment,input,l,r,low,mid,2*root+1);
    st q2=query(segment,input,l,r,mid+1,high,2*root+2);

    if(q1.value==INT_MIN )
    {
        //cout<<q2.sum<<","<<q2.left<<","<<q2.right<<","<<q2.value<<"  q2"<<endl;
        return q2;
    }

    if(q2.value==INT_MIN )
    {
        //cout<<q1.sum<<","<<q1.left<<","<<q1.right<<","<<q1.value<<"  q1"<<endl;
        return q1;
    }

    st x;
    x.sum=q1.sum+q2.sum;
    x.left=max(q1.left,q1.sum+q2.left);
    x.right=max(q2.right,q2.sum+q1.right);

    x.value=max(max(q1.value,q2.value),q1.right+q2.left);

    //cout<<x.sum<<","<<x.left<<","<<x.right<<","<<x.value<<endl;

    return x;
}

int main()
{
    //freopen("in.in","r",stdin);
    int j,k,l,m,n,x,y;
    nll.value=nll.right=nll.left=nll.sum=INT_MIN;
    in(n);
    vi input(n);
    vector<st> segment(4*n);

    repn(i,n)
    {
        in(input[i]);
    }

    constructST(input,segment,0,n-1,0);
/*
    cout<<endl<<"display segment tree"<<endl;
    for(j=0;j<=2*n-1;j++)
    {
        cout<<j<<" "<<segment[j]<<endl;
    }

    pn,pn;
*/
    in(m);

    W(m)
    {
        in(x);
        in(y);
        //x=query(segment,input,x-1,y-1,0,n-1,0);
        //cout<<endl<<"result= "<<x;
        out(query(segment,input,x-1,y-1,0,n-1,0).value);
        pn;
    }
    return 0;
}

