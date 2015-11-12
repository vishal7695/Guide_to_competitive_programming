#include <iostream>
#include <queue>

 using namespace std;

struct compare
{
    bool operator() (const int l, const int r)
    {
        //max heap
        return l<r;

        //l>r for min heap
    }
};

 int main()
 {
     priority_queue<int,vector<int>, compare > pq;

    for(int i=0;i<10;i++)
        pq.push(i);

     while ( !pq.empty() )
     {
         cout << pq.top() << endl;
         pq.pop();
     }

     return 0;
 }
