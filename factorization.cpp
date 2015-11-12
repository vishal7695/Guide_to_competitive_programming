// Program to print all prime factors
# include <cstdio>
# include <cmath>
#include<iostream>
using namespace std;

// A function to print all prime factors of a given number n
void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            printf("%d ", i);

	    //notice that we are constantly dividing the value of n
            n = n/i;
        }
    }

    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
        printf ("%d ", n);
}

/* Driver program to test above function */
int main()
{
    cout<<"Enter the number whose factors you want  ";
    int n ;
    cin>>n;
    primeFactors(n);
    return 0;
}
