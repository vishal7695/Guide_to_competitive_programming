#include<iostream>

using namespace std;

void radix_sort(int a[],int n)
{
    //nop(no. of passes) - no. of digits in the largest element max
	int nop=0,i,j,k,l,b[20],divisor=1,max;
	int temp;

	max=a[0];

	for(i = 1; i < n; i++)
    {
		max = (a[i] > max) ? a[i] : max;
	}

    while(max!=0)
    {
        max/=10;
        nop++;
    }

    for(int pass=1;pass<=nop;pass++)
    {
        for(j=0;j<n;j++)
        {
            b[j]=a[j];
        }

        j=0;

        for(k=0;k<=9&&j!=n;k++)
        {
            for(l=0;l<n&&j!=n;l++)
            {
                temp=b[l];
                temp/=divisor;
                if(temp%10==k)
                a[j++]=b[l];
            }

        }

        divisor*=10;

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

    radix_sort(a,n);

    cout<<"The sorted array is "<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
