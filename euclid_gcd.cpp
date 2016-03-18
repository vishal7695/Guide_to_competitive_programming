//find gcd of a number using euclid's method

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int gcd(int a, int b)
{
  if(a==0)
    return b;
  
  return gcd(b%a, a); 
}

int main()
{
    int a, b;
    
    cout<<"Enter the two numbers whose gcd you want to find"<<endl;
    cin>>a>>b;
    
    cout<<"The gcd of the two entered numbers is "<<gcd(a,b);
    
    cout<<endl;
    return 0;

}
