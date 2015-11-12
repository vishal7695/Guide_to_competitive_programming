//The maximum and minimum possible values of int, float and double

#include <climits>
#include <iostream>
#include<cfloat>
using namespace std;

int main()
{
 
  cout<<"int min="<<INT_MIN<<endl;
  cout<<"int max="<<INT_MAX<<endl;
  cout<<"unsigned int max="<<UINT_MAX<<endl;
  cout<<"long min="<<LONG_MIN<<endl;
  cout<<"long max="<<LONG_MAX<<endl;
  cout<<"unsigned long max="<<ULONG_MAX<<endl;
  cout<<"long long min="<<LLONG_MIN<<endl;
  cout<<"long long max="<<LLONG_MAX<<endl;
  cout<<"unsigned long long max="<<ULLONG_MAX<<endl;
  cout<<"float min="<<FLT_MIN<<endl;
  cout<<"float max="<<FLT_MAX<<endl;
  cout<<"double min="<<DBL_MIN<<endl;
  cout<<"double max="<<DBL_MAX<<endl;
  
  return 0;
}
