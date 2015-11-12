//sieve of eratosthenes

#include<iostream>
#include<vector>
using namespace std;

void SieveOfEratosthenes(vector<bool> &primes)
{
    int n=primes.size();

    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        /* Following property is maintained in the below for loop
           primes[i] == true means i is prime
           primes[i] == false means i is not prime */

        int i,j;

        for (i=2; i*i<n; ++i)
        {
            if ( primes[i]==true )
            {
                //i is prime, now mark its multiples as non prime
                //markMultiples(primes, i, n);

                j=2;

                while(i*j<n)
                {
                    primes[i*j]=false;
                    j++;
                }

            }
        }
    }
}


int main()
{
    int n=10000001;    //we want to check prime numbers upto n-1
    vector<bool> primes(n,true);  //initially all the numbers are assumed to be prime
    primes[0]=primes[1]=false;    //0 and 1 are not prime

    SieveOfEratosthenes(primes);

    int i=0;
    while(i++<100)
    {
        if(primes[i])
            cout<<i<<"  ";
    }

    return 0;
}
