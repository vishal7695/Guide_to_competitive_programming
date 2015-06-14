#include <iostream>
#include <queue>

 using namespace std;


 int main()
 {
     priority_queue<int,vector<int>, less<int> > pq;
     //instead of this we can simply write
     //priority_queue<int> pq because by default max heap is created

     //to create a min heap, simply change less to greater
     //priority_queue<int,vector<int>, greater<int> > pq because by default max heap is created


    for(int i=0;i<10;i++)
        pq.push(i);

     while ( !pq.empty() )
     {
         cout << pq.top() << endl;
         pq.pop();
     }

     return 0;
 }
