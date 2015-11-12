#include <iostream>
#include<cctype>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;


int main()
{
    int n,x;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    vector<vector<int> > a(n,vector<int> (n));
    cout<<"enter the values "<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cin>>a[i][j];

    cout<<endl<<endl;

    cout<<"Original matrix is \n";
    for(int i=0;i<n;i++,cout<<endl)
        for(int j=0;j<n;j++)
        cout<<a[i][j]<<"  ";

    for(int i=0;i<(n/2);i++)
    {
        int j=n-i-1;
        for(int k=i;k<j;k++)
        {
            int x=a[j-k][i];
            int y=a[i][k];
            a[i][k]=x;
            x=y;

            y=a[k][j];
            a[k][j]=x;
            x=y;

            y=a[j][j-k];
            a[j][j-k]=x;
            x=y;

            a[j-k][i]=x;
        }
    }

    cout<<"\none time Rotated matrix is \n";
    for(int i=0;i<n;i++,cout<<endl)
        for(int j=0;j<n;j++)
        cout<<a[i][j]<<"  ";

    for(int i=0;i<(n/2);i++)
    {
        int j=n-i-1;
        for(int k=i;k<j;k++)
        {
            int x=a[j-k][i];
            int y=a[i][k];
            a[i][k]=x;
            x=y;

            y=a[k][j];
            a[k][j]=x;
            x=y;

            y=a[j][j-k];
            a[j][j-k]=x;
            x=y;

            a[j-k][i]=x;
        }
    }

    cout<<"\nTwo time Rotated matrix is \n";
    for(int i=0;i<n;i++,cout<<endl)
        for(int j=0;j<n;j++)
        cout<<a[i][j]<<"  ";

    for(int i=0;i<(n/2);i++)
    {
        int j=n-i-1;
        for(int k=i;k<j;k++)
        {
            int x=a[j-k][i];
            int y=a[i][k];
            a[i][k]=x;
            x=y;

            y=a[k][j];
            a[k][j]=x;
            x=y;

            y=a[j][j-k];
            a[j][j-k]=x;
            x=y;

            a[j-k][i]=x;
        }
    }

    cout<<"\nThree time Rotated matrix is \n";
    for(int i=0;i<n;i++,cout<<endl)
        for(int j=0;j<n;j++)
        cout<<a[i][j]<<"  ";

    for(int i=0;i<(n/2);i++)
    {
        int j=n-i-1;
        for(int k=i;k<j;k++)
        {
            int x=a[j-k][i];
            int y=a[i][k];
            a[i][k]=x;
            x=y;

            y=a[k][j];
            a[k][j]=x;
            x=y;

            y=a[j][j-k];
            a[j][j-k]=x;
            x=y;

            a[j-k][i]=x;
        }
    }

    cout<<"\nFour time Rotated matrix is \n";
    for(int i=0;i<n;i++,cout<<endl)
        for(int j=0;j<n;j++)
        cout<<a[i][j]<<"  ";


    return 0;
}
