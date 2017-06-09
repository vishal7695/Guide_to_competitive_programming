//fast combination

#include<bits/stdc++.h>
using namespace std;

long long int combination(int n , int r)
{
    if(n<r)
        return 0;

    if(n==r)
        return 1;

    if(r==0)
        return 1;

    if(r==1 || r==n-1)
        return n;
    
    long long int d=1;
    
    int i=1;

    if(r > n/2)
        r = n-r;
    
    int x=n,y=1;
    
    while(i<=r)
    {
        d *= x;
        d /= y;
        y++;
        x--;
        i++;
    }

    return d;
}

int main()
{
    //freopen("in2.in","r",stdin);
    //freopen("out2.out","w",stdout);

    int num,n=1,r;
    
    while(n!=0)
    {
        cout<<"Caclulating C(n,r)"<<endl;
        cout<<"Enter the value of n and r (0 to exit)"<<endl;
        cin>>n>>r;
        num=combination(n,r);
        cout<<"No. of combinations are "<<num<<endl<<endl;
    }

    return 0;
}
