#include<bits/stdc++.h>
using namespace std;

void print_permutations(string str, int l, int h)
{
    //cout<<"call "<<str<<" "<<l<<" "<<h<<endl;

    if(l==h)
        cout<<str<<endl;

    for(int i=l; i<=h;i++)
    {
        //swap str[i] and str[l]

	swap(str[i],str[l]);
        print_permutations(str,l+1,h);
        swap(str[i],str[l]);
    }
}

int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin, str);

    print_permutations(str,0,str.length()-1);

    return 0;
}

