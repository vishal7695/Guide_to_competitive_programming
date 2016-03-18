//print all distinct permutaions of a string

#include<bits/stdc++.h>
using namespace std;

void print_distinct_permutations(string str, int l, int h)
{
    static int x=0;

    if(l==h)
        cout<<++x<<" "<<str<<endl;

    map<char, bool> mp;

    for(int i=l; i<=h;i++)
    {
        //find the status of this character
        //if this character is already covered 
        //skip this 
        if(mp.find(str[i])==mp.end())
        {
            mp[str[i]]=true;
        
            swap(str[i],str[l]);
            print_distinct_permutations(str,l+1,h);
            swap(str[i],str[l]);
        }
    }
}

int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin, str);

    print_distinct_permutations(str,0,str.length()-1);

    return 0;
}

