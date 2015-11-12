
/*
MINIMIZING NUMBER OF COINS IN COIN CHANGE PROBLEM
RECURSIVE SOLUTION

Given a value N, if we want to make change for N cents, and we have infinite supply of each of
S = { S1, S2, .. , Sm} valued coins, WHAT IS THE LEAST NO. OF COINS THAT WE NEED TO MAKE THE CHANGE?

*/

#include<cstdio>
#include<iostream>
#include<climits>

using namespace std;

int min_sol=INT_MAX;

// Returns the count of ways we can sum  S[0...m-1] coins to get sum n
void count( int S[], int m, int n,int taken )
{
    cout<<m<<", "<<n<<", "<<taken<<", "<<min_sol<<endl;
    // If n is 0 then there is 1 solution (do not include any coin)
    if(taken>min_sol)
    {
        cout<<"cut down"<<endl;
        return;
    }

    if (n == 0)
    {
        if(taken<min_sol)
        {
            min_sol=taken;
            cout<<"bingo"<<endl;
        }


        return ;
    }


    // If n is less than 0 then no solution exists
    if (n < 0)
        return ;


    // If there are no coins and n is greater than 0, then no solution exist
    if (m <=0 && n >= 1)
        return ;

    // solutions (i) including last coin (ii) excluding excluding
    count( S, m, n-S[m-1], taken+1);
    count( S, m - 1, n, taken);

}

// Driver program to test above function
int main()
{
    int i,j,m,n;
    int arr[20];

    cout<<"Enter the no. of coins ";
    cin>>m;

    cout<<endl<<"enter the values of "<<m<<" coins  ";
    for(i=0;i<m;i++)
        cin>>arr[i];

    cout<<endl<<"enter the value whose change you want ";
    cin>>n;

    count(arr, m, n, 0);

    if(min_sol==INT_MAX)
        cout<<"Solution does not exist";

    else
        cout<<"The least no. of coins required for the change is "<<min_sol;

    getchar();
    return 0;
}
