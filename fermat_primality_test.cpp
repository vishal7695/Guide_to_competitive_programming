#include<iostream>
#include<cstdlib>

using namespace std;

//The more iterations we do, the higher is the probability that our result is correct.
/*
More iterations of the function will result in higher accuracy, but will take more time.
You can choose the number of iterations depending upon the application.

Though Fermat is highly accurate in practice, there are certain composite numbers p known as
Carmichael numbers.

A Carmichael number is an odd composite number n which satisfies Fermat's little theorem
    a^(n-1) = 1 (mod n) 	for every choice of a satisfying GCD(a,n)=1 (i.e., a and n are relatively prime)
with 1<a<n.
and in that case, the Fermat’s test will return a wrong result with very high probability.

*/

/* This function calculates (a^b)%c */
int modular_exp(int a,int b,int c)
{
    long long result=1,base=a,exp=b; // long long is taken to avoid overflow of intermediate result
    while(exp > 0)
        {
            if(exp%2 == 1)
            {
                result=(result*base)%c;
            }

            base = (base*base)%c; // squaring the base
            exp /= 2;
        }

    return result%c;
}

/* Fermat's test for checking primality, the more iterations the more is accuracy */
bool Fermat(long long p,int iterations)
{
    if(p == 1)
    {
        // 1 isn't prime
        return false;
    }

    for(int i=0;i<iterations;i++)
    {
        // choose a random integer between 1 and p-1 ( inclusive )
        long long a = rand()%(p-1)+1;

        // modulo is the function we developed above for modular exponentiation.
        if(modular_exp(a,p-1,p) != 1)
        {
            return false; /* p is definitely composite */
        }
    }

    return true; /* p is probably prime */
}

int main()
{
    int x,n;
    do
    {

    cout<<"Enter the number you want to check for prime  ";
    cin>>n;

    Fermat(n,5)?cout<<"prime":cout<<"composite";


    for(int i=1;i<=100;i++)
    {
        Fermat(n,5)?cout<<"prime    ":cout<<"composite    ";
    }

    cout<<endl<<endl<<"do you want to continue (1) ";
    cin>>x;
    }while(x==1);

    return 0;
}
