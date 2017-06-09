//bubble_sort_improved
#include<iostream>

using namespace std;

void bubble_sort(int a[], int n)
{
    int i,j,swapped=1;

	// for n-1 passes
    for(i=n-1;i>0&&swapped;i--)
    {
        swapped=0;
		//consecutive elements will be compared
        for(j=0;j<i;j++)
        {
			//swap if (j+1)th element is greater than jth element
            if(a[j]>a[j+1])
            {
                swapped=1;
				//swap
                a[j]=a[j]+a[j+1];
                a[j+1]=a[j]-a[j+1];
                a[j]=a[j]-a[j+1];
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

    bubble_sort(a,n);

    cout<<"The sorted array is "<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
