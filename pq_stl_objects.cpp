// Implementation of priority queue of objects

#include <iostream>
#include <queue>
#include<cstdio>

 using namespace std;

//this is the class whose objects you want to put in the priority queue
 struct myclass
 {

   string str;
   int value;  //this is the key of priority queue
   char symbol;

 };


 struct mycompare
 {
  bool operator() (myclass *l, myclass *r) const
  {
      //implement the comparison function

      // for min heap l->value > r->value
      return l->value > r->value;

      // for max heap l->value < r->value

  }
 };


 int main()
 {

     priority_queue<myclass*,vector<myclass*>, mycompare > pq;

    myclass* element[5];

    for(int i=0;i<5;i++)
    {
        element[i]=new myclass;
        fflush(stdin);

        cout<<endl<<"enter the values<name,value,symbol> for element "<<i<<endl;
        getline(cin,element[i]->str);
        cin>>element[i]->value;
        cin>>element[i]->symbol;

        pq.push(element[i]);
    }

        myclass* temp;

     while ( !pq.empty() )
     {
         temp=pq.top();
         cout<<endl<<"name  "<<temp->str<<endl<<"value  "<<temp->value<<endl<<"symbol  "<<temp->symbol<<endl;
         pq.pop();
     }

     return 0;
 }
