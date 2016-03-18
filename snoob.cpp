//snoob - next higher number with same number of set bits

#include<bits/stdc++.h>
using namespace std;

int snoob(int x)
{
    if(x==0)
      return 0;
    
    //the number to snoob is of the format X*01+0*
    //which means zero or more zeroes followed by one or more ones 
    //followed by a zero, after that we don't care whatever is there
    //eg. xxx011110000
   
    //first find the rightmost set bit number
    //xxx000010000
    int smallest=x&(~x+1);

    //now, do the increament 
    //xxx100000000
    int increase=x+smallest;

    //after that we need to move the remaining ones to the right
    //first of all get all ones
    //this will include the increased one as well

    //000111110000
    int getones=x^increase;

    //now, shift
    int shiftones=(getones>>2)/smallest;

    //now, a simple or will give the result
    int result=increase|shiftones;

    return result;
}

int main()
{
    cout<<"Enter the number whose snoobing you want to perform "<<endl;
    int x;

    cin>>x;

    while(x<100)
    {
        x=snoob(x);
        cout<<x<<endl;
    }

    return 0;
}

