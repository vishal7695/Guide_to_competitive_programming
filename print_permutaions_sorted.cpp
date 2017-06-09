#include<bits/stdc++.h>
using namespace std;

void print_next(string str, int l, int &count)
{

    if(l==str.length()-1)
    {
        count=(count+1);
        cout<<str<<" "<<count<<endl;

        return ;
    }
    
    for(int i=l; i<str.length();i++)
    {
        char ch=str[i];
        for(int j=i-1;j>=l;j--)
        {
            str[j+1]=str[j];
        }

        str[l]=ch;

        print_next(str,l+1,count);
        
        ch=str[l];
        
        for(int j=l+1;j<=i;j++)
        {
            str[j-1]=str[j];
        }

        str[i]=ch;
    }
}

int main()
{
    string str;
    int count=0;

    do
    {
        cin>>str;
        sort(str.begin(),str.end());
        print_next(str,0,count);

        cout<<endl;

    }while(str!="");

    return 0;
}
