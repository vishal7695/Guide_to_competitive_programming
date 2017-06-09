#include<iostream>

using namespace std;


void shell_sort(int a[], int n)
{
   int i,j,x,gap;
   
   for(gap=n/2;gap>0;gap/=2)
   {

       for(i=gap;i<n;i++)
       {
           x=a[i];

           for(j=i-gap;j>=0&&a[j]>x;j=j-gap)
           {
               a[j+gap]=a[j];
           }

           a[j+gap]=x;
       }

   }
}

int main()
{
    int n;
    cout<<"enter the no. of elements you want to insert";
    cin>>n;

    int a[15];

    cout<<"enter the values";

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    shell_sort(a,n);

    cout<<"The sorted array is "<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
