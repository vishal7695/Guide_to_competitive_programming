//exponentiation by squaring

#include<bits/stdc++.h>
using namespace std;

//exponentiation by squaring
int power(int x, int n) 
{
    // our base case: x^0 = 1
    if (n == 0)
        return 1;
 
    // if n is odd
    if (n % 2 != 0)
        return x * power(x, n - 1);
 
    // if n is even, calculate x^(n / 2)
    int sqrt = power(x, n / 2);
 
    // and return it squared
    return sqrt * sqrt;
}

int main()
{
    int n,x;

    do
    {
        cout<<"Enter the base and exponent ( base=0 to exit ) ";
        cin>>x>>n;

        //x^n
        cout<<x<<"^"<<n<<"= "<<power(x,n)<<endl;

    }while(x!=0);

    return 0;
}
