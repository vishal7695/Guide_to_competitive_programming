#include<iostream>

using namespace std;

void selection_sort(int a[], int n)
{
    int i,j;

	// ith element will be compared to jth element 
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
			//swap if ith element is greater than jth element
            if(a[i]>a[j])
            {
                a[j]=a[j]+a[i];
                a[i]=a[j]-a[i];
                a[j]=a[j]-a[i];
            }
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

    selection_sort(a,n);

    cout<<"The sorted array is "<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
