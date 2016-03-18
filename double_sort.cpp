#include<bits/stdc++.h>
using namespace std;

struct entry 
{
  int id_number;
  string name1;
  int date;
  string name2;
};

/*
First, I want to sort alphabetically based on name1, then sort by date. 
However, the sort by date is a subset of the alphabetical sort, e.g. 
if I have two entries with the same name1, I then want to order those entries by date. 
  */

//SOLUTION
//add an overload of operator< to do comparison. 

// Add this as a member function to `entry`.
bool operator<(entry const &other) const 
{
    if (name1 < other.name1)
        return true;
    
    if (name1 > other.name1)
        return false;

    // otherwise name1 == other.name1
    // so we now fall through to use the next comparator.
    if (date < other.date)
        return true;
    
    return false;
}

//The operator< defined in the structure defines the order that will be used by default.

// sort by name, then date
std::sort(entries.begin(), entries.end());
