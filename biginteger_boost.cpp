//this is library for using biginteger in cpp

//install boost library using 
//sudo apt-get install libboost-all-dev

//program to print factorial of 100 with the help of boost library 
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
namespace mp = boost::multiprecision;
using namespace std;

int main()
{
    mp::cpp_int u = 1;
    for(unsigned i = 1; i <= 100; ++i)
            u *= i;

    cout << "100! = " << u << '\n';

    return 0;
}
