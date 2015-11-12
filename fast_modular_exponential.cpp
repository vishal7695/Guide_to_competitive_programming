/*
C++ Program to Implement Modular Exponentiation Algorithm
*/

#include <iostream>
#define ll long long
using namespace std;

/*

Function to calculate modulus of (x raised to the power y)

we have to calculate a^b mod c.
we know, that in the last iteration, value of exponent will be 1. So, the if statement will definitely
run in the last iteration.
*/

ll modular_pow(ll base, ll exponent, int modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        // in every iteration, value of exponent is halved and value of base is squared
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}


int main()
{

    ll x, y;
    int mod;
    cout<<"Enter Base Value: ";
    cin>>x;

    cout<<"Enter Exponent: ";
    cin>>y;

    cout<<"Enter Modular Value: ";
    cin>>mod;

    cout<<modular_pow(x, y , mod);
    return 0;
}
