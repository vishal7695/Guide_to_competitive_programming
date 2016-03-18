#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int getParent(int j)
{
    return j-(j & (-j));
}

int getNext(int j)
{
    return j+(j & (-j));
}

void updateValue(vi &bit, int i, int x, int n)
{
    int j;

    //index in bit 
    j=i+1;

    //add x to all the values
    
    while(j<(n+1))
    {
        bit[j]+=x;
        j=getNext(j);
    }
}

int get(vi &bit,int i)
{
    int j=i+1;

    int sum=0;

    while(j>0)
    {
        sum+=bit[j];
        j=getParent(j);
    }

    return sum;
}

int main()
{
    int n,m;
    int x;
    int q;

    cout<<"Enter the value of number of nodes in the array ";
    cin>>n;

    vi bit(n+1,0);

    cout<<"Enter the values of the array "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;

        updateValue(bit,i,x,n);
    }

   
    cout<<"Enter the number of queries for prefix sum upto an index ";
    cin>>q;
   
    for(int i=0;i<q;i++)
    {
        cout<<"Enter the index upto which you want the prefix sum ";
        cin>>m;
        cout<<"Prefix sum upto index "<<m<<" of the array is "<<get(bit,m)<<endl;
    }

    return 0;
}

