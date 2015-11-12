//check whether a number is prime or not

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


int main()
{
    int x,i,j,k,root;
    bool isPrime;
    cout<<"enter a number to test for prime (upto 10000 only) ";
    cin>>x;
    vector<int> primes(50);
    int prime_count=0;

    root=sqrt(x)+1;

    //now you should have all the prime numbers less than root stored in an array
    //maximum permissible value of root is 100 (x<=10000)

    //generating prime numbers upto root
    for(i=3;i<root;i++)
    {
        int rt=sqrt(i)+1;
        isPrime=true;

        for(j=0;primes[j]<rt && j<prime_count;i++)
        {
            if(i%primes[j]==0)
            {
                isPrime=false;
                break;
            }

        }

        if(isPrime)
        {
            primes[prime_count++]=i;
        }
    }


    for(i=0;i<prime_count;i++)
    {
        isPrime=true;
        if(x%primes[i]==0)
        {
            isPrime=false;
            cout<<"not prime";
            break;
        }

    }

    if(isPrime)
        cout<<"prime";



    return 0;

}
