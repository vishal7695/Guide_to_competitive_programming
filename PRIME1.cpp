/*
PROBLEM-Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to
generate all prime numbers between two given numbers
*/

/*
CONCEPT-The idea behind solution here is to generate all the prime numbers
that could be factors of numbers up to the maximum endpoint 1 billion. That square root happens
to be around 32000. Using this array, do a bounded Sieve of Eratosthenes only in the range
requested.
*/

#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
    vector<int>primes(4000);       //to store all prime numbers upto 32000
    int numprimes = 0;      //how many prime nums are there upto 32000

    primes[numprimes++] = 2;

    for (int i = 3; i <= 32000; i+=2)    //32000 is the root of 10^9
    {
        //checking whether i is prime or not
        //if i is prime, it will be added to the primes array and numprimes will be incremented

        bool isprime = true;  //initially considering i to be prime

        int cap = sqrt(i)+1;

        for (int j = 0; j < numprimes; j++)
        {
            if (primes[j] >= cap)
                break;

            if (i % primes[j] == 0)
            {
                isprime = false;
                break;
            }
        }

        if (isprime)
            primes[numprimes++] = i;
    }

    int T,N,M;
    scanf("%d",&T);

    for (int t = 0; t < T; t++)
    {
        if (t)
            printf("\n");

        scanf("%d %d",&M,&N);

        if (M < 2) M = 2;

        int cap = sqrt(N) + 1;

        vector<bool> isprime(100001,true);       //a new vector will be created for every test case

        //now, applying sieve of eratosthenes
        for (int i = 0; i < numprimes; i++)
        {
            int p = primes[i];

            if(p >= cap)
                break;

            int start;   //start will store first non prime number whose factor is p (prime[i])

            if (p >= M)
                start = p*2;

            else
                start = M + ((p - M % p) % p);

            for (int j = start; j <= N; j += p)   //mark all multiples of prime[i] as non prime in the given range
            {
                isprime[j - M] = false;
            }

        }

        //displaying now
        int start = (M % 2)?M:M+1;

        if (M == 2)
        {
            printf("2\n");
        }

        for (int i = start; i <= N; i+=2) //skipping all even numbers as they are not prime
        {                                 //(except two which is separately displayed if in the desired range)
            if (isprime[i-M])             //isprime[i-M] will store the prime status of num i
                printf("%d\n",i);
        }
    }

    return 0;
}


