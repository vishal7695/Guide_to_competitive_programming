//nth fibonacci number
//matrix exponentiation by squaring

#include <bits/stdc++.h>
using namespace std;

//multiply matrix a and b. 
//put result in c
void matmult(long long  a[][2],long long  b[][2],long long c[][2],long long  M)
{
    int i,j,k;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c[i][j]=0;
            for(k=0;k<2;k++)
            {
                c[i][j]+=(a[i][k]*b[k][j]);
                c[i][j]=c[i][j]%M;
            }
        }
    }
 
}


//find ( Z^n )% M and return result in ans
void matpow(long long Z[][2],int n,long long ans[][2],long long M)
{
    long long temp[2][2];
    
    //assign ans= the identity matrix
    ans[0][0]=1;
    ans[1][0]=0;
    ans[0][1]=0;
    ans[1][1]=1;

    int i,j;
   
    while(n>0)
    {
        //if n is odd
        if(n&1)
        {
            matmult(ans,Z,temp,M);

            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                    ans[i][j]=temp[i][j];
        }
   
        matmult(Z,Z,temp,M);

        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                Z[i][j]=temp[i][j];
 
        n=n/2;
    }

}

//exponentiation by squaring for numbers
long power(long num, long pow)
{
    if (pow == 0) 
        return 1;

    if (pow % 2 == 0)
        return power(num*num, pow / 2);
    
    else
        return power(num, pow - 1) * num;
}

long long findFibonacci(long long n,long long M)
{
    long long fib;

    if(n<=1)
        return n;

    //n greater than 2
    
    long long int Z[2][2]={{1,1},{1,0}},result[2][2];
    //modify matrix a[][] for other recurrence relations
 
    //F(n+1)=Z^n
    //F(n)=Z^(n-1)
    matpow(Z,n-1,result,M);
   
    fib=result[0][0];
         
    return fib;
}

int main()
{
    int n;
    int MOD=INT_MAX;

    do
    {
        cout<<"Enter the order of fibonacci number you want ( 0 to exit ) ";
        cin>>n;
       
        cout<<n<<"th fibonacci number is ";
        cout<<findFibonacci(n,MOD)<<endl;

    }while(n!=0);

    return 0;
}
