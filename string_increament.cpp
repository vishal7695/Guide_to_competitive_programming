//The string stores a very large number
//This program increamens the string by 1


#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

void string_increament(string& str)
{
    bool flag9=1;

    for(int i=0;i<str.length() && flag9==1;i++)
    {
        if(str[i]!='9')
        {
            flag9=0;
        }
    }


    if(flag9)
    {

        //all digits are 9

        str[0]='1';

        int i;

        for(i=1; i<str.length();i++)
        {
            str[i]='0';
        }

        str.append("0");
    }

    else
    {
        int n=str.length()-1;

        int x=1;

        while(x)
        {
            if(str[n]=='9')
            {
                str[n]='0';
                n--;
            }

            else
            {
                str[n]++;
                x=0;
            }

        }

    }
}

int main()
{
    string x;

    getline(cin,x);  //input an integer here

    //call increament function

    string_increament(x);

    cout<<"\n\nlength is "<<x.length()<<"\nstring is "<<x;

    cout<<"\n\nnew length is "<<x.length()<<"\nnew string is "<<x;

    return 0;
}
