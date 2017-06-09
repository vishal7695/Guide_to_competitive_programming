//insertion sort
#include<iostream>

using namespace std;


void ins_sort(int a[], int n)
{
   int i,j,x,k;
   
   //ith element will be put into its proper place
   //assuming all elements before i all in sorted order
   for(i=1;i<n;i++)
   {
	   //this value needs to be put into its correct place
       x=a[i];

	   //elements will be shifted to the right until the loop condition fails
       for(j=i-1;j>=0&&a[j]>x;j--)
       {
		   //right shift	
           a[j+1]=a[j];
       }
	   
	   //and this is the correct place
       a[j+1]=x;
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

    ins_sort(a,n);

    cout<<"The sorted array is "<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
