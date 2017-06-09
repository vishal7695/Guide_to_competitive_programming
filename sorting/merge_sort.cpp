//merge_sort
#include<iostream>

using namespace std;


void Merge(int a[],int left,int mid,int right)
{
    int i,j,k,temp[15],length=right-left+1;
    i=left;
    j=mid+1;
    k=0;

    while(i<=mid&&j<=right)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            k++;
            i++;
        }

        else if(a[i]>a[j])
        {
            temp[k]=a[j];
            k++;
            j++;
        }

        else
        {
            temp[k]=a[i];
            k++;
            i++;

            temp[k]=a[j];
            k++;
            j++;
        }
    }

    while(i<=mid)
    {
        temp[k]=a[i];
        k++;
        i++;
    }

    while(j<=right)
    {
        temp[k]=a[j];
        k++;
        j++;
    }

    for(i=0,j=left;i<length;i++)
    {
        a[left++]=temp[i];
    }
}

void merge_sort(int a[], int left,int right)
{
    if(right>left)
    {
        int mid=(left+right)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);

        Merge(a,left,mid,right);
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

    merge_sort(a,0,n-1);

    cout<<"The sorted array is "<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}

