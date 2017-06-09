//compile this program using c++ 11
//g++ -std=c++11 filename.cpp

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;

    string str;
    cout<<"Enter a binary string ";
    cin>>str;

    n=2;
    while(n<=10)
    {
        x=stoi(str,nullptr,n);

        cout<<"for base="<<n<<" value= "<<x<<endl;

        n++;
    }

    return 0;
}
