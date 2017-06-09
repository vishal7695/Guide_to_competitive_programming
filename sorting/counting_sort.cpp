#include<iostream>

using namespace std;


void count_sort(int arr[], int n)
{
	int i, j, k;
	int idx = 0;
	int min, max;

	min = max = arr[0];

	for(i = 1; i < n; i++)
    {
		min = (arr[i] < min) ? arr[i] : min;
		max = (arr[i] > max) ? arr[i] : max;
	}

	k = max - min + 1;

	/* creates k buckets */
	int *B = new int [k];

	// initialize to 0
	for(i = 0; i < k; i++)
        B[i] = 0;

	for(i = 0; i < n; i++)
        B[arr[i] - min]++;

	for(i = min; i <= max; i++)
		for(j = 0; j < B[i - min]; j++)
            arr[idx++] = i;

	delete [] B;
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

    count_sort(a,n);

    cout<<"The sorted array is "<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
