#include<iostream>
#include<cstdlib>
#define ll long long

using namespace std;


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

/*
ALGORITHM
Let p be the given number which we have to test for primality.
First we rewrite p-1 as (2^d)*s.
Now we pick some random a in range [1,n-1] and then
check whether a^s = 1 ( mod p ) or a^(s*(2^r)) = -1 ( mod p ).
If both of them fail, then p is definitely composite.
Otherwise p is probably prime.
We can choose another a and repeat the same test.
We can stop after some fixed number of iterations and claim that either p
is definitely composite, or it is probably prime.
*/

/* Miller-Rabin primality test, iteration signifies the accuracy of the test */
bool Miller(long long p,int iteration)
{

    if(p<2)
    {
		// 1 is not prime
        return false;
    }

    if(p!=2 && p%2==0)
    {
		// any even number is not prime
        return false;
    }

    long long s=p-1;
    int d=0;

    while(s%2==0)
    {
        d++;
        s/=2;
    }
    //here, we have successfully broken (p-1) into (2^d)*s

    for(int i=0;i<iteration;i++)
    {
        long long a=rand()%(p-2)+2;
        //next=1 means p is probably prime (stands for next iteration)
	int next=0;

        //mod = a^s % p
        long long mod=modular_pow(a,s,p);

        if(mod==1 ||mod==p-1)
        {
            //probably prime
            //next iteration
            next=1;
        }

        for(int j=0;j<d&&next==0;j++)
        {
            // a^((2^r)*s) = mod^(2^r)
            mod=modular_pow(mod,2,p);

            if(mod==1)
            {
                //composite
                return false;
            }

            else if(mod==p-1)
            {
                //probably prime
                //next iteration
                next=1;
            }

        }

        if(next==0)
            return false;

    }
    return true;
}

int main()
{
    int x,n;
   /*
    do
    {

    cout<<"Enter the number you want to check for prime  ";
    cin>>n;

    for(int i=1;i<=100;i++)
    {
        Miller(n,5)?cout<<"prime    ":cout<<"composite    ";
    }

    cout<<endl<<endl<<"do you want to continue (1) ";
    cin>>x;
    }while(x==1);
*/

    for(int i=2;i<=600;i++)
    {
        if(Miller(n,5))
            cout<<i<<"    ";
    }

    return 0;
}
