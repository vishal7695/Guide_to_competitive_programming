//quick_sort
#include<iostream>

using namespace std;

int part(int a[],int low,int high)
{
    //considering the left most item as pivot

    int left,right,pivot=a[low];
    left=low;
    right=high;

    while(left<right)
    {
        //increase left till a[left]<=pivot
        while(a[left]<=pivot)
        {
            left++;
        }

        //increase right till a[right]>pivot
        while(a[right]>pivot)
        {
            right--;
        }

        if(left<right)
        {
            a[left]=a[left]+a[right];
            a[right]=a[left]-a[right];
            a[left]=a[left]-a[right];
        }
    }

    //right is final position for the pivot

    a[low]=a[right];
    a[right]=pivot;

    //now, return the position of the pivot

    return right;
}

void quick_sort(int a[], int low, int high)
{
    int pivot;

    if(high>low)
    {
        pivot=part(a,low,high);

        quick_sort(a,low,pivot-1);
        quick_sort(a,pivot+1,high);
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

    quick_sort(a,0,n-1);

    cout<<"The sorted array is "<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
