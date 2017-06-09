//powerset using bitset
#include<bits/stdc++.h>
using namespace std;

void bitset_add_one(bitset<10000> &bits)
{
    int i=0;
    while(bits[i]==1)
    {
        bits[i]=0; 
        i++;
    }

    bits[i]=1;
}

int main()
{
    int i;
    int n;

    //generate a power set for a given set(array)
    //create a bitset of maximum size(maximum size of numbers in the array
    
    bitset<10000> bits;

    cout<<"Enter the size of array ";
    cin>>n;

    vector<int> a(n);

    cout<<"Enter the elements of the array "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<"The powerset of the input array is "<<endl;

    //bits[n] will be equal to one only whenever you have traversed all the elements of the powerset
    while(bits[n]==0)
    {
        //display the elements of the powerset
        for(i=0;i<n;i++)
        {
            if(bits[i]==1)
            {
                cout<<a[i]<<" ";
            }

        }

        cout<<endl;
        bitset_add_one(bits);
    }

    return 0;
}
