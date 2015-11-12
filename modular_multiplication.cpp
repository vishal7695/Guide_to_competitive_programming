/*

 * C++ Program to Implement modular multiplication

 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#define ll long long
using namespace std;

/*
 * calculates (a * b) % c taking into account that a * b might overflow
*/

/*
 * Logic

   if b=3,
    result=a*2+a

   if b=4,
    result=a*2*2

   if b=17,
    result=a*2*2*2*2+a
 */

ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0,y = a % mod;

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }

        y = (y * 2) % mod;
        b /= 2;
    }

    return x % mod;
}


//Main

int main()

{

    cout<<"enter a :";
    ll a,b,c;
    cin>>a;
    cout<<"enter b :";
    cin>>b;
    cout<<"enter the value of modulo ";
    cin>>c;
    cout<<endl<<"("<<a<<"*"<<b<<") mod "<<c<<" ="<<mulmod(a,b,c);
    return 0;

}
